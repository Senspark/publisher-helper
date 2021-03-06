QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helper
TEMPLATE = app

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++1z

INCLUDEPATH += \
    $$PWD/../androidpublisher \
    $$PWD/../googleapis/include \
    $$PWD/../gflags/include \
    $$PWD/../glog/src \
    $$PWD/../jsoncpp/include

LIBS += \
    -L$$PWD/../googleapis/lib -lgoogle_calendar_api \
    -L$$PWD/../googleapis/lib -lgoogle_storage_api \
    -L$$PWD/../googleapis/lib -lgoogleapis_curl_http \
    -L$$PWD/../googleapis/lib -lgoogleapis_http \
    -L$$PWD/../googleapis/lib -lgoogleapis_internal \
    -L$$PWD/../googleapis/lib -lgoogleapis_json \
    -L$$PWD/../googleapis/lib -lgoogleapis_jsoncpp \
    -L$$PWD/../googleapis/lib -lgoogleapis_jsonplayback \
    -L$$PWD/../googleapis/lib -lgoogleapis_oauth2 \
    -L$$PWD/../googleapis/lib -lgoogleapis_openssl_codec \
    -L$$PWD/../googleapis/lib -lgoogleapis_scribes \
    -L$$PWD/../googleapis/lib -lgoogleapis_utils \
    -L$$OUT_PWD/../androidpublisher -landroid_publisher \
    $$PWD/../gflags/lib/libgflags.a \
    $$PWD/../glog/.libs/libglog.a \
    $$PWD/../jsoncpp/libjsoncpp.a \
    $$PWD/../openssl/libssl.a \
    $$PWD/../openssl/libcrypto.a \
    -lcurl

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    clienthelper.cpp \
    inappproducttree.cpp \
    inappproductmodel.cpp \
    inappproductmodelid.cpp \
    datastatehelper.cpp \
    localization.cpp \
    selectcolumndialog.cpp \
    localizationlist.cpp \
    translator.cpp \
    downloader.cpp \
    stringutils.cpp

HEADERS += \
    mainwindow.hpp \
    clienthelper.hpp \
    inappproducttree.hpp \
    inappproductmodel.hpp \
    inappproductmodelid.hpp \
    datastatehelper.hpp \
    localization.hpp \
    selectcolumndialog.hpp \
    localizationlist.hpp \
    translator.hpp \
    downloader.hpp \
    stringutils.hpp

FORMS += \
    mainwindow.ui \
    selectcolumndialog.ui
