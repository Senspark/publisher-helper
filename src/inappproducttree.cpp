#include <ciso646>
#include <sstream>

#include "clienthelper.hpp"
#include "datastatehelper.hpp"
#include "inappproductmodel.hpp"
#include "inappproducttree.hpp"

#include <QAction>
#include <QDebug>
#include <QHeaderView>
#include <QMenu>

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

    menu.exec(viewport()->mapToGlobal(position));
}

void Self::setInAppProducts(
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        iapList) {
    std::vector<google_androidpublisher_api::InAppProduct> products;
    for (auto&& value : *iapList->mutable_inappproduct().MutableStorage()) {
        products.emplace_back(std::addressof(value));
    }

    dataHelper_ = std::make_unique<DataStateHelper>();

    model_ = new InAppProductModel();
    model_->load(products);
    model_->setDataStateHelper(dataHelper_.get());

    setModel(model_);

    header()->setSectionResizeMode(0,
                                   QHeaderView::ResizeMode::ResizeToContents);

    iapList_ = std::move(iapList);
}

googleapis::util::Status Self::patch(ClientHelper* helper) {
    auto status = googleapis::util::Status();
    int productCount = iapList_->mutable_inappproduct().size();
    for (int i = 0; i < productCount; ++i) {
        auto&& oldProduct = iapList_->mutable_inappproduct().mutable_get(i);
        auto&& currentProduct = model_->getItemAt(i);
        if (not(oldProduct == currentProduct)) {
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
            oldProduct.CopyFrom(*ptr);
        }
    }
    return status;
}

void Self::showTitle() {
    //
}

void Self::showDescription() {
    // clear();
    // buildColumns();
}

void Self::buildColumns() {}

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
