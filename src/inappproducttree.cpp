#include <sstream>

#include "clienthelper.hpp"
#include "inappproductmodel.hpp"
#include "inappproducttree.hpp"

#include <QDebug>
#include <QHeaderView>

using Self = InAppProductTree;

Self::InAppProductTree(QWidget* parent)
    : Super(parent) {
    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
    setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
}

Self::~InAppProductTree() {}

void Self::setInAppProducts(
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        iapList) {
    std::vector<google_androidpublisher_api::InAppProduct> products;
    for (auto&& value : *iapList->mutable_inappproduct().MutableStorage()) {
        products.emplace_back(std::addressof(value));
    }

    auto model = new InAppProductModel();
    model->load(products);
    setModel(model);

    iapList_ = std::move(iapList);
}

googleapis::util::Status Self::patch(ClientHelper* helper) {
    googleapis::util::Status status;
    for (auto&& value : *iapList_->mutable_inappproduct().MutableStorage()) {
        google_androidpublisher_api::InAppProduct product(
            std::addressof(value));
        std::unique_ptr<google_androidpublisher_api::InAppProduct> ptr(
            google_androidpublisher_api::InAppProduct::New());
        for (int i = 0; i < 3; ++i) {
            status = helper->iap_patch(product.get_package_name().as_string(),
                                       product.get_sku().as_string(), product,
                                       ptr.get());
            if (status.ok()) {
                break;
            }
        }
        if (not status.ok()) {
            return status;
        }
        product.CopyFrom(*ptr);
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
