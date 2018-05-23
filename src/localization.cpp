#include "localization.hpp"

using Self = Localization;

const Self Self::Afrikaans("Afrikaans", "af");
const Self Self::Amharic("Amharic", "am");
const Self Self::Arabic("Arabic", "ar");
const Self Self::Armenian("Armenian", "hy-AM");
const Self Self::Azerbaijani("Azerbaijani", "az-AZ");
const Self Self::Bangla("Bangla", "bn-BD");
const Self Self::Basque("Basque", "eu-ES");
const Self Self::Belarusian("Belarusian", "be");
const Self Self::Bulgarian("Bulgarian", "bg");
const Self Self::Burmese("Burmese", "my-MM");
const Self Self::Catalan("Catalan", "ca");
const Self Self::Chinese_Hong_Kong("Chinese (Hong Kong)", "zh-HK");
const Self Self::Chinese_Simplified("Chinese (Simplified)", "zh-CN");
const Self Self::Chinese_Traditional("Chinese (Traditional)", "zh-TW");
const Self Self::Croation("Croatian", "hr");
const Self Self::Czech("Czech", "cs-CZ");
const Self Self::Danish("Danish", "da-DK");
const Self Self::Dutch("Dutch", "nl-NL");
const Self Self::English_AU("English", "en-AU");
const Self Self::English_IN("English", "en-IN");
const Self Self::English_SG("English", "en-SG");
const Self Self::English_ZA("English", "en-ZA");
const Self Self::English_CA("English (Canada)", "en-CA");
const Self Self::English_GB("English (United Kingdom)", "en-GB");
const Self Self::English_US("English (United States)", "en-US");
const Self Self::Estonian("Estonian", "et");
const Self Self::Filipino("Filipino", "fil");
const Self Self::Finnish("Finnish", "fi-FI");
const Self Self::French("French", "fr-FR");
const Self Self::French_Canada("French (Canada)", "fr-CA");
const Self Self::Galician("Galician", "gl-ES");
const Self Self::Georgian("Georgian", "ka-GE");
const Self Self::German("German", "de-DE");
const Self Self::Greek("Greek", "el-GR");
const Self Self::Hebrew("Hebrew", "iw-IL");
const Self Self::Hindi("Hindi", "hi-IN");
const Self Self::Hungarian("Hungarian", "hu-HU");
const Self Self::Icelandic("Icelandic", "is-IS");
const Self Self::Indonesian("Indonesian", "id");
const Self Self::Italian("Italian", "it-IT");
const Self Self::Japanese("Japanese", "ja-JP");
const Self Self::Kannada("Kannada", "kn-IN");
const Self Self::Khmer("Khmer", "km-KH");
const Self Self::Korean("Korean (South Korean)", "ko-KR");
const Self Self::Kyrgyz("Kyrgrz", "ky-KG");
const Self Self::Lao("Lao", "lo-LA");
const Self Self::Latvian("Latvian", "lv");
const Self Self::Lithuanian("Lithuanian", "lt");
const Self Self::Macedonian("Macedonian", "mk-MK");
const Self Self::Malay("Malay", "ms");
const Self Self::Malayalam("Malayalam", "ml-IN");
const Self Self::Marathi("Marathi", "mr-IN");
const Self Self::Mongolian("Mongolian", "mn-MN");
const Self Self::Nepali("Nepali", "ne-NP");
const Self Self::Norwegian("Norwegian", "no-NO");
const Self Self::Persian("Persian", "fa");
const Self Self::Polish("Polish", "pl-PL");
const Self Self::Portuguese_Brazil("Portuguese (Brazil)", "pt-BR");
const Self Self::Portuguese_Portugal("Portuguese (Portugal)", "pt-PT");
const Self Self::Romanian("Romanian", "ro");
// const Self Self::Romansh("Romansh", "rm"); Not supported by google translation.
const Self Self::Russian("Russian", "ru-RU");
const Self Self::Serbian("Serbian", "sr");
const Self Self::Sinhala("Sinhala", "si-LK");
const Self Self::Slovenian("Slovak", "sk");
const Self Self::Spanish_Latin_America("Spanish (Latin America)", "es-419");
const Self Self::Spanish_ES("Spanish (Spain)", "es-ES");
const Self Self::Spanish_US("Spanish (United States)", "es-US");
const Self Self::Swahili("Swahili", "sw");
const Self Self::Swedish("Swedish", "sv-SE");
const Self Self::Tamil("Tamil", "ta-IN");
const Self Self::Telugu("Telugu", "te-IN");
const Self Self::Thai("Thai", "th");
const Self Self::Turkish("Turkish", "tr-TR");
const Self Self::Ukrainian("Ukrainian", "uk");
const Self Self::Vietnamese("Vietnamese", "vi");
const Self Self::Zulu("Zulu", "zu");

