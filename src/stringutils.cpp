#include <ciso646>

#include "stringutils.hpp"

#include <QSet>

using Self = StringUtils;

QString Self::toLowerCase(const QString& text) {
    return text.toLower();
}

QString Self::toUpperCase(const QString& text) {
    return text.toUpper();
}

QString Self::toCapitalizedCase(const QString& text) {
    auto result = toLowerCase(text);
    for (int i = 0; i < result.size(); ++i) {
        if (i == 0 || (result[i - 1].isSpace() && result[i].isLetter())) {
            result[i] = result[i].toUpper();
        }
    }
    return result;
}

QString Self::toTitleCase(const QString& text) {
    // https://github.com/gouch/to-title-case/blob/master/to-title-case.js
    QSet<QString> smallWords;
    smallWords << "a"
               << "an"
               << "and"
               << "as"
               << "at"
               << "but"
               << "by"
               << "en"
               << "for"
               << "if"
               << "in"
               << "nor"
               << "of"
               << "on"
               << "or"
               << "per"
               << "the"
               << "to"
               << "vs."
               << "via";

    auto result = toLowerCase(text);
    bool first = true;
    for (int i = 0; i < result.size(); ++i) {
        if (i == 0 || (result[i - 1].isSpace() && result[i].isLetter())) {
            if (first) {
                first = false;
            } else {
                QString word;
                for (int j = i; j < result.size(); ++j) {
                    if (result[j].isSpace()) {
                        break;
                    }
                    word.append(result[j]);
                }
                if (smallWords.contains(word)) {
                    continue;
                }
            }
            result[i] = result[i].toUpper();
        }
    }
    return result;
}
