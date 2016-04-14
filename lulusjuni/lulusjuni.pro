#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T18:47:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lulusjuni
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

HEADERS  += mainwindow.h \
    backgroundmodeltuningdialog.h \
    fieldselectiondialog.h \
    trackingviewdialog.h \
    systemperformancedialog.h \
    errorcalculationdialog.h \
    cameraviewdialog.h \
    videoprocessor.h \
    matdisplay.h \
    playervisual.h \
    objectvariable.h \
    LinkedList.h \
    associate.h \
    preprocessing.h \
    node.h \
    perspectivetransformation.h \
    dialogcameracalibration.h \
    clickdisplay.h \
    cvmatandqimage.h \
    processor.h \
    Tracking.h \
    fusiondatafortrans.h \
    coordinatetransform.h \
    tracking.h \
    kalmanpredictor.h \
    associate.h


SOURCES += main.cpp\
    backgroundmodeltuningdialog.cpp \
    mainwindow.cpp \
    fieldselectiondialog.cpp \
    trackingviewdialog.cpp \
    systemperformancedialog.cpp \
    errorcalculationdialog.cpp \
    cameraviewdialog.cpp \
    videoprocessor.cpp \
    matdisplay.cpp \
    playervisual.cpp \
    objectvariable.cpp \
    LinkedList.cpp \
    associate.cpp \
    preprocessing.cpp \
    node.cpp \
    perspectivetransformation.cpp \
    dialogcameracalibration.cpp \
    clickdisplay.cpp \
    cvmatandqimage.cpp \
    processor.cpp \
    Tracking.cpp \
    fusiondatafortrans.cpp \
    coordinatetransform.cpp \
    tracking.cpp \
    kalmanpredictor.cpp

FORMS    += mainwindow.ui \
    backgroundmodeltuningdialog.ui \
    fieldselectiondialog.ui \
    trackingviewdialog.ui \
    systemperformancedialog.ui \
    errorcalculationdialog.ui \
    cameraviewdialog.ui \
    perspectivetransformation.ui \
    dialogcameracalibration.ui
