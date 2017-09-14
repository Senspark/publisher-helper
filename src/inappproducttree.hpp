#ifndef INAPPPRODUCTTREE_HPP
#define INAPPPRODUCTTREE_HPP

#include <QTreeView>

#include <google/androidpublisher_api/inappproducts_list_response.h>

class ClientHelper;
class DataStateHelper;
class InAppProductModel;

class InAppProductTree : public QTreeView {
private:
    using Self = InAppProductTree;
    using Super = QTreeView;

public:
    explicit InAppProductTree(QWidget* parent = nullptr);

    virtual ~InAppProductTree() override;

    void setInAppProducts(
        std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
            iapList);

    googleapis::util::Status patch(ClientHelper* helper);

    void showTitle();

    void showDescription();

    bool undo();

    bool redo();

protected:
    void buildColumns();

    void showContextMenu(const QPoint& position);

private:
    InAppProductModel* model_;
    std::unique_ptr<DataStateHelper> dataHelper_;
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        iapList_;
};

#endif // INAPPPRODUCTTREE_HPP
