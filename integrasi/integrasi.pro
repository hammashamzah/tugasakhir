#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T14:06:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = integrasi
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

SOURCES += main.cpp\
        mainwindow.cpp \
    backgroundmodeltuningdialog.cpp \
    cameraviewdialog.cpp \
    errorcalculationdialog.cpp \
    fieldselectiondialog.cpp \
    clickdisplay.cpp \
    player.cpp \
    coordinatetransform.cpp \
    cvmatandqimage.cpp \
    systemperformancedialog.cpp \
    trackingviewdialog.cpp \
    videoprocessor.cpp \
    objectdetector.cpp \
    datalogger.cpp \
    dynamicassociation.cpp \
    kalmandynamic.cpp \
    searchplayerdata.cpp \
    unitdynamicassociate.cpp \
    datawindow.cpp \
    kalmanobject.cpp

HEADERS  += mainwindow.h \
    backgroundmodeltuningdialog.h \
    cameraviewdialog.h \
    errorcalculationdialog.h \
    fieldselectiondialog.h \
    clickdisplay.h \
    player.h \
    coordinatetransform.h \
    cvmatandqimage.h \
    systemperformancedialog.h \
    trackingviewdialog.h \
    videoprocessor.h \
    objectdetector.h \
    datalogger.h \
    dynamicassociation.h \
    kalmandynamic.h \
    kalmandynamictoplevel.h \
    searchplayerdata.h \
    unitdynamicassociate.h \
    datawindow.h \
    kalmanobject.h

FORMS    += mainwindow.ui \
    backgroundmodeltuningdialog.ui \
    cameraviewdialog.ui \
    errorcalculationdialog.ui \
    fieldselectiondialog.ui \
    systemperformancedialog.ui \
    trackingviewdialog.ui \
    datawindow.ui

DISTFILES += \
    integrasi.pro.user
