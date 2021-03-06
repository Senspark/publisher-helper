#include <ciso646>
#include <sstream>

#include "clienthelper.hpp"
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QMessageBox>
#include <QSettings>

using Self = MainWindow;

Self::MainWindow(QWidget* parent)
    : Super(parent)
    , ui_(new Ui::MainWindow)
    , helper_(new ClientHelper()) {
    ui_->setupUi(this);
    setWindowTitle(QString("Publisher Helper - build %1")
                       .arg(QDateTime::currentDateTime().toString(
                           "MMM dd, yyyy HH:mm:ss t")));

    ui_->jsonInput->setReadOnly(true);
    ui_->authorizationLabel->setText("AUTHORIZATION: NO");

    connect(ui_->browseButton, &QPushButton::clicked, [this] {
        auto oldPath = getJsonFilePath();
        auto path = QFileDialog::getOpenFileName(this, "Open JSON file",
                                                 oldPath, "JSON (*.json)");
        if (path.isEmpty()) {
            return;
        }
        if (oldPath == path) {
            return;
        }

        setJsonFilePath(path);
        updateJsonFilePath(path);
        helper_->reset();
        ui_->authorizationLabel->setText("AUTHORIZATION: NO");
    });

    connect(ui_->authorizeButton, &QPushButton::clicked, [this] {
        auto jsonFilePath = getJsonFilePath();
        if (jsonFilePath.isEmpty()) {
            return;
        }
        auto status = helper_->startUp(jsonFilePath.toStdString());
        if (not status.ok()) {
            QMessageBox::critical(this, "Error",
                                  QString::fromStdString(status.ToString()),
                                  QMessageBox::Button::Ok);
            return;
        }

        ui_->refreshButton->setEnabled(true);
        ui_->patchButton->setEnabled(true);
        ui_->authorizationLabel->setText("AUTHORIZATION: YES");
    });

    connect(ui_->refreshButton, &QPushButton::clicked, [this] {
        auto packageName = ui_->packageInput->text();
        if (packageName.isEmpty()) {
            // return;
        }

        auto data = std::unique_ptr<
            google_androidpublisher_api::InappproductsListResponse>(
            google_androidpublisher_api::InappproductsListResponse::New());
        auto status = helper_->iap_list(packageName.toStdString(), data.get());
        if (not status.ok()) {
            QMessageBox::critical(this, "Error",
                                  QString::fromStdString(status.ToString()),
                                  QMessageBox::Button::Ok);
            return;
        }

        ui_->inAppProductTree->setInAppProducts(std::move(data));
    });

    connect(ui_->patchButton, &QPushButton::clicked, [this] {
        auto status = ui_->inAppProductTree->patch(helper_);
        if (not status.ok()) {
            QMessageBox::critical(this, "Error",
                                  QString::fromStdString(status.ToString()),
                                  QMessageBox::Button::Ok);
            return;
        }
        QMessageBox::information(this, "Info",
                                 "Operation has completed successfully!",
                                 QMessageBox::Button::Ok);
    });

    connect(ui_->undoAction, &QAction::triggered,
            [this] { ui_->inAppProductTree->undo(); });

    connect(ui_->redoAction, &QAction::triggered,
            [this] { ui_->inAppProductTree->redo(); });

    updateJsonFilePath();

    ui_->refreshButton->setEnabled(false);
    ui_->patchButton->setEnabled(false);
}

Self::~MainWindow() {
    delete ui_;
    delete helper_;
}

QString Self::getJsonFilePath() {
    QSettings settings;
    auto path = settings.value("json_file_path", "").toString();
    return path;
}

void Self::setJsonFilePath(const QString& path) {
    QSettings settings;
    settings.setValue("json_file_path", path);
}

void Self::updateJsonFilePath() {
    auto path = getJsonFilePath();
    updateJsonFilePath(path);
}

void Self::updateJsonFilePath(QString& path) {
    ui_->jsonInput->setText(path);
}
