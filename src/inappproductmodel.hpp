#ifndef INAPPPRODUCTMODEL_HPP
#define INAPPPRODUCTMODEL_HPP

#include <QAbstractItemModel>

namespace google_androidpublisher_api {
class InAppProduct;
} // namespace google_androidpublisher_api

class InAppProductModel : public QAbstractItemModel {
    Q_OBJECT

private:
    using Self = InAppProductModel;
    using Super = QAbstractItemModel;

public:
    explicit InAppProductModel(QObject* parent = nullptr);

    virtual ~InAppProductModel() override;

    void load(std::vector<google_androidpublisher_api::InAppProduct>& products);

    virtual QVariant data(const QModelIndex& index, int role) const override;

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

private:
    QVector<QString> localizations_;
    std::vector<google_androidpublisher_api::InAppProduct> products_;
};

#endif // INAPPPRODUCTMODEL_HPP