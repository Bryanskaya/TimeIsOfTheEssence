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
        Commands/draw_command.cpp \
        Commands/transform_command.cpp \
        Commands/update_command.cpp \
        Errors/base_error.cpp \
        Errors/hourglass_error.cpp \
        Errors/scene_errors.cpp \
        Errors/side_errors.cpp \
        Errors/vector_errors.cpp \
        Manager/managers.cpp \
        Objects/Visitors/draw_visitor.cpp \
        Objects/Visitors/init_state_visitor.cpp \
        Objects/Visitors/object_visitor.cpp \
        Objects/Visitors/update_visitor.cpp \
        Objects/camera.cpp \
        Objects/composite_object.cpp \
        Objects/glass.cpp \
        Objects/light_source.cpp \
        Objects/sand.cpp \
        Objects/scene_object.cpp \
        Objects/simple_object.cpp \
        Objects/stand.cpp \
        Objects/surface_object.cpp \
        Primitives/Box/box.cpp \
        Primitives/Model/model.cpp \
        Primitives/Piramid/piramid.cpp \
        Primitives/Piramid/piramid_3.cpp \
        Primitives/Point/point.cpp \
        Primitives/Side/side.cpp \
        Primitives/Surface/surface.cpp \
        Primitives/Vector/vector.cpp \
        Primitives/Vertex/vertex.cpp \
        Scene/scene.cpp \
        Transformation/transformation.cpp \
        Visualizing/drawer.cpp \
        Visualizing/projecting.cpp \
        Visualizing/visualizer.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Commands/add_command.h \
        Commands/all_commands.h \
        Commands/base_command.h \
        Commands/draw_command.h \
        Commands/transform_command.h \
        Commands/update_command.h \
        Errors/base_error.h \
        Errors/hourglass_error.h \
        Errors/scene_errors.h \
        Errors/side_errors.h \
        Errors/vector_errors.h \
        Manager/managers.h \
        Objects/Visitors/draw_visitor.h \
        Objects/Visitors/init_state_visitor.h \
        Objects/Visitors/object_visitor.h \
        Objects/Visitors/update_visitor.h \
        Objects/camera.h \
        Objects/composite_object.h \
        Objects/glass.h \
        Objects/light_source.h \
        Objects/sand.h \
        Objects/scene_object.h \
        Objects/simple_object.h \
        Objects/stand.h \
        Objects/surface_object.h \
        Primitives/Box/box.h \
        Primitives/Model/model.h \
        Primitives/Piramid/piramid.h \
        Primitives/Piramid/piramid_3.h \
        Primitives/Point/point.h \
        Primitives/Side/side.h \
        Primitives/Surface/surface.h \
        Primitives/Vector/vector.h \
        Primitives/Vertex/vertex.h \
        Scene/facade.h \
        Scene/scene.h \
        Transformation/transformation.h \
        Transformation/transformator.h \
        Visualizing/drawer.h \
        Visualizing/projecting.h \
        Visualizing/visualizer.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
