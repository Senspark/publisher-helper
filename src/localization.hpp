#ifndef LOCALIZATION_HPP
#define LOCALIZATION_HPP

#include <QString>
#include <QVector>

class Localization {
private:
    using Self = Localization;

public:
    static const Self Afrikaans;
    static const Self Amharic;
    static const Self Arabic;
    static const Self Armenian;
    static const Self Azerbaijani;
    static const Self Bangla;
    static const Self Basque;
    static const Self Belarusian;
    static const Self Bulgarian;
    static const Self Burmese;
    static const Self Catalan;
    static const Self Chinese_Hong_Kong;
    static const Self Chinese_Simplified;
    static const Self Chinese_Traditional;
    static const Self Croation;
    static const Self Czech;
    static const Self Danish;
    static const Self Dutch;
    static const Self English_AU;
    static const Self English_IN;
    static const Self English_SG;
    static const Self English_ZA;
    static const Self English_CA;
    static const Self English_GB;
    static const Self English_US;
    static const Self Estonian;
    static const Self Filipino;
    static const Self Finnish;
    static const Self French;
    static const Self French_Canada;
    static const Self Galician;
    static const Self Georgian;
    static const Self German;
    static const Self Greek;
    static const Self Hebrew;
    static const Self Hindi;
    static const Self Hungarian;
    static const Self Icelandic;
    static const Self Indonesian;
    static const Self Italian;
    static const Self Japanese;
    static const Self Kannada;
    static const Self Khmer;
    static const Self Korean;
    static const Self Kyrgyz;
    static const Self Lao;
    static const Self Latvian;
    static const Self Lithuanian;
    static const Self Macedonian;
    static const Self Malay;
    static const Self Malayalam;
    static const Self Marathi;
    static const Self Mongolian;
    static const Self Nepali;
    static const Self Norwegian;
    static const Self Persian;
    static const Self Polish;
    static const Self Portuguese_Brazil;
    static const Self Portuguese_Portugal;
    static const Self Romanian;
    static const Self Romansh;
    static const Self Russian;
    static const Self Serbian;
    static const Self Sinhala;
    static const Self Slovenian;
    static const Self Spanish_Latin_America;
    static const Self Spanish_ES;
    static const Self Spanish_US;
    static const Self Swahili;
    static const Self Swedish;
    static const Self Tamil;
    static const Self Telugu;
    static const Self Thai;
    static const Self Turkish;
    static const Self Ukrainian;
    static const Self Vietnamese;
    static const Self Zulu;

    static QVector<Self> All();

    Localization();

    Localization(const Self&) = default;
    Self& operator=(const Self&) = default;

    const QString& name() const;
    const QString& iso_name() const;

    bool operator==(const Self& other) const;

private:
    Localization(const QString& name, const QString& iso_name);

    QString name_;
    QString iso_name_;
};

#endif // LOCALIZATION_HPP
