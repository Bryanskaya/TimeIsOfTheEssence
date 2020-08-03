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
        Commands/add_command.cpp \
        Commands/base_command.cpp \
        Commands/transform_command.cpp \
        Errors/base_error.cpp \
        Errors/side_errors.cpp \
        Errors/vector_errors.cpp \
        Objects/camera.cpp \
        Objects/light_source.cpp \
        Objects/scene_object.cpp \
        Objects/simple_object.cpp \
        Primitives/Model/model.cpp \
        Primitives/Point/point.cpp \
        Primitives/Side/side.cpp \
        Primitives/Vector/vector.cpp \
        Primitives/Vertex/vertex.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Commands/add_command.h \
        Commands/base_command.h \
        Commands/transform_command.h \
        Errors/base_error.h \
        Errors/side_errors.h \
        Errors/vector_errors.h \
        Objects/camera.h \
        Objects/light_source.h \
        Objects/scene_object.h \
        Objects/simple_object.h \
        Primitives/Model/model.h \
        Primitives/Point/point.h \
        Primitives/Side/side.h \
        Primitives/Vector/vector.h \
        Primitives/Vertex/vertex.h \
        Scene/scene.h \
        mainwindow.h \
        new_fold/Point/mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
