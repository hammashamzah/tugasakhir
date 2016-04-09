/********************************************************************************
** Form generated from reading UI file 'errorcalculationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORCALCULATIONDIALOG_H
#define UI_ERRORCALCULATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorCalculationDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ErrorCalculationDialog)
    {
        if (ErrorCalculationDialog->objectName().isEmpty())
            ErrorCalculationDialog->setObjectName(QStringLiteral("ErrorCalculationDialog"));
        ErrorCalculationDialog->resize(959, 593);
        horizontalLayout_3 = new QHBoxLayout(ErrorCalculationDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(ErrorCalculationDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(320, 240));
        label->setStyleSheet(QStringLiteral("Background-color: #000;"));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(ErrorCalculationDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ErrorCalculationDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        label_2 = new QLabel(ErrorCalculationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(ErrorCalculationDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(ErrorCalculationDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 176, 54));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        verticalLayout_2->addWidget(groupBox);

        pushButton_3 = new QPushButton(ErrorCalculationDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(ErrorCalculationDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ErrorCalculationDialog);

        QMetaObject::connectSlotsByName(ErrorCalculationDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorCalculationDialog)
    {
        ErrorCalculationDialog->setWindowTitle(QApplication::translate("ErrorCalculationDialog", "Dialog", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("ErrorCalculationDialog", "Next Frame", 0));
        pushButton_2->setText(QApplication::translate("ErrorCalculationDialog", "Previous Frame", 0));
        label_2->setText(QApplication::translate("ErrorCalculationDialog", "Frame Number:", 0));
        lineEdit->setText(QApplication::translate("ErrorCalculationDialog", "0", 0));
        groupBox->setTitle(QApplication::translate("ErrorCalculationDialog", "Tracking Mode", 0));
        radioButton->setText(QApplication::translate("ErrorCalculationDialog", "Single Object Mode", 0));
        radioButton_2->setText(QApplication::translate("ErrorCalculationDialog", "Multiple Object Mode", 0));
        pushButton_3->setText(QApplication::translate("ErrorCalculationDialog", "Save Manual Coordinate to File...", 0));
        pushButton_4->setText(QApplication::translate("ErrorCalculationDialog", "Calculate Error", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorCalculationDialog: public Ui_ErrorCalculationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORCALCULATIONDIALOG_H
