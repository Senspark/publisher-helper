#include <ciso646>
#include <set>
#include <sstream>

#include "clienthelper.hpp"
#include "datastatehelper.hpp"
#include "inappproductmodel.hpp"
#include "inappproducttree.hpp"
#include "localization.hpp"
#include "selectcolumndialog.hpp"
#include "stringutils.hpp"
#include "translator.hpp"

#include <QAction>
#include <QDebug>
#include <QHeaderView>
#include <QMenu>
#include <QProgressDialog>

using Self = InAppProductTree;

Self::InAppProductTree(QWidget* parent)
    : Super(parent) {
    header()->setSectionResizeMode(QHeaderView::ResizeMode::Interactive);
    setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
    setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setUniformRowHeights(true);

    connect(this, &Self::customContextMenuRequested,
            [this](const QPoint& position) { showContextMenu(position); });
}

Self::~InAppProductTree() {}

void Self::showContextMenu(const QPoint& position) {
    if (selectedIndexes().isEmpty()) {
        return;
    }

    QMenu menu;

    auto expandAction = new QAction("Expand rows", this);
    menu.addAction(expandAction);
    menu.connect(expandAction, &QAction::triggered, [this] {
        for (auto&& index : selectedIndexes()) {
            if (index.column() == 0) {
                expand(index);
            }
        }
    });

    auto collapseAction = new QAction("Collapse rows", this);
    menu.addAction(collapseAction);
    menu.connect(collapseAction, &QAction::triggered, [this] {
        for (auto&& index : selectedIndexes()) {
            if (index.column() == 0) {
                collapse(index);
            }
        }
    });

    auto hideColumnAction = new QAction("Hide columns");
    menu.addAction(hideColumnAction);
    menu.connect(hideColumnAction, &QAction::triggered, [this] {
        std::set<int> toHideColumns;
        for (auto&& index : selectedIndexes()) {
            if (index.column() != 0) {
                toHideColumns.insert(index.column());
            }
        }
        auto localizations = model_->getLocalizations();
        for (auto iter = toHideColumns.rbegin(); iter != toHideColumns.rend();
             ++iter) {
            int column = *iter;
            Q_ASSERT(1 <= column && column <= localizations.size());
            localizations.erase(localizations.begin() + column - 1);
        }
        model_->setLocalizations(localizations);
    });

    auto showColumnAction = new QAction("Select columns...");
    menu.addAction(showColumnAction);
    menu.connect(showColumnAction, &QAction::triggered, [this] {
        SelectColumnDialog dialog(this);
        dialog.setSelectedLocalizations(model_->getLocalizations());
        connect(&dialog, &SelectColumnDialog::accepted, [this, &dialog] {
            auto selectedLocalizations = dialog.selectedLocalizations();
            model_->setLocalizations(selectedLocalizations);
        });
        dialog.exec();
    });

    auto resizeColumnAction = new QAction("Resize columns to contents");
    menu.addAction(resizeColumnAction);
    menu.connect(resizeColumnAction, &QAction::triggered, [this] {
        for (auto&& index : selectedIndexes()) {
            resizeColumnToContents(index.column());
        }
    });

    QModelIndexList removableIndexes;
    for (auto&& index : selectedIndexes()) {
        if (model_->flags(index).testFlag(Qt::ItemFlag::ItemIsEditable)) {
            removableIndexes << index;
        }
    }

    auto deleteAction = new QAction("Delete cells", this);
    deleteAction->setEnabled(not removableIndexes.isEmpty());
    menu.addAction(deleteAction);
    menu.connect(deleteAction, &QAction::triggered, [this, removableIndexes] {
        dataHelper_->pushGroup();
        for (auto&& index : removableIndexes) {
            model_->setData(index, "", Qt::ItemDataRole::EditRole);
        }
        dataHelper_->popGroup();
    });

    auto translateAction = new QAction("Translate from en-US", this);
    translateAction->setEnabled(not removableIndexes.isEmpty());
    menu.addAction(translateAction);
    menu.connect(
        translateAction, &QAction::triggered, [this, removableIndexes] {
            int count = removableIndexes.size();
            qDebug() << "count = " << count;
            auto processed = std::make_shared<int>(0);  // to count.
            auto percentage = std::make_shared<int>(0); // to 100.

            QProgressDialog dialog(this);
            dialog.setMinimumDuration(0);
            dialog.setMaximum(count);
            dialog.setValue(0);
            dialog.setCancelButton(nullptr);
            dataHelper_->pushGroup();
            for (auto&& index : removableIndexes) {
                auto parent = index.parent();
                Q_ASSERT(parent.isValid());
                auto&& item = model_->getItemAt(parent.row());
                auto sku = QString::fromStdString(item.get_sku().as_string());
                auto&& localization =
                    model_->getLocalizations().at(index.column() - 1);
                auto englishText =
                    (index.row() == 0
                         ? model_->getTitleText(sku, Localization::English_US)
                         : model_->getDescriptionText(
                               sku, Localization::English_US));
                translator_->translate(
                    Localization::English_US, localization, englishText,
                    [this, &dialog, index, count, processed,
                     percentage](const QString& content) {
                        model_->setData(index, content,
                                        Qt::ItemDataRole::EditRole);
                        ++(*processed);
                        if (*processed == count) {
                            dataHelper_->popGroup();
                        }
                        if (*processed >= *percentage * count / 100) {
                            constexpr int step = 10;
                            *percentage += step;
                            dialog.setValue(*processed);
                        }
                    });
            }
            dialog.exec();
        });

    auto convertToMenu = menu.addMenu("Convert to...");
    auto convertToLowerCaseAction = new QAction("lower case");
    convertToMenu->addAction(convertToLowerCaseAction);
    convertToMenu->connect(
        convertToLowerCaseAction, &QAction::triggered,
        [this, removableIndexes] {
            dataHelper_->pushGroup();
            for (auto&& index : removableIndexes) {
                auto value = model_->data(index, Qt::ItemDataRole::DisplayRole);
                value = StringUtils::toLowerCase(value.toString());
                model_->setData(index, value, Qt::ItemDataRole::EditRole);
            }
            dataHelper_->popGroup();
        });

    auto convertToCapitalizedCaseAction = new QAction("Capitalized Case");
    convertToMenu->addAction(convertToCapitalizedCaseAction);
    convertToMenu->connect(
        convertToCapitalizedCaseAction, &QAction::triggered,
        [this, removableIndexes] {
            dataHelper_->pushGroup();
            for (auto&& index : removableIndexes) {
                auto value = model_->data(index, Qt::ItemDataRole::DisplayRole);
                value = StringUtils::toCapitalizedCase(value.toString());
                model_->setData(index, value, Qt::ItemDataRole::EditRole);
            }
            dataHelper_->popGroup();
        });

    auto convertToTitleCaseAction = new QAction("Title Case");
    convertToMenu->addAction(convertToTitleCaseAction);
    convertToMenu->connect(
        convertToTitleCaseAction, &QAction::triggered,
        [this, removableIndexes] {
            dataHelper_->pushGroup();
            for (auto&& index : removableIndexes) {
                auto value = model_->data(index, Qt::ItemDataRole::DisplayRole);
                value = StringUtils::toTitleCase(value.toString());
                model_->setData(index, value, Qt::ItemDataRole::EditRole);
            }
            dataHelper_->popGroup();
        });

    menu.exec(viewport()->mapToGlobal(position));
}

