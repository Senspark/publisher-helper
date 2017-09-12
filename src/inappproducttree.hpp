#ifndef INAPPPRODUCTTREE_HPP
#define INAPPPRODUCTTREE_HPP

#include <QTreeWidget>

#include <google/androidpublisher_api/inappproducts_list_response.h>

class InAppProductTree : public QTreeWidget {
private:
    using Self = InAppProductTree;
    using Super = QTreeWidget;

public:
    explicit InAppProductTree(QWidget* parent = nullptr);

    virtual ~InAppProductTree() override;

    void setInAppProducts(
        google_androidpublisher_api::InappproductsListResponse& iapList);

    void showTitle();

    void showDescription();

protected:
    void buildColumns();

private:
    std::unique_ptr<google_androidpublisher_api::InappproductsListResponse>
        iapList_;
};

#endif // INAPPPRODUCTTREE_HPP
