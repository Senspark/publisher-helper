#include <ciso646>
#include <sstream>

#include "inappproductmodel.hpp"

#include <QDebug>
#include <QSet>

#include <google/androidpublisher_api/in_app_product.h>

using Self = InAppProductModel;

Self::InAppProductModel(QObject* parent)
    : Super(parent) {}

Self::~InAppProductModel() {}
void Self::load(
    std::vector<google_androidpublisher_api::InAppProduct>& products) {
    for (auto&& product : products) {
        std::unique_ptr<google_androidpublisher_api::InAppProduct> item(
            google_androidpublisher_api::InAppProduct::New());
        item->CopyFrom(product);
        items_.push_back(std::move(item));
    }

    QSet<QString> localizations;
    for (auto&& item : items_) {

        // std::ostringstream os;
        // product.StoreToJsonStream(&os);
        // qDebug() << QString::fromStdString(os.str());

        auto&& listings = item->get_listings();
        for (auto i = listings.begin(); i != listings.end(); ++i) {
            localizations.insert(QString::fromStdString(i.key()));
        }
    }
    localizations_ = localizations.toList().toVector();
}

QVariant Self::data(const QModelIndex& index, int role) const {
    if (not index.isValid()) {
        return QVariant();
    }
    if (role == Qt::ItemDataRole::DisplayRole ||
        role == Qt::ItemDataRole::EditRole) {
        auto row = index.row();
        auto&& item = getItemAt(row);
        auto col = index.column();
        if (col == 0) {
            return QString::fromStdString(item.get_sku().as_string());
        }
        auto&& listing = item.get_listings();
        auto&& localization = localizations_.at(col - 1);
        std::unique_ptr<google_androidpublisher_api::InAppProductListing> ptr(
            google_androidpublisher_api::InAppProductListing::New());
        if (listing.get(localization.toStdString().c_str(), ptr.get())) {
            return QString::fromStdString(ptr->get_title().as_string());
        }
        return "(null)";
    }
    return QVariant();
}

bool Self::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (not index.isValid()) {
        return false;
    }
    if (role == Qt::ItemDataRole::EditRole) {
        auto oldValue = data(index, role);
        if (oldValue == value) {
            return false;
        }
        if (value.isNull()) {
            Q_ASSERT(false);
        }
        auto row = index.row();
        auto&& item = getItemAt(row);
        auto col = index.column();
        Q_ASSERT(col != 0);
        auto&& listing = item.mutable_listings();
        auto&& localization = localizations_.at(col - 1);
        std::unique_ptr<google_androidpublisher_api::InAppProductListing> ptr(
            google_androidpublisher_api::InAppProductListing::New());
        if (listing.get(localization.toStdString().c_str(), ptr.get())) {
            // Exist.
            if (value.toString().isEmpty()) {
                ptr->clear_title();
            } else {
                ptr->set_title(value.toString().toStdString());
            }
        } else {
            // Doesn't exist.
            ptr->clear_title();
            ptr->clear_description();
            if (value.toString().isEmpty()) {
                //
            } else {
                ptr->set_title(value.toString().toStdString());
            }
        }
        listing.put(localization.toStdString().c_str(), *ptr);
        dataChanged(index, index);
        return true;
    }
    return false;
}

QVariant Self::headerData(int section, Qt::Orientation orientation,
                          int role) const {
    if (role == Qt::DisplayRole) {
        if (section == 0) {
            return "SKU";
        }
        return localizations_.at(section - 1);
    }
    Q_UNUSED(orientation);
    return QVariant();
}

QModelIndex Self::index(int row, int column, const QModelIndex& parent) const {
    if (not hasIndex(row, column, parent)) {
        return QModelIndex();
    }
    if (row > static_cast<int>(items_.size())) {
        return QModelIndex();
    }
    return createIndex(row, column, nullptr);
}

QModelIndex Self::parent(const QModelIndex& index) const {
    if (not index.isValid()) {
        return QModelIndex();
    }
    return QModelIndex();
}

int Self::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return static_cast<int>(items_.size());
}

int Self::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return localizations_.size() + 1;
}

Qt::ItemFlags Self::flags(const QModelIndex& index) const {
    if (not index.isValid()) {
        return Qt::ItemFlag::NoItemFlags;
    }
    auto flags = Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled;
    if (index.column() != 0) {
        flags |= Qt::ItemFlag::ItemIsEditable;
    }
    return flags;
}

google_androidpublisher_api::InAppProduct& Self::getItemAt(int i) {
    return *items_.at(static_cast<std::size_t>(i));
}

const google_androidpublisher_api::InAppProduct& Self::getItemAt(int i) const {
    return *items_.at(static_cast<std::size_t>(i));
}
