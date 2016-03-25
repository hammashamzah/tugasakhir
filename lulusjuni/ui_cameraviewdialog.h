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
    QVBoxLayout *verticalLayout_11;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_26;
    QVBoxLayout *verticalLayout_25;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *raw_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *raw_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *raw_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QLabel *sd;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_11;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_12;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_19;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_21;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_23;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_25;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_27;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_29;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_31;
    QLabel *label_32;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_33;
    QLabel *label_34;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_35;
    QLabel *label_36;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_37;
    QLabel *label_38;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_39;
    QLabel *label_40;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_41;
    QLabel *label_42;

    void setupUi(QDialog *CameraViewDialog)
    {
        if (CameraViewDialog->objectName().isEmpty())
            CameraViewDialog->setObjectName(QStringLiteral("CameraViewDialog"));
        CameraViewDialog->resize(775, 554);
        verticalLayout_11 = new QVBoxLayout(CameraViewDialog);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        scrollArea = new QScrollArea(CameraViewDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1962, 3102));
        verticalLayout_26 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        raw_1 = new QLabel(scrollAreaWidgetContents);
        raw_1->setObjectName(QStringLiteral("raw_1"));
        raw_1->setMinimumSize(QSize(640, 480));
        raw_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout->addWidget(raw_1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        raw_2 = new QLabel(scrollAreaWidgetContents);
        raw_2->setObjectName(QStringLiteral("raw_2"));
        raw_2->setMinimumSize(QSize(640, 480));
        raw_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_2->addWidget(raw_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        raw_3 = new QLabel(scrollAreaWidgetContents);
        raw_3->setObjectName(QStringLiteral("raw_3"));
        raw_3->setMinimumSize(QSize(640, 480));
        raw_3->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_3->addWidget(raw_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_25->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_10);

        sd = new QLabel(scrollAreaWidgetContents);
        sd->setObjectName(QStringLiteral("sd"));
        sd->setMinimumSize(QSize(640, 480));
        sd->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_4->addWidget(sd);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_11);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(240, 180));
        label_5->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_6->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_12);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(640, 480));
        label_6->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_7->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_25->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_19);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(640, 480));
        label_20->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_13->addWidget(label_20);


        verticalLayout_8->addLayout(verticalLayout_13);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_21);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(640, 480));
        label_22->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_14->addWidget(label_22);


        horizontalLayout_4->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_23);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(640, 480));
        label_24->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_15->addWidget(label_24);


        horizontalLayout_4->addLayout(verticalLayout_15);


        verticalLayout_25->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_25);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(640, 480));
        label_26->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_16->addWidget(label_26);


        verticalLayout_9->addLayout(verticalLayout_16);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_27);

        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setMinimumSize(QSize(640, 480));
        label_28->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_17->addWidget(label_28);


        horizontalLayout_5->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_29 = new QLabel(scrollAreaWidgetContents);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_29);

        label_30 = new QLabel(scrollAreaWidgetContents);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(640, 480));
        label_30->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_18->addWidget(label_30);


        horizontalLayout_5->addLayout(verticalLayout_18);


        verticalLayout_25->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);
        label_31->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_31);

        label_32 = new QLabel(scrollAreaWidgetContents);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMinimumSize(QSize(640, 480));
        label_32->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_19->addWidget(label_32);


        verticalLayout_10->addLayout(verticalLayout_19);


        horizontalLayout_6->addLayout(verticalLayout_10);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_33 = new QLabel(scrollAreaWidgetContents);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy);
        label_33->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(label_33);

        label_34 = new QLabel(scrollAreaWidgetContents);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMinimumSize(QSize(640, 480));
        label_34->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_20->addWidget(label_34);


        horizontalLayout_6->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_35 = new QLabel(scrollAreaWidgetContents);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy);
        label_35->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_35);

        label_36 = new QLabel(scrollAreaWidgetContents);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMinimumSize(QSize(640, 480));
        label_36->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_21->addWidget(label_36);


        horizontalLayout_6->addLayout(verticalLayout_21);


        verticalLayout_25->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_37 = new QLabel(scrollAreaWidgetContents);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy);
        label_37->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(label_37);

        label_38 = new QLabel(scrollAreaWidgetContents);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setMinimumSize(QSize(640, 480));
        label_38->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_22->addWidget(label_38);


        verticalLayout_12->addLayout(verticalLayout_22);


        horizontalLayout_7->addLayout(verticalLayout_12);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_39 = new QLabel(scrollAreaWidgetContents);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy);
        label_39->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(label_39);

        label_40 = new QLabel(scrollAreaWidgetContents);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(640, 480));
        label_40->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_23->addWidget(label_40);


        horizontalLayout_7->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        label_41 = new QLabel(scrollAreaWidgetContents);
        label_41->setObjectName(QStringLiteral("label_41"));
        sizePolicy.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy);
        label_41->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(label_41);

        label_42 = new QLabel(scrollAreaWidgetContents);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setMinimumSize(QSize(640, 480));
        label_42->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_24->addWidget(label_42);


        horizontalLayout_7->addLayout(verticalLayout_24);


        verticalLayout_25->addLayout(horizontalLayout_7);


        verticalLayout_26->addLayout(verticalLayout_25);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_11->addWidget(scrollArea);


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
        label_9->setText(QApplication::translate("CameraViewDialog", "Raw 3", 0));
        raw_3->setText(QString());
        label_10->setText(QApplication::translate("CameraViewDialog", "Background Removal 1", 0));
        sd->setText(QString());
        label_11->setText(QApplication::translate("CameraViewDialog", "Background Removal 2", 0));
        label_5->setText(QString());
        label_12->setText(QApplication::translate("CameraViewDialog", "Background Removal 3", 0));
        label_6->setText(QString());
        label_19->setText(QApplication::translate("CameraViewDialog", "Histogram 1", 0));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("CameraViewDialog", "Histogram 2", 0));
        label_22->setText(QString());
        label_23->setText(QApplication::translate("CameraViewDialog", "Histogram 3", 0));
        label_24->setText(QString());
        label_25->setText(QApplication::translate("CameraViewDialog", "Histogram 1", 0));
        label_26->setText(QString());
        label_27->setText(QApplication::translate("CameraViewDialog", "Histogram 2", 0));
        label_28->setText(QString());
        label_29->setText(QApplication::translate("CameraViewDialog", "Histogram 3", 0));
        label_30->setText(QString());
        label_31->setText(QApplication::translate("CameraViewDialog", "Histogram 1", 0));
        label_32->setText(QString());
        label_33->setText(QApplication::translate("CameraViewDialog", "Histogram 2", 0));
        label_34->setText(QString());
        label_35->setText(QApplication::translate("CameraViewDialog", "Histogram 3", 0));
        label_36->setText(QString());
        label_37->setText(QApplication::translate("CameraViewDialog", "Histogram 1", 0));
        label_38->setText(QString());
        label_39->setText(QApplication::translate("CameraViewDialog", "Histogram 2", 0));
        label_40->setText(QString());
        label_41->setText(QApplication::translate("CameraViewDialog", "Histogram 3", 0));
        label_42->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraViewDialog: public Ui_CameraViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAVIEWDIALOG_H
