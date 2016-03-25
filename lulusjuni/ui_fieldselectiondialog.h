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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FieldSelectionDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *FieldSelectionDialog)
    {
        if (FieldSelectionDialog->objectName().isEmpty())
            FieldSelectionDialog->setObjectName(QStringLiteral("FieldSelectionDialog"));
        FieldSelectionDialog->resize(848, 583);
        verticalLayout_3 = new QVBoxLayout(FieldSelectionDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox = new QComboBox(FieldSelectionDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(FieldSelectionDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(320, 240));
        label->setStyleSheet(QStringLiteral("Background-color: #000;"));
        label->setScaledContents(false);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(FieldSelectionDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(FieldSelectionDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(FieldSelectionDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(FieldSelectionDialog);

        QMetaObject::connectSlotsByName(FieldSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *FieldSelectionDialog)
    {
        FieldSelectionDialog->setWindowTitle(QApplication::translate("FieldSelectionDialog", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("FieldSelectionDialog", "Camera 1", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 2", 0)
         << QApplication::translate("FieldSelectionDialog", "Camera 3", 0)
        );
        label->setText(QString());
        pushButton->setText(QApplication::translate("FieldSelectionDialog", "Set..", 0));
        pushButton_2->setText(QApplication::translate("FieldSelectionDialog", "Apply", 0));
        pushButton_3->setText(QApplication::translate("FieldSelectionDialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class FieldSelectionDialog: public Ui_FieldSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDSELECTIONDIALOG_H
