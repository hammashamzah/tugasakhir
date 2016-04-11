/********************************************************************************
** Form generated from reading UI file 'perspectivetransformation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSPECTIVETRANSFORMATION_H
#define UI_PERSPECTIVETRANSFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <matdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_perspectiveTransformation
{
public:
    QDialogButtonBox *buttonBox;
    matDisplay *labelPersTrans;
    QRadioButton *radioButton_P1;
    QRadioButton *radioButton_P2;
    QRadioButton *radioButton_P3;
    QRadioButton *radioButton_P4;

    void setupUi(QDialog *perspectiveTransformation)
    {
        if (perspectiveTransformation->objectName().isEmpty())
            perspectiveTransformation->setObjectName(QStringLiteral("perspectiveTransformation"));
        perspectiveTransformation->resize(640, 480);
        buttonBox = new QDialogButtonBox(perspectiveTransformation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 440, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelPersTrans = new matDisplay(perspectiveTransformation);
        labelPersTrans->setObjectName(QStringLiteral("labelPersTrans"));
        labelPersTrans->setGeometry(QRect(50, 30, 531, 351));
        labelPersTrans->setMouseTracking(true);
        labelPersTrans->setAutoFillBackground(true);
        labelPersTrans->setPixmap(QPixmap(QString::fromUtf8("lapangan.png")));
        labelPersTrans->setScaledContents(true);
        radioButton_P1 = new QRadioButton(perspectiveTransformation);
        radioButton_P1->setObjectName(QStringLiteral("radioButton_P1"));
        radioButton_P1->setGeometry(QRect(40, 410, 100, 22));
        radioButton_P2 = new QRadioButton(perspectiveTransformation);
        radioButton_P2->setObjectName(QStringLiteral("radioButton_P2"));
        radioButton_P2->setGeometry(QRect(170, 410, 100, 22));
        radioButton_P3 = new QRadioButton(perspectiveTransformation);
        radioButton_P3->setObjectName(QStringLiteral("radioButton_P3"));
        radioButton_P3->setGeometry(QRect(40, 440, 100, 22));
        radioButton_P4 = new QRadioButton(perspectiveTransformation);
        radioButton_P4->setObjectName(QStringLiteral("radioButton_P4"));
        radioButton_P4->setGeometry(QRect(170, 440, 100, 22));

        retranslateUi(perspectiveTransformation);
        QObject::connect(buttonBox, SIGNAL(accepted()), perspectiveTransformation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), perspectiveTransformation, SLOT(reject()));

        QMetaObject::connectSlotsByName(perspectiveTransformation);
    } // setupUi

    void retranslateUi(QDialog *perspectiveTransformation)
    {
        perspectiveTransformation->setWindowTitle(QApplication::translate("perspectiveTransformation", "Dialog", 0));
        labelPersTrans->setText(QString());
        radioButton_P1->setText(QApplication::translate("perspectiveTransformation", "P1 (not set)", 0));
        radioButton_P2->setText(QApplication::translate("perspectiveTransformation", "P2 (not set)", 0));
        radioButton_P3->setText(QApplication::translate("perspectiveTransformation", "P3 (not set)", 0));
        radioButton_P4->setText(QApplication::translate("perspectiveTransformation", "P4 (not set)", 0));
    } // retranslateUi

};

namespace Ui {
    class perspectiveTransformation: public Ui_perspectiveTransformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSPECTIVETRANSFORMATION_H
