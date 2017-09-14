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
    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
    setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
    setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);

    connect(this, &Self::customContextMenuRequested,
            [this](const QPoint& position) { showContextMenu(position); });
}

Self::~InAppProductTree() {}

void Self::showContextMenu(const QPoint& position) {
    QMenu menu;

    auto deleteAction = new QAction("Delete", this);
    deleteAction->setEnabled(not selectedIndexes().isEmpty());
    menu.addAction(deleteAction);
    menu.connect(deleteAction, &QAction::triggered, [this] {
        dataHelper_->pushGroup();
        for (auto&& index : selectedIndexes()) {
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

    model_->addLocalization("af");
    model_->addLocalization("am");
    model_->addLocalization("ar");
    model_->addLocalization("hy-AM");
    model_->addLocalization("az-AZ");
    model_->addLocalization("bn-BD");
    model_->addLocalization("eu-ES");
    model_->addLocalization("be");
    model_->addLocalization("bg");
    model_->addLocalization("my-MM");
    model_->addLocalization("ca");
    model_->addLocalization("zh-HK");
    model_->addLocalization("zh-CN");
    model_->addLocalization("zh-TW");
    model_->addLocalization("hr");
    model_->addLocalization("cs-CZ");
    model_->addLocalization("da-DK");
    model_->addLocalization("nl-NL");
    model_->addLocalization("en-AU");
    model_->addLocalization("en-IN");
    model_->addLocalization("en-SG");
    model_->addLocalization("en-ZA");
    model_->addLocalization("en-CA");
    model_->addLocalization("en-GB");
    model_->addLocalization("en-US");
    model_->addLocalization("et");
    model_->addLocalization("fil");
    model_->addLocalization("fi-FI");
    model_->addLocalization("fr-FR");
    model_->addLocalization("fr-CA");
    model_->addLocalization("gl-ES");
    model_->addLocalization("ka-GE");
    model_->addLocalization("de-DE");
    model_->addLocalization("el-GR");
    model_->addLocalization("iw-IL");
    model_->addLocalization("hi-IN");
    model_->addLocalization("hu-HU");
    model_->addLocalization("is-IS");
    model_->addLocalization("id");
    model_->addLocalization("it-IT");
    model_->addLocalization("ja-JP");
    model_->addLocalization("kn-IN");
    model_->addLocalization("km-KH");
    model_->addLocalization("ko-KR");
    model_->addLocalization("ky-KG");
    model_->addLocalization("lo-LA");
    model_->addLocalization("lv");
    model_->addLocalization("lt");
    model_->addLocalization("mk-MK");
    model_->addLocalization("ms");
    model_->addLocalization("ml-IN");
    model_->addLocalization("mr-IN");
    model_->addLocalization("mn-MN");
    model_->addLocalization("ne-NP");
    model_->addLocalization("no-NO");
    model_->addLocalization("fa");
    model_->addLocalization("pl-PL");
    model_->addLocalization("pt-BR");
    model_->addLocalization("pt-PT");
    model_->addLocalization("ro");
    model_->addLocalization("rm");
    model_->addLocalization("ru-RU");
    model_->addLocalization("sr");
    model_->addLocalization("si-LK");
    model_->addLocalization("sk");
    model_->addLocalization("sl");
    model_->addLocalization("es-419");
    model_->addLocalization("es-ES");
    model_->addLocalization("es-US");
    model_->addLocalization("sw");
    model_->addLocalization("sv-SE");
    model_->addLocalization("ta-IN");
    model_->addLocalization("te-IN");
    model_->addLocalization("th");
    model_->addLocalization("tr-TR");
    model_->addLocalization("uk");
    model_->addLocalization("vi");
    model_->addLocalization("zu");

    setModel(model_);

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
