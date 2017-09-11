#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <google/androidpublisher_api/android_publisher_service.h>
#include <googleapis/client/auth/oauth2_authorization.h>

namespace Ui {
class MainWindow;
} // namespace Ui

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    using Self = MainWindow;
    using Super = QMainWindow;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    QString getJsonFilePath();
    void setJsonFilePath(const QString& path);
    void updateJsonFilePath();
    void updateJsonFilePath(QString& path);

    std::unique_ptr<googleapis::client::HttpTransportLayerConfig> config_;
    std::unique_ptr<googleapis::client::OAuth2AuthorizationFlow> flow_;
    std::unique_ptr<google_androidpublisher_api::AndroidPublisherService>
        service_;

private:
    Ui::MainWindow* ui_;
};

#endif // MAINWINDOW_HPP
