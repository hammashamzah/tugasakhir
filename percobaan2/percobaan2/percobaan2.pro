QT += core
QT -= gui

TARGET = percobaan2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    associate.cpp \
    cameraobjectprocessor.cpp \
    datainputcam.cpp \
    datainputtrans.cpp \
    dataseparator.cpp \
    dataseparatorcam.cpp \
    fusiondatafortrans.cpp \
    generatematcam.cpp \
    kalmanpredictor.cpp \
    player.cpp \
    searchplayerdata.cpp \
    boundaryhandler.cpp \
    kalmantoplevel.cpp

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

HEADERS += \
    associate.h \
    cameraobjectprocessor.h \
    datainputcam.h \
    datainputtrans.h \
    dataseparator.h \
    dataseparatorcam.h \
    fusiondatafortrans.h \
    generatematcam.h \
    kalmanpredictor.h \
    player.h \
    searchplayerdata.h \
    boundaryhandler.h \
    kalmantoplevel.h
