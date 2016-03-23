#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T04:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QLabel_mouseEvent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matdisplay.cpp

HEADERS  += mainwindow.h \
    matdisplay.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include
LIBS += `pkg-config opencv --cflags --libs`