QVector<Self> Self::All() {
    QVector<Self> list;
    list.append(Afrikaans);
    list.append(Amharic);
    list.append(Arabic);
    list.append(Armenian);
    list.append(Azerbaijani);
    list.append(Bangla);
    list.append(Basque);
    list.append(Belarusian);
    list.append(Bulgarian);
    list.append(Burmese);
    list.append(Catalan);
    list.append(Chinese_Hong_Kong);
    list.append(Chinese_Simplified);
    list.append(Chinese_Traditional);
    list.append(Croation);
    list.append(Czech);
    list.append(Danish);
    list.append(Dutch);
    list.append(English_AU);
    list.append(English_IN);
    list.append(English_SG);
    list.append(English_ZA);
    list.append(English_CA);
    list.append(English_GB);
    list.append(English_US);
    list.append(Estonian);
    list.append(Filipino);
    list.append(Finnish);
    list.append(French);
    list.append(French_Canada);
    list.append(Galician);
    list.append(Georgian);
    list.append(German);
    list.append(Greek);
    list.append(Hebrew);
    list.append(Hindi);
    list.append(Hungarian);
    list.append(Icelandic);
    list.append(Indonesian);
    list.append(Italian);
    list.append(Japanese);
    list.append(Kannada);
    list.append(Khmer);
    list.append(Korean);
    list.append(Kyrgyz);
    list.append(Lao);
    list.append(Latvian);
    list.append(Lithuanian);
    list.append(Macedonian);
    list.append(Malay);
    list.append(Malayalam);
    list.append(Marathi);
    list.append(Mongolian);
    list.append(Nepali);
    list.append(Norwegian);
    list.append(Persian);
    list.append(Polish);
    list.append(Portuguese_Brazil);
    list.append(Portuguese_Portugal);
    list.append(Romanian);
    // list.append(Romansh);
    list.append(Russian);
    list.append(Serbian);
    list.append(Sinhala);
    list.append(Slovenian);
    list.append(Spanish_Latin_America);
    list.append(Spanish_ES);
    list.append(Spanish_US);
    list.append(Swahili);
    list.append(Swedish);
    list.append(Tamil);
    list.append(Telugu);
    list.append(Thai);
    list.append(Turkish);
    list.append(Ukrainian);
    list.append(Vietnamese);
    list.append(Zulu);
    return list;
}

const QString& Self::name() const {
    return name_;
}

const QString& Self::iso_name() const {
    return iso_name_;
}

const QString& Self::google_translate_code() const {
    return google_translate_code_;
}

Self::Localization() {
    Q_ASSERT(false);
}

Self::Localization(const QString& name, const QString& iso_name)
    : name_(name)
    , iso_name_(iso_name) {
    if (iso_name == "zh-CN" || iso_name == "zh-TW") {
        google_translate_code_ = iso_name;
    } else if (iso_name.contains('-')) {
        auto i = iso_name.indexOf('-');
        google_translate_code_ = iso_name.left(i);
    } else {
        google_translate_code_ = iso_name;
    }
}

bool Self::operator==(const Self& other) const {
    return iso_name() == other.iso_name();
}
