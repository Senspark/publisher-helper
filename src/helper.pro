QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helper
TEMPLATE = app

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++1z

LIBS += \
    -L$$PWD/../googleapis/lib -lgoogle_calendar_api \
    -L$$PWD/../googleapis/lib -lgoogle_storage_api \
    -L$$PWD/../googleapis/lib -lgoogleapis_curl_http \
    -L$$PWD/../googleapis/lib -lgoogleapis_internal \
    -L$$PWD/../googleapis/lib -lgoogleapis_json \
    -L$$PWD/../googleapis/lib -lgoogleapis_jsoncpp \
    -L$$PWD/../googleapis/lib -lgoogleapis_jsonplayback \
    -L$$PWD/../googleapis/lib -lgoogleapis_oauth2 \
    -L$$PWD/../googleapis/lib -lgoogleapis_openssl_codec \
    -L$$PWD/../googleapis/lib -lgoogleapis_scribes \
    -L$$PWD/../googleapis/lib -lgoogleapis_utils \
    -L$$OUT_PWD/../androidpublisher -landroid_publisher

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.hpp

FORMS += \
    mainwindow.ui
