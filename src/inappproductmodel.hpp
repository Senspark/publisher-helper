#ifndef INAPPPRODUCTMODEL_HPP
#define INAPPPRODUCTMODEL_HPP

#include <QAbstractItemModel>

namespace google_androidpublisher_api {
class InAppProduct;
} // namespace google_androidpublisher_api

class DataStateHelper;
class Localization;

class InAppProductModel : public QAbstractItemModel {
    Q_OBJECT

private:
    using Self = InAppProductModel;
    using Super = QAbstractItemModel;

public:
    explicit InAppProductModel(QObject* parent = nullptr);

    virtual ~InAppProductModel() override;

    void setDataStateHelper(DataStateHelper* helper);

    void load(std::vector<google_androidpublisher_api::InAppProduct>& products);

    virtual QVariant data(const QModelIndex& index, int role) const override;

    virtual bool setData(const QModelIndex& index, const QVariant& value,
                         int role) override;

    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role) const override;

    virtual QModelIndex
    index(int row, int column,
          const QModelIndex& parent = QModelIndex()) const override;

    virtual QModelIndex parent(const QModelIndex& index) const override;

    virtual int
    rowCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual int
    columnCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;

    google_androidpublisher_api::InAppProduct& getItemAt(int i);

    const google_androidpublisher_api::InAppProduct& getItemAt(int i) const;

    const QVector<Localization>& getLocalizations() const;

    void setLocalizations(const QVector<Localization>& localizations);

    bool addLocalization(const Localization& localization);

    QString getTitleText(const QString& sku,
                         const Localization& localization) const;

    QString getDescriptionText(const QString& sku,
                               const Localization& localization) const;

private:
    DataStateHelper* dataHelper_;
    QVector<Localization> localizations_;
    std::vector<std::unique_ptr<google_androidpublisher_api::InAppProduct>>
        items_;
};

#endif // INAPPPRODUCTMODEL_HPP
