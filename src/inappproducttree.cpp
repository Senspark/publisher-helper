#include "inappproducttree.hpp"

#include <QHeaderView>

using Self = InAppProductTree;

Self::InAppProductTree(QWidget* parent)
    : Super(parent) {}

Self::~InAppProductTree() {}

void Self::setInAppProducts(
    google_androidpublisher_api::InappproductsListResponse& iapList) {
    iapList_ = std::make_unique<
        google_androidpublisher_api::InappproductsListResponse>(
        iapList.MutableStorage());
}

void Self::showTitle() {
    clear();
    buildColumns();
    for (auto&& iap : iapList_->get_inappproduct()) {
        auto item = new QTreeWidgetItem(this);
        item->setText(0, QString::fromStdString(iap.get_sku().as_string()));

        auto&& listings = iap.get_listings();
        for (int i = 1; i < columnCount(); ++i) {
            auto headerText = headerItem()->text(i);
            if (listings.has(headerText.toStdString().c_str())) {
                std::unique_ptr<
                    google_androidpublisher_api::InAppProductListing>
                    listing(google_androidpublisher_api::InAppProductListing::
                                New());
                listings.get(headerText.toStdString().c_str(), listing.get());
                item->setText(i, QString::fromStdString(
                                     listing->get_title().as_string()));
            }
        }
    }
    //
}

void Self::showDescription() {
    clear();
    buildColumns();
}

void Self::buildColumns() {
    QSet<QString> localizations;
    for (auto&& iap : iapList_->get_inappproduct()) {
        auto&& listings = iap.get_listings();
        for (auto i = listings.begin(); i != listings.end(); ++i) {
            localizations.insert(QString::fromStdString(i.key()));
        }
    }
    setColumnCount(localizations.size() + 1);
    headerItem()->setText(0, "SKU");

    int i = 1;
    for (auto&& text : localizations) {
        headerItem()->setText(i, text);
        ++i;
    }
}
