#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
} // namespace Ui

class ClientHelper;

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

private:
    Ui::MainWindow* ui_;

    ClientHelper* helper_;
};

#endif // MAINWINDOW_HPP
