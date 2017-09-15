#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <QString>

/// https://convertcase.net/
class StringUtils {
public:
    static QString toLowerCase(const QString& text);

    static QString toUpperCase(const QString& text);

    static QString toCapitalizedCase(const QString& text);

    static QString toTitleCase(const QString& text);
};

#endif // STRINGUTILS_HPP
