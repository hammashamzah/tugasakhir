/********************************************************************************
** Form generated from reading UI file 'fieldselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELDSELECTIONDIALOG_H
#define UI_FIELDSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "clickdisplay.h"

QT_BEGIN_NAMESPACE

class Ui_FieldSelectionDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cameraSelectCombo;
    QVBoxLayout *verticalLayout;
    ClickDisplay *imageView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_set;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *FieldSelectionDialog)
    {
        if (FieldSelectionDialog->objectName().isEmpty())
            FieldSelectionDialog->setObjectName(QStringLiteral("FieldSelectionDialog"));
        FieldSelectionDialog->resize(848, 583);
        verticalLayout_3 = new QVBoxLayout(FieldSelectionDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        cameraSelectCombo = new QComboBox(FieldSelectionDialog);
        cameraSelectCombo->setObjectName(QStringLiteral("cameraSelectCombo"));

        verticalLayout_2->addWidget(cameraSelectCombo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageView = new ClickDisplay(FieldSelectionDialog);
        imageView->setObjectName(QStringLiteral("imageView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageView->sizePolicy().hasHeightForWidth());
        imageView->setSizePolicy(sizePolicy);
        imageView->setMinimumSize(QSize(320, 240));
        imageView->setStyleSheet(QStringLiteral("Background-color: #000;"));
        imageView->setProperty("scaledContents", QVariant(true));

        verticalLayout->addWidget(imageView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_set = new QPushButton(FieldSelectionDialog);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_set->sizePolicy().hasHeightForWidth());
        pushButton_set->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_set);

        pushButton_apply = new QPushButton(FieldSelectionDialog);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));
        sizePolicy1.setHeightForWidth(pushButton_apply->sizePolicy().hasHeightForWidth());
        pushButton_apply->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_apply);

        pushButton_ok = new QPushButton(FieldSelectionDialog);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        sizePolicy1.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_ok);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(FieldSelectionDialog);

        QMetaObject::connectSlotsByName(FieldSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *FieldSelectionDialog)
    {
        FieldSelectionDialog->setWindowTitle(QApplication::translate("FieldSelectionDialog", "Dialog", 0));
        cameraSelectCombo->clear();
        cameraSelectCombo->insertItems(0, QStringList()
         << QApplication::translate("FieldSelectionDialog", "Camera 1", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 2", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 1 Trapezium", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 2 Trapezium", 0)
        );
        imageView->setProperty("text", QVariant(QString()));
        pushButton_set->setText(QApplication::translate("FieldSelectionDialog", "Set Masking...", 0));
        pushButton_apply->setText(QApplication::translate("FieldSelectionDialog", "Apply", 0));
        pushButton_ok->setText(QApplication::translate("FieldSelectionDialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class FieldSelectionDialog: public Ui_FieldSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDSELECTIONDIALOG_H
