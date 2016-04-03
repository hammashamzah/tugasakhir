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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <matdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionVideo_1;
    QAction *actionVideo_2;
    QAction *actionVideo_3;
    QAction *actionTuning_Background_Model;
    QAction *actionError_Calculation;
    QAction *actionSystem_Performance_Testing_Metrics;
    QAction *actionPer_Camera_Raw_View;
    QAction *actionField_Selection;
    QAction *actionTracking_View;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    matDisplay *label_game_visual;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_play;
    QHBoxLayout *horizontalLayout;
    QLabel *current_time_1;
    QLabel *max_time_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *current_time_2;
    QSlider *time_slider_2;
    QLabel *max_time_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *current_time_3;
    QSlider *time_slider_3;
    QSlider *time_slider_1;
    QLabel *max_time_3;
    QLabel *label_videostream_1;
    QLabel *label_videostream_2;
    QLabel *label_videostream_3;
    QLabel *label_formationTeamA;
    QLabel *label_formationTeamB;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_6;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuLoad_Video;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuPerformance;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(919, 576);
        MainWindow->setAutoFillBackground(false);
        actionVideo_1 = new QAction(MainWindow);
        actionVideo_1->setObjectName(QStringLiteral("actionVideo_1"));
        actionVideo_2 = new QAction(MainWindow);
        actionVideo_2->setObjectName(QStringLiteral("actionVideo_2"));
        actionVideo_3 = new QAction(MainWindow);
        actionVideo_3->setObjectName(QStringLiteral("actionVideo_3"));
        actionTuning_Background_Model = new QAction(MainWindow);
        actionTuning_Background_Model->setObjectName(QStringLiteral("actionTuning_Background_Model"));
        actionError_Calculation = new QAction(MainWindow);
        actionError_Calculation->setObjectName(QStringLiteral("actionError_Calculation"));
        actionSystem_Performance_Testing_Metrics = new QAction(MainWindow);
        actionSystem_Performance_Testing_Metrics->setObjectName(QStringLiteral("actionSystem_Performance_Testing_Metrics"));
        actionPer_Camera_Raw_View = new QAction(MainWindow);
        actionPer_Camera_Raw_View->setObjectName(QStringLiteral("actionPer_Camera_Raw_View"));
        actionField_Selection = new QAction(MainWindow);
        actionField_Selection->setObjectName(QStringLiteral("actionField_Selection"));
        actionTracking_View = new QAction(MainWindow);
        actionTracking_View->setObjectName(QStringLiteral("actionTracking_View"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_game_visual = new matDisplay(centralWidget);
        label_game_visual->setObjectName(QStringLiteral("label_game_visual"));
        label_game_visual->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_game_visual->sizePolicy().hasHeightForWidth());
        label_game_visual->setSizePolicy(sizePolicy);
        label_game_visual->setStyleSheet(QStringLiteral("Background-color: #000;"));
        label_game_visual->setScaledContents(true);

        verticalLayout_3->addWidget(label_game_visual);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));

        verticalLayout->addWidget(pushButton_play);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        current_time_1 = new QLabel(centralWidget);
        current_time_1->setObjectName(QStringLiteral("current_time_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(current_time_1->sizePolicy().hasHeightForWidth());
        current_time_1->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(current_time_1);

        max_time_1 = new QLabel(centralWidget);
        max_time_1->setObjectName(QStringLiteral("max_time_1"));
        sizePolicy1.setHeightForWidth(max_time_1->sizePolicy().hasHeightForWidth());
        max_time_1->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(max_time_1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        current_time_2 = new QLabel(centralWidget);
        current_time_2->setObjectName(QStringLiteral("current_time_2"));
        sizePolicy1.setHeightForWidth(current_time_2->sizePolicy().hasHeightForWidth());
        current_time_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(current_time_2);

        time_slider_2 = new QSlider(centralWidget);
        time_slider_2->setObjectName(QStringLiteral("time_slider_2"));
        time_slider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(time_slider_2);

        max_time_2 = new QLabel(centralWidget);
        max_time_2->setObjectName(QStringLiteral("max_time_2"));
        sizePolicy1.setHeightForWidth(max_time_2->sizePolicy().hasHeightForWidth());
        max_time_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(max_time_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        current_time_3 = new QLabel(centralWidget);
        current_time_3->setObjectName(QStringLiteral("current_time_3"));
        sizePolicy1.setHeightForWidth(current_time_3->sizePolicy().hasHeightForWidth());
        current_time_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(current_time_3);

        time_slider_3 = new QSlider(centralWidget);
        time_slider_3->setObjectName(QStringLiteral("time_slider_3"));
        time_slider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(time_slider_3);

        time_slider_1 = new QSlider(centralWidget);
        time_slider_1->setObjectName(QStringLiteral("time_slider_1"));
        time_slider_1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(time_slider_1);

        max_time_3 = new QLabel(centralWidget);
        max_time_3->setObjectName(QStringLiteral("max_time_3"));
        sizePolicy1.setHeightForWidth(max_time_3->sizePolicy().hasHeightForWidth());
        max_time_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(max_time_3);


        verticalLayout->addLayout(horizontalLayout_3);

        label_videostream_1 = new QLabel(centralWidget);
        label_videostream_1->setObjectName(QStringLiteral("label_videostream_1"));
        sizePolicy1.setHeightForWidth(label_videostream_1->sizePolicy().hasHeightForWidth());
        label_videostream_1->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_videostream_1);

        label_videostream_2 = new QLabel(centralWidget);
        label_videostream_2->setObjectName(QStringLiteral("label_videostream_2"));
        sizePolicy1.setHeightForWidth(label_videostream_2->sizePolicy().hasHeightForWidth());
        label_videostream_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_videostream_2);

        label_videostream_3 = new QLabel(centralWidget);
        label_videostream_3->setObjectName(QStringLiteral("label_videostream_3"));
        sizePolicy1.setHeightForWidth(label_videostream_3->sizePolicy().hasHeightForWidth());
        label_videostream_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_videostream_3);


        horizontalLayout_4->addLayout(verticalLayout);

        label_formationTeamA = new QLabel(centralWidget);
        label_formationTeamA->setObjectName(QStringLiteral("label_formationTeamA"));

        horizontalLayout_4->addWidget(label_formationTeamA);

        label_formationTeamB = new QLabel(centralWidget);
        label_formationTeamB->setObjectName(QStringLiteral("label_formationTeamB"));
        label_formationTeamB->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(label_formationTeamB);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 59, 15));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 121, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 70, 121, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 59, 15));
        splitter->addWidget(groupBox);

        verticalLayout_2->addWidget(splitter);


        horizontalLayout_5->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuLoad_Video = new QMenu(menuFile);
        menuLoad_Video->setObjectName(QStringLiteral("menuLoad_Video"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuPerformance = new QMenu(menuBar);
        menuPerformance->setObjectName(QStringLiteral("menuPerformance"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuPerformance->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(menuLoad_Video->menuAction());
        menuLoad_Video->addAction(actionVideo_1);
        menuLoad_Video->addAction(actionVideo_2);
        menuLoad_Video->addAction(actionVideo_3);
        menuEdit->addAction(actionTuning_Background_Model);
        menuEdit->addAction(actionField_Selection);
        menuView->addAction(actionPer_Camera_Raw_View);
        menuView->addAction(actionTracking_View);
        menuPerformance->addAction(actionError_Calculation);
        menuPerformance->addAction(actionSystem_Performance_Testing_Metrics);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionVideo_1->setText(QApplication::translate("MainWindow", "Video 1", 0));
        actionVideo_2->setText(QApplication::translate("MainWindow", "Video 2", 0));
        actionVideo_3->setText(QApplication::translate("MainWindow", "Video 3", 0));
        actionTuning_Background_Model->setText(QApplication::translate("MainWindow", "Tuning Background Model", 0));
        actionError_Calculation->setText(QApplication::translate("MainWindow", "Error Calculation", 0));
        actionSystem_Performance_Testing_Metrics->setText(QApplication::translate("MainWindow", "System Performance Testing/Metrics", 0));
        actionPer_Camera_Raw_View->setText(QApplication::translate("MainWindow", "Per Camera Raw View", 0));
        actionField_Selection->setText(QApplication::translate("MainWindow", "Field Selection", 0));
        actionTracking_View->setText(QApplication::translate("MainWindow", "Tracking View", 0));
        label_game_visual->setText(QString());
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", 0));
        current_time_1->setText(QApplication::translate("MainWindow", "00:00", 0));
        max_time_1->setText(QApplication::translate("MainWindow", "00:00", 0));
        current_time_2->setText(QApplication::translate("MainWindow", "00:00", 0));
        max_time_2->setText(QApplication::translate("MainWindow", "00:00", 0));
        current_time_3->setText(QApplication::translate("MainWindow", "00:00", 0));
        max_time_3->setText(QApplication::translate("MainWindow", "00:00", 0));
        label_videostream_1->setText(QApplication::translate("MainWindow", "Video Stream 1: Unknown", 0));
        label_videostream_2->setText(QApplication::translate("MainWindow", "Video Stream 2: Unknown", 0));
        label_videostream_3->setText(QApplication::translate("MainWindow", "Video Stream 3: Unknown", 0));
        label_formationTeamA->setText(QApplication::translate("MainWindow", "FormationTeamA", 0));
        label_formationTeamB->setText(QApplication::translate("MainWindow", "FormationTeamB", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Player Performance", 0));
        label_2->setText(QApplication::translate("MainWindow", "ID", 0));
        label_3->setText(QApplication::translate("MainWindow", "Player Name", 0));
        label_4->setText(QApplication::translate("MainWindow", "Player Speed", 0));
        label_5->setText(QApplication::translate("MainWindow", "Position", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuLoad_Video->setTitle(QApplication::translate("MainWindow", "Load Video", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuPerformance->setTitle(QApplication::translate("MainWindow", "Performance", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
