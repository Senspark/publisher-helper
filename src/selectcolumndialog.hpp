#ifndef SELECTCOLUMNDIALOG_HPP
#define SELECTCOLUMNDIALOG_HPP

#include <QDialog>

namespace Ui {
class SelectColumnDialog;
} // namespace Ui

class Localization;

class SelectColumnDialog : public QDialog {
    Q_OBJECT

private:
    using Self = SelectColumnDialog;
    using Super = QDialog;

public:
    explicit SelectColumnDialog(QWidget* parent = nullptr);

    virtual ~SelectColumnDialog() override;

    QVector<Localization> selectedLocalizations() const;

    void setSelectedLocalizations(const QVector<Localization>& localizations);

private:
    Ui::SelectColumnDialog* ui_;
};

#endif // SELECTCOLUMNDIALOG_HPP
