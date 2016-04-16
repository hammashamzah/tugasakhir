/********************************************************************************
** Form generated from reading UI file 'cameraviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAVIEWDIALOG_H
#define UI_CAMERAVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraViewDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *raw_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *raw_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QLabel *masked_1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_11;
    QLabel *masked_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_19;
    QLabel *object_1;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_21;
    QLabel *object_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_25;
    QLabel *opened_1;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_27;
    QLabel *opened_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_31;
    QLabel *blured_1;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_33;
    QLabel *blured_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_37;
    QLabel *keypoint_1;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_39;
    QLabel *keypoint_2;

    void setupUi(QDialog *CameraViewDialog)
    {
        if (CameraViewDialog->objectName().isEmpty())
            CameraViewDialog->setObjectName(QStringLiteral("CameraViewDialog"));
        CameraViewDialog->resize(826, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CameraViewDialog->sizePolicy().hasHeightForWidth());
        CameraViewDialog->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(CameraViewDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scrollArea = new QScrollArea(CameraViewDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 794, 1658));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        raw_1 = new QLabel(scrollAreaWidgetContents);
        raw_1->setObjectName(QStringLiteral("raw_1"));
        sizePolicy.setHeightForWidth(raw_1->sizePolicy().hasHeightForWidth());
        raw_1->setSizePolicy(sizePolicy);
        raw_1->setMinimumSize(QSize(320, 240));
        raw_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout->addWidget(raw_1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        raw_2 = new QLabel(scrollAreaWidgetContents);
        raw_2->setObjectName(QStringLiteral("raw_2"));
        sizePolicy.setHeightForWidth(raw_2->sizePolicy().hasHeightForWidth());
        raw_2->setSizePolicy(sizePolicy);
        raw_2->setMinimumSize(QSize(320, 240));
        raw_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_2->addWidget(raw_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_10);

        masked_1 = new QLabel(scrollAreaWidgetContents);
        masked_1->setObjectName(QStringLiteral("masked_1"));
        sizePolicy.setHeightForWidth(masked_1->sizePolicy().hasHeightForWidth());
        masked_1->setSizePolicy(sizePolicy);
        masked_1->setMinimumSize(QSize(320, 240));
        masked_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_4->addWidget(masked_1);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_11);

        masked_2 = new QLabel(scrollAreaWidgetContents);
        masked_2->setObjectName(QStringLiteral("masked_2"));
        masked_2->setMinimumSize(QSize(320, 240));
        masked_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_6->addWidget(masked_2);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_19);

        object_1 = new QLabel(scrollAreaWidgetContents);
        object_1->setObjectName(QStringLiteral("object_1"));
        object_1->setMinimumSize(QSize(320, 240));
        object_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_13->addWidget(object_1);


        verticalLayout_8->addLayout(verticalLayout_13);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_21);

        object_2 = new QLabel(scrollAreaWidgetContents);
        object_2->setObjectName(QStringLiteral("object_2"));
        object_2->setMinimumSize(QSize(320, 240));
        object_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_14->addWidget(object_2);


        horizontalLayout_4->addLayout(verticalLayout_14);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy1.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy1);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_25);

        opened_1 = new QLabel(scrollAreaWidgetContents);
        opened_1->setObjectName(QStringLiteral("opened_1"));
        opened_1->setMinimumSize(QSize(320, 240));
        opened_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_16->addWidget(opened_1);


        verticalLayout_9->addLayout(verticalLayout_16);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_27);

        opened_2 = new QLabel(scrollAreaWidgetContents);
        opened_2->setObjectName(QStringLiteral("opened_2"));
        opened_2->setMinimumSize(QSize(320, 240));
        opened_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_17->addWidget(opened_2);


        horizontalLayout_5->addLayout(verticalLayout_17);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy1.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy1);
        label_31->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_31);

        blured_1 = new QLabel(scrollAreaWidgetContents);
        blured_1->setObjectName(QStringLiteral("blured_1"));
        blured_1->setMinimumSize(QSize(320, 240));
        blured_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_19->addWidget(blured_1);


        verticalLayout_10->addLayout(verticalLayout_19);


        horizontalLayout_6->addLayout(verticalLayout_10);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_33 = new QLabel(scrollAreaWidgetContents);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy1.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy1);
        label_33->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(label_33);

        blured_2 = new QLabel(scrollAreaWidgetContents);
        blured_2->setObjectName(QStringLiteral("blured_2"));
        blured_2->setMinimumSize(QSize(320, 240));
        blured_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_20->addWidget(blured_2);


        horizontalLayout_6->addLayout(verticalLayout_20);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_37 = new QLabel(scrollAreaWidgetContents);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy1.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy1);
        label_37->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(label_37);

        keypoint_1 = new QLabel(scrollAreaWidgetContents);
        keypoint_1->setObjectName(QStringLiteral("keypoint_1"));
        keypoint_1->setMinimumSize(QSize(320, 240));
        keypoint_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_22->addWidget(keypoint_1);


        verticalLayout_12->addLayout(verticalLayout_22);


        horizontalLayout_7->addLayout(verticalLayout_12);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_39 = new QLabel(scrollAreaWidgetContents);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy1.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy1);
        label_39->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(label_39);

        keypoint_2 = new QLabel(scrollAreaWidgetContents);
        keypoint_2->setObjectName(QStringLiteral("keypoint_2"));
        keypoint_2->setMinimumSize(QSize(320, 240));
        keypoint_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_23->addWidget(keypoint_2);


        horizontalLayout_7->addLayout(verticalLayout_23);


        verticalLayout_3->addLayout(horizontalLayout_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        retranslateUi(CameraViewDialog);

        QMetaObject::connectSlotsByName(CameraViewDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraViewDialog)
    {
        CameraViewDialog->setWindowTitle(QApplication::translate("CameraViewDialog", "Dialog", 0));
        label_7->setText(QApplication::translate("CameraViewDialog", "Raw 1", 0));
        raw_1->setText(QString());
        label_8->setText(QApplication::translate("CameraViewDialog", "Raw 2", 0));
        raw_2->setText(QString());
        label_10->setText(QApplication::translate("CameraViewDialog", "Masked Frame 1", 0));
        masked_1->setText(QString());
        label_11->setText(QApplication::translate("CameraViewDialog", "Masked Frame 2", 0));
        masked_2->setText(QString());
        label_19->setText(QApplication::translate("CameraViewDialog", "Object Frame 1", 0));
        object_1->setText(QString());
        label_21->setText(QApplication::translate("CameraViewDialog", "Object Frame 2", 0));
        object_2->setText(QString());
        label_25->setText(QApplication::translate("CameraViewDialog", "Opened Frame 1", 0));
        opened_1->setText(QString());
        label_27->setText(QApplication::translate("CameraViewDialog", "Opened Frame 2", 0));
        opened_2->setText(QString());
        label_31->setText(QApplication::translate("CameraViewDialog", "Blurred Frame 1", 0));
        blured_1->setText(QString());
        label_33->setText(QApplication::translate("CameraViewDialog", "Blurred Frame 2", 0));
        blured_2->setText(QString());
        label_37->setText(QApplication::translate("CameraViewDialog", "Keypoints 1", 0));
        keypoint_1->setText(QString());
        label_39->setText(QApplication::translate("CameraViewDialog", "Keypoints 2", 0));
        keypoint_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraViewDialog: public Ui_CameraViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAVIEWDIALOG_H
