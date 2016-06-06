/********************************************************************************
** Form generated from reading UI file 'distortioncorrectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTORTIONCORRECTIONDIALOG_H
#define UI_DISTORTIONCORRECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DistortionCorrectionDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_undistorted;
    QVBoxLayout *verticalLayout_2;
    QSlider *verticalSlider;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_koefisien;
    QSpinBox *spinBox_orde;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_camera;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DistortionCorrectionDialog)
    {
        if (DistortionCorrectionDialog->objectName().isEmpty())
            DistortionCorrectionDialog->setObjectName(QStringLiteral("DistortionCorrectionDialog"));
        DistortionCorrectionDialog->resize(720, 487);
        gridLayout = new QGridLayout(DistortionCorrectionDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_undistorted = new QLabel(DistortionCorrectionDialog);
        label_undistorted->setObjectName(QStringLiteral("label_undistorted"));
        label_undistorted->setMinimumSize(QSize(600, 400));
        label_undistorted->setFrameShape(QFrame::Panel);
        label_undistorted->setScaledContents(true);

        horizontalLayout->addWidget(label_undistorted);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSlider = new QSlider(DistortionCorrectionDialog);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(verticalSlider);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        doubleSpinBox_koefisien = new QDoubleSpinBox(DistortionCorrectionDialog);
        doubleSpinBox_koefisien->setObjectName(QStringLiteral("doubleSpinBox_koefisien"));

        verticalLayout->addWidget(doubleSpinBox_koefisien);

        spinBox_orde = new QSpinBox(DistortionCorrectionDialog);
        spinBox_orde->setObjectName(QStringLiteral("spinBox_orde"));

        verticalLayout->addWidget(spinBox_orde);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(DistortionCorrectionDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox_camera = new QComboBox(DistortionCorrectionDialog);
        comboBox_camera->setObjectName(QStringLiteral("comboBox_camera"));

        horizontalLayout_2->addWidget(comboBox_camera);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(DistortionCorrectionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(DistortionCorrectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DistortionCorrectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DistortionCorrectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DistortionCorrectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DistortionCorrectionDialog)
    {
        DistortionCorrectionDialog->setWindowTitle(QApplication::translate("DistortionCorrectionDialog", "Dialog", 0));
        label_undistorted->setText(QApplication::translate("DistortionCorrectionDialog", "TextLabel", 0));
        label->setText(QApplication::translate("DistortionCorrectionDialog", "Camera", 0));
        comboBox_camera->clear();
        comboBox_camera->insertItems(0, QStringList()
         << QApplication::translate("DistortionCorrectionDialog", "Left", 0)
         << QApplication::translate("DistortionCorrectionDialog", "Right", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class DistortionCorrectionDialog: public Ui_DistortionCorrectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTORTIONCORRECTIONDIALOG_H
