#ifndef LOCALIZATIONLIST_HPP
#define LOCALIZATIONLIST_HPP

#include <QListWidget>

class Localization;

class LocalizationList : public QListWidget {
    Q_OBJECT

private:
    using Self = LocalizationList;
    using Super = QListWidget;

public:
    explicit LocalizationList(QWidget* parent = nullptr);

    QVector<Localization> selectedLocalizations() const;

    void setSelectedLocalizations(const QVector<Localization>& localizations);

protected:
    void showContextMenu(const QPoint& position);
};

#endif // LOCALIZATIONLIST_HPP
