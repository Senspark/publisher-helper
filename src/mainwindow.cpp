#include <ciso646>

#include "clienthelper.hpp"
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

using Self = MainWindow;

Self::MainWindow(QWidget* parent)
    : Super(parent)
    , ui_(new Ui::MainWindow)
    , helper_(new ClientHelper()) {
    ui_->setupUi(this);

    ui_->jsonInput->setReadOnly(true);

    connect(ui_->browseButton, &QPushButton::clicked, [this] {
        auto oldPath = getJsonFilePath();
        auto path = QFileDialog::getOpenFileName(this, "Open JSON file",
                                                 oldPath, "JSON (*.json)");
        if (path.isEmpty()) {
            return;
        }

        setJsonFilePath(path);
        updateJsonFilePath(path);
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
        }

    });

    connect(ui_->refreshButton, &QPushButton::clicked, [this] {
        auto packageName = ui_->packageInput->text();
        if (packageName.isEmpty()) {
            return;
        }

        using DataTp = google_androidpublisher_api::InappproductsListResponse;
        std::unique_ptr<DataTp> data_ptr(DataTp::New());
        DataTp* data(data_ptr.get());

        auto status = helper_->iap_list(packageName.toStdString(), data);
        if (not status.ok()) {
            QMessageBox::critical(this, "Error",
                                  QString::fromStdString(status.ToString()),
                                  QMessageBox::Button::Ok);
        }

        auto iapList = data->mutable_inappproduct(); // get_inappproduct();
        for (const google_androidpublisher_api::InAppProduct& iap : iapList) {
            qDebug() << QString::fromStdString(iap.get_sku().as_string());
        }
    });

    updateJsonFilePath();
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
