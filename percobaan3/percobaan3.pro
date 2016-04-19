QT += core
QT -= gui

TARGET = percobaan3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab


SOURCES += main.cpp \
    dynamiassociation.cpp \
    player.cpp \
    searchplayerdata.cpp \
    unitdynamicassociate.cpp \
    kalmandynamic.cpp \
    kalmandynamictoplevel.cpp \
    kalmanobject.cpp

HEADERS += \
    dynamiassociation.h \
    player.h \
    searchplayerdata.h \
    unitdynamicassociate.h \
    kalmandynamic.h \
    kalmandynamictoplevel.h \
    kalmanobject.h

