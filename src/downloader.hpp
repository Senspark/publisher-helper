#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <QNetworkAccessManager>
#include <QUrl>

class Downloader : public QObject {
    Q_OBJECT

private:
    using Self = Downloader;

public:
    using Callback = std::function<void(const QString& content)>;

    Downloader();
    virtual ~Downloader() override;

    void download(const QUrl& url, const Callback& callback);

private:
    Callback callback_;
    QNetworkAccessManager networkManager_;
};

#endif // DOWNLOADER_HPP
