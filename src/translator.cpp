#include "translator.hpp"
#include "downloader.hpp"
#include "localization.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QUrl>

using Self = Translator;

Self::Translator() {}

Self::~Translator() {}

void Self::translate(const QString& from, const QString& to,
                     const QString& text, const Callback& callback) {
    QString formatUrl("http://translate.googleapis.com/translate_a/"
                      "single?client=gtx&sl=%1&tl=%2&dt=t&q=%3");
    auto encoded = QUrl::toPercentEncoding(text);
    QUrl url(formatUrl.arg(from).arg(to).arg(QString(encoded)));

    auto downloader = new Downloader();
    downloader->download(url, [callback](const QString& content) {
        auto doc = QJsonDocument::fromJson(content.toUtf8());
        Q_ASSERT(doc.isArray());
        auto&& b0 = doc.array().at(0);
        Q_ASSERT(b0.isArray());
        auto&& b1 = b0.toArray().at(0);
        Q_ASSERT(b1.isArray());
        auto&& b2 = b1.toArray().at(0);
        callback(b2.toString());
    });
}

void Self::translate(const Localization& from, const Localization& to,
                     const QString& text, const Callback& callback) {
    return translate(from.google_translate_code(), to.google_translate_code(),
                     text, callback);
}
