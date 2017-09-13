#include <ciso646>
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

    model_ = new InAppProductModel();
    model_->load(products);
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
