#include <ciso646>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>

#include <googleapis/client/transport/curl_http_transport.h>
#include <googleapis/client/transport/http_authorization.h>

using Self = MainWindow;

Self::MainWindow(QWidget* parent)
    : Super(parent)
    , ui_(new Ui::MainWindow) {
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
        QFile file(jsonFilePath);
        if (not file.open(QIODevice::ReadOnly)) {
            return;
        }
        auto jsonContent = file.readAll();

        config_.reset(new googleapis::client::HttpTransportLayerConfig());
        config_->ResetDefaultTransportFactory(
            new googleapis::client::CurlHttpTransportFactory(config_.get()));

        googleapis::util::Status status;
        flow_.reset(googleapis::client::OAuth2AuthorizationFlow::
                        MakeFlowFromClientSecretsJson(
                            jsonContent.toStdString(),
                            config_->NewDefaultTransportOrDie(),
                            std::addressof(status)));
        if (not status.ok()) {
            QMessageBox::critical(
                this, "Error", QString::fromStdString(status.error_message()),
                QMessageBox::Button::Ok);
            return;
        }
    });

    updateJsonFilePath();
}

Self::~MainWindow() {
    delete ui_;
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
