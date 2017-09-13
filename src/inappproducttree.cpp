#include <sstream>

#include "inappproductmodel.hpp"
#include "inappproducttree.hpp"

#include <QDebug>
#include <QHeaderView>

using Self = InAppProductTree;

Self::InAppProductTree(QWidget* parent)
    : Super(parent) {
    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
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

void Self::showTitle() {
    //
}

void Self::showDescription() {
    // clear();
    // buildColumns();
}

void Self::buildColumns() {}
