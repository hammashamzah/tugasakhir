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
#include <clickdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_FieldSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *cameraSelectCombo;
    ClickDisplay *imageView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_set;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_ok;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_load_file;
    QPushButton *pushButton_load_default_file;
    QPushButton *pushButton_save_file;

    void setupUi(QDialog *FieldSelectionDialog)
    {
        if (FieldSelectionDialog->objectName().isEmpty())
            FieldSelectionDialog->setObjectName(QStringLiteral("FieldSelectionDialog"));
        FieldSelectionDialog->resize(848, 583);
        verticalLayout = new QVBoxLayout(FieldSelectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cameraSelectCombo = new QComboBox(FieldSelectionDialog);
        cameraSelectCombo->setObjectName(QStringLiteral("cameraSelectCombo"));

        verticalLayout->addWidget(cameraSelectCombo);

        imageView = new ClickDisplay(FieldSelectionDialog);
        imageView->setObjectName(QStringLiteral("imageView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageView->sizePolicy().hasHeightForWidth());
        imageView->setSizePolicy(sizePolicy);
        imageView->setMinimumSize(QSize(320, 240));
        imageView->setStyleSheet(QStringLiteral("Background-color: #000;"));
        imageView->setScaledContents(true);

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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_load_file = new QPushButton(FieldSelectionDialog);
        pushButton_load_file->setObjectName(QStringLiteral("pushButton_load_file"));

        horizontalLayout_2->addWidget(pushButton_load_file);

        pushButton_load_default_file = new QPushButton(FieldSelectionDialog);
        pushButton_load_default_file->setObjectName(QStringLiteral("pushButton_load_default_file"));

        horizontalLayout_2->addWidget(pushButton_load_default_file);

        pushButton_save_file = new QPushButton(FieldSelectionDialog);
        pushButton_save_file->setObjectName(QStringLiteral("pushButton_save_file"));

        horizontalLayout_2->addWidget(pushButton_save_file);


        verticalLayout->addLayout(horizontalLayout_2);


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
         << QApplication::translate("FieldSelectionDialog", "Camera 1 Transformation", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 2 Transformation", 0)
        );
        imageView->setText(QString());
        pushButton_set->setText(QApplication::translate("FieldSelectionDialog", "Set Masking...", 0));
        pushButton_apply->setText(QApplication::translate("FieldSelectionDialog", "Apply", 0));
        pushButton_ok->setText(QApplication::translate("FieldSelectionDialog", "Ok", 0));
        pushButton_load_file->setText(QApplication::translate("FieldSelectionDialog", "Load from File...", 0));
        pushButton_load_default_file->setText(QApplication::translate("FieldSelectionDialog", "Load from Default File", 0));
        pushButton_save_file->setText(QApplication::translate("FieldSelectionDialog", "Save to File...", 0));
    } // retranslateUi

};

namespace Ui {
    class FieldSelectionDialog: public Ui_FieldSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDSELECTIONDIALOG_H
