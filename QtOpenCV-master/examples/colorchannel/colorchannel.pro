include(../../QtOpenCV.pri)
include(../shared/shared.pri)
add_opencv_modules(core imgproc)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = colorchannel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
