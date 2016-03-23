/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <matdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    matDisplay *Mat_Display;
    QLabel *mouse_position_label;
    QLabel *label;
    QRadioButton *radioButton_P1;
    QRadioButton *radioButton_P2;
    QRadioButton *radioButton_P3;
    QRadioButton *radioButton_P4;
    QLabel *label_transformed;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_generateTransMat;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(760, 656);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Mat_Display = new matDisplay(centralWidget);
        Mat_Display->setObjectName(QStringLiteral("Mat_Display"));
        Mat_Display->setGeometry(QRect(20, 20, 551, 261));
        Mat_Display->setMaximumSize(QSize(10000, 100000));
        Mat_Display->setStyleSheet(QStringLiteral("background-color: rgb(234, 120, 120);"));
        Mat_Display->setScaledContents(true);
        mouse_position_label = new QLabel(centralWidget);
        mouse_position_label->setObjectName(QStringLiteral("mouse_position_label"));
        mouse_position_label->setGeometry(QRect(20, 290, 121, 16));
        mouse_position_label->setStyleSheet(QLatin1String("background-color: rgb(72, 63, 63);\n"
"background-color: rgb(231, 236, 227);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 70, 59, 15));
        radioButton_P1 = new QRadioButton(centralWidget);
        radioButton_P1->setObjectName(QStringLiteral("radioButton_P1"));
        radioButton_P1->setGeometry(QRect(580, 100, 104, 20));
        radioButton_P2 = new QRadioButton(centralWidget);
        radioButton_P2->setObjectName(QStringLiteral("radioButton_P2"));
        radioButton_P2->setGeometry(QRect(580, 120, 104, 20));
        radioButton_P3 = new QRadioButton(centralWidget);
        radioButton_P3->setObjectName(QStringLiteral("radioButton_P3"));
        radioButton_P3->setGeometry(QRect(580, 140, 104, 20));
        radioButton_P4 = new QRadioButton(centralWidget);
        radioButton_P4->setObjectName(QStringLiteral("radioButton_P4"));
        radioButton_P4->setGeometry(QRect(580, 160, 104, 20));
        label_transformed = new QLabel(centralWidget);
        label_transformed->setObjectName(QStringLiteral("label_transformed"));
        label_transformed->setGeometry(QRect(30, 310, 401, 281));
        label_transformed->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_transformed->setScaledContents(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 0, 59, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 0, 111, 16));
        pushButton_generateTransMat = new QPushButton(centralWidget);
        pushButton_generateTransMat->setObjectName(QStringLiteral("pushButton_generateTransMat"));
        pushButton_generateTransMat->setGeometry(QRect(580, 200, 111, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 30, 89, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Mat_Display->setText(QString());
        mouse_position_label->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Set Point", 0));
        radioButton_P1->setText(QApplication::translate("MainWindow", "P1 (Not set)", 0));
        radioButton_P2->setText(QApplication::translate("MainWindow", "P2 (Not set)", 0));
        radioButton_P3->setText(QApplication::translate("MainWindow", "P3 (Not Set)", 0));
        radioButton_P4->setText(QApplication::translate("MainWindow", "P4 (Not set)", 0));
        label_transformed->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Source", 0));
        label_4->setText(QApplication::translate("MainWindow", "Transformed", 0));
        pushButton_generateTransMat->setText(QApplication::translate("MainWindow", "Generate Matrix", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
