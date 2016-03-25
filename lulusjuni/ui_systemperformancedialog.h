/********************************************************************************
** Form generated from reading UI file 'systemperformancedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMPERFORMANCEDIALOG_H
#define UI_SYSTEMPERFORMANCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SystemPerformanceDialog
{
public:

    void setupUi(QDialog *SystemPerformanceDialog)
    {
        if (SystemPerformanceDialog->objectName().isEmpty())
            SystemPerformanceDialog->setObjectName(QStringLiteral("SystemPerformanceDialog"));
        SystemPerformanceDialog->resize(400, 300);

        retranslateUi(SystemPerformanceDialog);

        QMetaObject::connectSlotsByName(SystemPerformanceDialog);
    } // setupUi

    void retranslateUi(QDialog *SystemPerformanceDialog)
    {
        SystemPerformanceDialog->setWindowTitle(QApplication::translate("SystemPerformanceDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemPerformanceDialog: public Ui_SystemPerformanceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMPERFORMANCEDIALOG_H
