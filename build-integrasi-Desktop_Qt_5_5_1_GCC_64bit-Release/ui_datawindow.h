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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWindow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_display_data;
    QPushButton *pushButton_load;
    QPushButton *pushButton_save;

    void setupUi(QWidget *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(1107, 758);
        widget = new QWidget(DataWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(330, 530, 325, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_display_data = new QPushButton(widget);
        pushButton_display_data->setObjectName(QStringLiteral("pushButton_display_data"));

        horizontalLayout->addWidget(pushButton_display_data);

        pushButton_load = new QPushButton(widget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout->addWidget(pushButton_load);

        pushButton_save = new QPushButton(widget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);


        retranslateUi(DataWindow);

        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QWidget *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "Form", 0));
        pushButton_display_data->setText(QApplication::translate("DataWindow", "Display Data", 0));
        pushButton_load->setText(QApplication::translate("DataWindow", "Load From File", 0));
        pushButton_save->setText(QApplication::translate("DataWindow", "Save to File", 0));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
