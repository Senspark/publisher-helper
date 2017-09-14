#include "localizationlist.hpp"
#include "localization.hpp"

#include <QMenu>

using Self = LocalizationList;

namespace role {
constexpr int localization = 1234;
} // namespace role

Self::LocalizationList(QWidget* parent)
    : Super(parent) {

    setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    auto all = Localization::All();
    for (auto&& localization : all) {
        auto item = new QListWidgetItem(QString("%1 - %2")
                                            .arg(localization.name())
                                            .arg(localization.iso_name()),
                                        this);
        item->setFlags(item->flags() | Qt::ItemFlag::ItemIsUserCheckable);
        item->setData(role::localization, QVariant::fromValue(localization));
        item->setCheckState(Qt::CheckState::Unchecked);
    }

    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setUniformItemSizes(true);

    connect(this, &QListWidget::customContextMenuRequested,
            [this](const QPoint& position) { showContextMenu(position); });
}

void Self::showContextMenu(const QPoint& position) {
    if (selectedIndexes().isEmpty()) {
        return;
    }

    QMenu menu;

    auto checkAction = new QAction("Check", this);
    menu.addAction(checkAction);
    menu.connect(checkAction, &QAction::triggered, [this] {
        for (auto&& item : selectedItems()) {
            item->setCheckState(Qt::CheckState::Checked);
        }
    });

    auto uncheckAction = new QAction("Uncheck", this);
    menu.addAction(uncheckAction);
    menu.connect(uncheckAction, &QAction::triggered, [this] {
        for (auto&& item : selectedItems()) {
            item->setCheckState(Qt::CheckState::Unchecked);
        }
    });

    menu.exec(viewport()->mapToGlobal(position));
}

QVector<Localization> Self::selectedLocalizations() const {
    QVector<Localization> localizations;
    for (int i = 0; i < count(); ++i) {
        auto currentItem = item(i);
        if (currentItem->checkState() == Qt::CheckState::Checked) {
            auto itemLocalization =
                currentItem->data(role::localization).value<Localization>();
            localizations.append(itemLocalization);
        }
    }
    return localizations;
}

void Self::setSelectedLocalizations(
    const QVector<Localization>& localizations) {
    for (int i = 0; i < count(); ++i) {
        auto currentItem = item(i);
        auto itemLocalization =
            currentItem->data(role::localization).value<Localization>();
        currentItem->setCheckState(Qt::CheckState::Unchecked);
        if (localizations.contains(itemLocalization)) {
            currentItem->setCheckState(Qt::CheckState::Checked);
        }
    }
}
