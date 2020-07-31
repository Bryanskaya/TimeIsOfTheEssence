#-------------------------------------------------
#
# Project created by QtCreator 2020-07-17T20:48:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = coursework
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Errors/base_error.cpp \
        Errors/vector_errors.cpp \
        Objects/Point/point.cpp \
        Objects/Side/side.cpp \
        Objects/Vector/vector.cpp \
        Objects/Vertex/vertex.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Errors/base_error.h \
        Errors/vector_errors.h \
        Objects/Point/point.h \
        Objects/Side/side.h \
        Objects/Vector/vector.h \
        Objects/Vertex/vertex.h \
        mainwindow.h \
        new_fold/Point/mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
