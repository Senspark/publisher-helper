#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <QFuture>
#include <QNetworkAccessManager>
#include <QString>

class Localization;

class Translator {
private:
    using Self = Translator;

public:
    using Callback = std::function<void(const QString& content)>;

    Translator();
    ~Translator();

    void translate(const QString& from, const QString& to, const QString& text,
                   const Callback& callback);

    void translate(const Localization& from, const Localization& to,
                   const QString& text, const Callback& callback);

private:
};

#endif // TRANSLATOR_HPP
