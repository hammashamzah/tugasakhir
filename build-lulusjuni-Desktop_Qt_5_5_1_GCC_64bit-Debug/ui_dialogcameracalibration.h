/********************************************************************************
** Form generated from reading UI file 'dialogcameracalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCAMERACALIBRATION_H
#define UI_DIALOGCAMERACALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DialogCameraCalibration
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QPushButton *pushButton_OpenVideoCal;
    QLabel *label_VideoCal;
    QSlider *horizontalSlider_VideoFrame;
    QLineEdit *lineEdit_FrameIdx;
    QGroupBox *groupBox;
    QLabel *label_CounterSelectedImage;
    QPushButton *pushButton_runCalibration;
    QPushButton *pushButton_selectFrame;

    void setupUi(QDialog *DialogCameraCalibration)
    {
        if (DialogCameraCalibration->objectName().isEmpty())
            DialogCameraCalibration->setObjectName(QStringLiteral("DialogCameraCalibration"));
        DialogCameraCalibration->resize(886, 662);
        buttonBox = new QDialogButtonBox(DialogCameraCalibration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 620, 701, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(DialogCameraCalibration);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 40, 101, 24));
        pushButton_OpenVideoCal = new QPushButton(DialogCameraCalibration);
        pushButton_OpenVideoCal->setObjectName(QStringLiteral("pushButton_OpenVideoCal"));
        pushButton_OpenVideoCal->setGeometry(QRect(140, 40, 101, 24));
        label_VideoCal = new QLabel(DialogCameraCalibration);
        label_VideoCal->setObjectName(QStringLiteral("label_VideoCal"));
        label_VideoCal->setGeometry(QRect(30, 80, 640, 480));
        label_VideoCal->setFrameShape(QFrame::WinPanel);
        label_VideoCal->setScaledContents(true);
        horizontalSlider_VideoFrame = new QSlider(DialogCameraCalibration);
        horizontalSlider_VideoFrame->setObjectName(QStringLiteral("horizontalSlider_VideoFrame"));
        horizontalSlider_VideoFrame->setGeometry(QRect(30, 580, 281, 16));
        horizontalSlider_VideoFrame->setOrientation(Qt::Horizontal);
        lineEdit_FrameIdx = new QLineEdit(DialogCameraCalibration);
        lineEdit_FrameIdx->setObjectName(QStringLiteral("lineEdit_FrameIdx"));
        lineEdit_FrameIdx->setGeometry(QRect(330, 580, 113, 24));
        groupBox = new QGroupBox(DialogCameraCalibration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(700, 70, 161, 341));
        label_CounterSelectedImage = new QLabel(groupBox);
        label_CounterSelectedImage->setObjectName(QStringLiteral("label_CounterSelectedImage"));
        label_CounterSelectedImage->setGeometry(QRect(7, 25, 151, 161));
        QFont font;
        font.setPointSize(48);
        label_CounterSelectedImage->setFont(font);
        label_CounterSelectedImage->setAlignment(Qt::AlignCenter);
        pushButton_runCalibration = new QPushButton(groupBox);
        pushButton_runCalibration->setObjectName(QStringLiteral("pushButton_runCalibration"));
        pushButton_runCalibration->setGeometry(QRect(30, 310, 101, 24));
        pushButton_selectFrame = new QPushButton(DialogCameraCalibration);
        pushButton_selectFrame->setObjectName(QStringLiteral("pushButton_selectFrame"));
        pushButton_selectFrame->setGeometry(QRect(460, 580, 91, 24));

        retranslateUi(DialogCameraCalibration);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogCameraCalibration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogCameraCalibration, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCameraCalibration);
    } // setupUi

    void retranslateUi(QDialog *DialogCameraCalibration)
    {
        DialogCameraCalibration->setWindowTitle(QApplication::translate("DialogCameraCalibration", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DialogCameraCalibration", "Camera 1", 0)
         << QApplication::translate("DialogCameraCalibration", "Camera 2", 0)
        );
        pushButton_OpenVideoCal->setText(QApplication::translate("DialogCameraCalibration", "Open Video ", 0));
        label_VideoCal->setText(QApplication::translate("DialogCameraCalibration", "Video CAlibration", 0));
        groupBox->setTitle(QApplication::translate("DialogCameraCalibration", "Number Frames Selected", 0));
        label_CounterSelectedImage->setText(QApplication::translate("DialogCameraCalibration", "0", 0));
        pushButton_runCalibration->setText(QApplication::translate("DialogCameraCalibration", "Run Calibration", 0));
        pushButton_selectFrame->setText(QApplication::translate("DialogCameraCalibration", "Select Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogCameraCalibration: public Ui_DialogCameraCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCAMERACALIBRATION_H
