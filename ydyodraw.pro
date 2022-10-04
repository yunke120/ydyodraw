QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ydyodraw
TEMPLATE = app
DESTDIR = $$PWD/bin

INCLUDEPATH += $$PWD/items

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    itemlabel.cpp \
    items/mitem.cpp \
    main.cpp \
    mainwindow.cpp \
    mscene.cpp \
    mview.cpp

HEADERS += \
    itemlabel.h \
    items/mitem.h \
    mainwindow.h \
    mscene.h \
    mview.h \
    reflect.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    Resource.qrc


