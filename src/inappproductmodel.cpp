#include <ciso646>
#include <sstream>

#include "inappproductmodel.hpp"
#include "inappproductmodelid.hpp"

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
        // Root level.
        return QVariant();
    }
    auto parent = index.parent();
    if (not parent.isValid()) {
        // 1st level.
        if (role == Qt::ItemDataRole::DisplayRole ||
            role == Qt::ItemDataRole::EditRole) {
            if (index.column() == 0) {
                auto&& item = getItemAt(index.row());
                return QString::fromStdString(item.get_sku().as_string());
            }
        }
        return QVariant();
    }
    // 2nd level.
    if (role == Qt::ItemDataRole::DisplayRole ||
        role == Qt::ItemDataRole::EditRole) {
        auto&& item = getItemAt(parent.row());
        if (index.column() == 0) {
            if (index.row() == 0) {
                return "Title";
            }
            Q_ASSERT(index.row() == 1);
            return "Description";
        }
        auto&& listing = item.get_listings();
        auto&& localization = localizations_.at(index.column() - 1);
        std::unique_ptr<google_androidpublisher_api::InAppProductListing> ptr(
            google_androidpublisher_api::InAppProductListing::New());
        QString text = "(null)";
        if (listing.get(localization.toStdString().c_str(), ptr.get())) {
            if (index.row() == 0) {
                text = QString::fromStdString(ptr->get_title().as_string());
            } else if (index.row() == 1) {
                text =
                    QString::fromStdString(ptr->get_description().as_string());
            } else {
                Q_ASSERT(false);
            }
        }
        if (text.isEmpty()) {
            text = "(null)";
        }
        return text;
    }
    return QVariant();
}

bool Self::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (not index.isValid()) {
        // Root level.
        return false;
    }
    auto parent = index.parent();
    if (not parent.isValid()) {
        // 1st level.
        return false;
    }
    if (role == Qt::ItemDataRole::EditRole) {
        auto oldValue = data(index, role);
        if (oldValue == value) {
            return false;
        }
        Q_ASSERT(not value.isNull());
        if (value == "(null)") {
            // (null) is equal to an empty string.
            return setData(index, "", role);
        }
        auto&& item = getItemAt(parent.row());
        Q_ASSERT(index.column() != 0);
        auto&& listing = item.mutable_listings();
        auto&& localization = localizations_.at(index.column() - 1);
        std::unique_ptr<google_androidpublisher_api::InAppProductListing> ptr(
            google_androidpublisher_api::InAppProductListing::New());
        if (not listing.get(localization.toStdString().c_str(), ptr.get())) {
            ptr->clear_title();
            ptr->clear_description();
        }
        if (index.row() == 0) {
            if (value.toString().isEmpty()) {
                ptr->clear_title();
            } else {
                ptr->set_title(value.toString().toStdString());
            }
        } else if (index.row() == 1) {
            if (value.toString().isEmpty()) {
                ptr->clear_description();
            } else {
                ptr->set_description(value.toString().toStdString());
            }
        } else {
            Q_ASSERT(false);
        }
        if (not ptr->has_title() && not ptr->has_description()) {
            ptr->CopyFrom(*std::unique_ptr<
                          google_androidpublisher_api::InAppProductListing>(
                google_androidpublisher_api::InAppProductListing::New()));
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
    if (not parent.isValid()) {
        // Root level.
        if (row > static_cast<int>(items_.size())) {
            // Out of range.
            return QModelIndex();
        }
        return createIndex(
            row, column,
            InAppProductModelId().setRow0(static_cast<quintptr>(row)).getId());
    }
    // Not root level.
    InAppProductModelId modelId(parent.internalId());
    Q_ASSERT(modelId.hasRow0());
    if (not modelId.hasRow1()) {
        // 1st level.
        if (row > 2) {
            // Title + description.
            return QModelIndex();
        }
        return createIndex(row, column,
                           modelId.setRow1(static_cast<quintptr>(row)).getId());
    }
    // 2nd level.
    return QModelIndex();
}

QModelIndex Self::parent(const QModelIndex& index) const {
    if (not index.isValid()) {
        // Root level.
        return QModelIndex();
    }
    InAppProductModelId modelId(index.internalId());
    Q_ASSERT(modelId.hasRow0());
    if (not modelId.hasRow1()) {
        // 1st level.
        return QModelIndex();
    }
    auto row0 = modelId.getRow0();
    return createIndex(row0, 0, modelId.clearRow1().getId());
}

int Self::rowCount(const QModelIndex& parent) const {
    if (not parent.isValid()) {
        // Root level.
        return static_cast<int>(items_.size());
    }
    InAppProductModelId modelId(parent.internalId());
    Q_ASSERT(modelId.hasRow0());
    if (not modelId.hasRow1()) {
        // 1st level.
        return 2;
    }
    // 2nd level.
    return 0;
}

int Self::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    // if (not parent.isValid()) {
    // Root level.
    // return 0;
    // }
    // ModelId modelId(parent.internalId());
    // Q_ASSERT(modelId.hasRow0());
    // if (not modelId.hasRow1()) {
    // 1st level.
    // return 0;
    // }
    // 2nd level.
    return localizations_.size() + 1;
}

Qt::ItemFlags Self::flags(const QModelIndex& index) const {
    QFlags<Qt::ItemFlag> flags = Qt::ItemFlag::NoItemFlags;
    if (not index.isValid()) {
        return flags;
    }
    flags |= Qt::ItemFlag::ItemIsEnabled;
    auto parent = index.parent();
    if (not parent.isValid()) {
        // 1st level.
        if (index.column() != 0) {
            return flags;
        }
        flags |= Qt::ItemFlag::ItemIsSelectable;
        return flags;
    }
    // 2nd level.
    flags |= Qt::ItemFlag::ItemIsSelectable;
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
