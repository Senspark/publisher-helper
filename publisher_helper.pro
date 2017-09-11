TARGET = publisher_helper
TEMPLATE = subdirs

SUBDIRS = \
    android_publisher \
    helper

android_publisher.file = androidpublisher/android_publisher.pro
helper.file = src/helper.pro

helper.depends = android_publisher
