#ifndef INAPPPRODUCTTREE_HPP
#define INAPPPRODUCTTREE_HPP

#include <QTreeView>

#include <google/androidpublisher_api/inappproducts_list_response.h>

class ClientHelper;
class DataStateHelper;
class InAppProductModel;
class Translator;

class InAppProductTree : public QTreeView {
    Q_OBJECT

private:
    using Self = InAppProductTree;
    using Super = QTreeView;

public:
    explicit InAppProductTree(QWidget* parent = nullptr);

    virtual ~InAppProductTree() override;

    void setInAppProducts(
        std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
            products);

    googleapis::util::Status patch(ClientHelper* helper);

    bool undo();

    bool redo();

protected:
    void showContextMenu(const QPoint& position);

private:
    InAppProductModel* model_;
    std::unique_ptr<DataStateHelper> dataHelper_;
    std::unique_ptr<Translator> translator_;
    std::vector<std::unique_ptr<google_androidpublisher_api::InAppProduct>>
        products_;
};

#endif // INAPPPRODUCTTREE_HPP
