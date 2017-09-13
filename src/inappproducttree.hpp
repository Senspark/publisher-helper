#ifndef INAPPPRODUCTTREE_HPP
#define INAPPPRODUCTTREE_HPP

#include <QTreeView>

#include <google/androidpublisher_api/inappproducts_list_response.h>

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

    void showTitle();

    void showDescription();

protected:
    void buildColumns();

private:
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        iapList_;
};

#endif // INAPPPRODUCTTREE_HPP
