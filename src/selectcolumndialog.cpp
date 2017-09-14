#include "selectcolumndialog.hpp"
#include "localization.hpp"
#include "localizationlist.hpp"
#include "ui_selectcolumndialog.h"

using Self = SelectColumnDialog;

Self::SelectColumnDialog(QWidget* parent)
    : Super(parent)
    , ui_(new Ui::SelectColumnDialog) {
    ui_->setupUi(this);
}

Self::~SelectColumnDialog() {
    delete ui_;
}

QVector<Localization> Self::selectedLocalizations() const {
    return ui_->localizationList->selectedLocalizations();
}

void Self::setSelectedLocalizations(
    const QVector<Localization>& localizations) {
    ui_->localizationList->setSelectedLocalizations(localizations);
}
