QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ydyodraw
TEMPLATE = app
DESTDIR = $$PWD/bin

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mscene.cpp \
    mview.cpp

HEADERS += \
    mainwindow.h \
    mscene.h \
    mview.h

FORMS += \
    mainwindow.ui