void Self::setInAppProducts(
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        products) {
    products_.clear();
    for (auto&& value : products->mutable_inappproduct()) {
        std::unique_ptr<google_androidpublisher_api::InAppProduct> item(
            google_androidpublisher_api::InAppProduct::New());
        item->CopyFrom(value);
        products_.push_back(std::move(item));
    }

    std::sort(
        products_.begin(), products_.end(),
        [](const std::unique_ptr<google_androidpublisher_api::InAppProduct>&
               lhs,
           const std::unique_ptr<google_androidpublisher_api::InAppProduct>&
               rhs) { return lhs->get_sku() < rhs->get_sku(); });

    dataHelper_ = std::make_unique<DataStateHelper>();
    translator_ = std::make_unique<Translator>();

    model_ = new InAppProductModel();
    model_->load(products_);
    model_->setDataStateHelper(dataHelper_.get());

    setModel(model_);

    header()->setSectionResizeMode(0,
                                   QHeaderView::ResizeMode::ResizeToContents);
}

googleapis::util::Status Self::patch(ClientHelper* helper) {
    auto status = googleapis::util::Status();
    int productCount = products_.size();
    for (int i = 0; i < productCount; ++i) {
        auto&& oldProduct = products_.at(i);
        auto&& currentProduct = model_->getItemAt(i);
        if (not(*oldProduct == currentProduct)) {
            std::unique_ptr<google_androidpublisher_api::InAppProduct> ptr(
                google_androidpublisher_api::InAppProduct::New());
            for (int i = 0; i < 3; ++i) {
                status = helper->iap_patch(
                    currentProduct.get_package_name().as_string(),
                    currentProduct.get_sku().as_string(), currentProduct,
                    ptr.get());
                if (status.ok()) {
                    break;
                }
            }
            if (not status.ok()) {
                return status;
            }
            currentProduct.CopyFrom(*ptr);
            oldProduct->CopyFrom(*ptr);
        }
    }
    return status;
}

bool Self::undo() {
    if (not dataHelper_) {
        return false;
    }
    if (not dataHelper_->canUndo()) {
        return false;
    }
    auto states = dataHelper_->undo();
    dataHelper_->setEnabled(false);
    for (auto&& state : states) {
        model_->setData(state.index, state.oldValue, state.role);
    }
    dataHelper_->setEnabled(true);
    return true;
}

bool Self::redo() {
    if (not dataHelper_) {
        return false;
    }
    if (not dataHelper_->canRedo()) {
        return false;
    }
    auto states = dataHelper_->redo();
    dataHelper_->setEnabled(false);
    for (auto&& state : states) {
        model_->setData(state.index, state.newValue, state.role);
    }
    dataHelper_->setEnabled(true);
    return true;
}
