#include "downloader.hpp"

#include <QNetworkReply>
#include <QNetworkRequest>

using Self = Downloader;

Self::Downloader() {
    qDebug() << Q_FUNC_INFO;
}

Self::~Downloader() {
    qDebug() << Q_FUNC_INFO;
}

void Self::download(const QUrl& url, const Callback& callback) {
    qDebug() << "attemp to download: " << url;
    QNetworkRequest request(url);
    networkManager_.get(request);
    connect(&networkManager_, &QNetworkAccessManager::finished,
            [this, callback](QNetworkReply* reply) {
                auto statusCode = reply->attribute(
                    QNetworkRequest::Attribute::HttpStatusCodeAttribute);
                QString content(reply->readAll());
                qDebug() << "downloaded: " << content;
                callback(content);
                deleteLater();
            });
}
