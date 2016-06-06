/********************************************************************************
** Form generated from reading UI file 'pengujiandata.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENGUJIANDATA_H
#define UI_PENGUJIANDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <clickdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_PengujianData
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    ClickDisplay *label_pengujianKiri;
    QLabel *label_coordinate;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PengujianData)
    {
        if (PengujianData->objectName().isEmpty())
            PengujianData->setObjectName(QStringLiteral("PengujianData"));
        PengujianData->resize(665, 657);
        gridLayout = new QGridLayout(PengujianData);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_pengujianKiri = new ClickDisplay(PengujianData);
        label_pengujianKiri->setObjectName(QStringLiteral("label_pengujianKiri"));
        label_pengujianKiri->setMinimumSize(QSize(400, 300));
        label_pengujianKiri->setMaximumSize(QSize(999999, 9999999));
        label_pengujianKiri->setSizeIncrement(QSize(1, 0));
        label_pengujianKiri->setFrameShape(QFrame::Panel);
        label_pengujianKiri->setScaledContents(true);

        horizontalLayout->addWidget(label_pengujianKiri);


        verticalLayout->addLayout(horizontalLayout);

        label_coordinate = new QLabel(PengujianData);
        label_coordinate->setObjectName(QStringLiteral("label_coordinate"));
        label_coordinate->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_coordinate);

        buttonBox = new QDialogButtonBox(PengujianData);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(PengujianData);
        QObject::connect(buttonBox, SIGNAL(accepted()), PengujianData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PengujianData, SLOT(reject()));

        QMetaObject::connectSlotsByName(PengujianData);
    } // setupUi

    void retranslateUi(QDialog *PengujianData)
    {
        PengujianData->setWindowTitle(QApplication::translate("PengujianData", "Dialog", 0));
        label_pengujianKiri->setText(QString());
        label_coordinate->setText(QApplication::translate("PengujianData", "Position", 0));
    } // retranslateUi

};

namespace Ui {
    class PengujianData: public Ui_PengujianData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENGUJIANDATA_H
