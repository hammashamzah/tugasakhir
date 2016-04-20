/********************************************************************************
** Form generated from reading UI file 'datawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWINDOW_H
#define UI_DATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_DataWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    FreezeTableWidget *tableView_result;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_cut;
    QPushButton *pushButton_paste;
    QPushButton *pushButton_refresh;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_display_data;
    QPushButton *pushButton_load;

    void setupUi(QWidget *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(468, 439);
        gridLayout = new QGridLayout(DataWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView_result = new FreezeTableWidget(DataWindow);
        tableView_result->setObjectName(QStringLiteral("tableView_result"));

        verticalLayout_2->addWidget(tableView_result);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_cut = new QPushButton(DataWindow);
        pushButton_cut->setObjectName(QStringLiteral("pushButton_cut"));

        horizontalLayout_2->addWidget(pushButton_cut);

        pushButton_paste = new QPushButton(DataWindow);
        pushButton_paste->setObjectName(QStringLiteral("pushButton_paste"));

        horizontalLayout_2->addWidget(pushButton_paste);

        pushButton_refresh = new QPushButton(DataWindow);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));

        horizontalLayout_2->addWidget(pushButton_refresh);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_save = new QPushButton(DataWindow);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        pushButton_display_data = new QPushButton(DataWindow);
        pushButton_display_data->setObjectName(QStringLiteral("pushButton_display_data"));

        horizontalLayout->addWidget(pushButton_display_data);

        pushButton_load = new QPushButton(DataWindow);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout->addWidget(pushButton_load);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(DataWindow);

        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QWidget *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "Form", 0));
        pushButton_cut->setText(QApplication::translate("DataWindow", "Cut", 0));
        pushButton_paste->setText(QApplication::translate("DataWindow", "Paste", 0));
        pushButton_refresh->setText(QApplication::translate("DataWindow", "Refresh", 0));
        pushButton_save->setText(QApplication::translate("DataWindow", "Save to File", 0));
        pushButton_display_data->setText(QApplication::translate("DataWindow", "Display Data", 0));
        pushButton_load->setText(QApplication::translate("DataWindow", "Load From File", 0));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
