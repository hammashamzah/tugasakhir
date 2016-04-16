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
#include <QtWidgets/QListWidget>
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
#include <clickdisplay.h>

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
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    ClickDisplay *label_stream_1;
    ClickDisplay *label_stream_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listTeamA;
    ClickDisplay *label_game_visual;
    QListWidget *listTeamB;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *idLabel;
    QLabel *playerNameLabel;
    QLabel *playerSpeedLabel;
    QLabel *positionLabel;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_play;
    QPushButton *pushButton_single_play;
    QPushButton *pushButton_send_id;
    QPushButton *pushButton_initialize_object;
    QHBoxLayout *horizontalLayout;
    QLabel *label_current_time;
    QSlider *slider_global_frame;
    QLabel *label_max_time;
    QMenuBar *menuBar;
    QMenu *menuFile;
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
        MainWindow->resize(1132, 652);
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
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_stream_1 = new ClickDisplay(centralWidget);
        label_stream_1->setObjectName(QStringLiteral("label_stream_1"));
        label_stream_1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_stream_1->sizePolicy().hasHeightForWidth());
        label_stream_1->setSizePolicy(sizePolicy);
        label_stream_1->setMinimumSize(QSize(480, 320));
        label_stream_1->setStyleSheet(QStringLiteral("Background-color: #000;"));

        horizontalLayout_5->addWidget(label_stream_1);

        label_stream_2 = new ClickDisplay(centralWidget);
        label_stream_2->setObjectName(QStringLiteral("label_stream_2"));
        sizePolicy.setHeightForWidth(label_stream_2->sizePolicy().hasHeightForWidth());
        label_stream_2->setSizePolicy(sizePolicy);
        label_stream_2->setMinimumSize(QSize(480, 320));
        label_stream_2->setStyleSheet(QStringLiteral("Background-color: #000;"));

        horizontalLayout_5->addWidget(label_stream_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listTeamA = new QListWidget(centralWidget);
        listTeamA->setObjectName(QStringLiteral("listTeamA"));

        horizontalLayout_2->addWidget(listTeamA);

        label_game_visual = new ClickDisplay(centralWidget);
        label_game_visual->setObjectName(QStringLiteral("label_game_visual"));
        label_game_visual->setMinimumSize(QSize(320, 240));
        label_game_visual->setMaximumSize(QSize(480, 320));
        label_game_visual->setStyleSheet(QStringLiteral("Background-color: #000;"));
        label_game_visual->setScaledContents(true);

        horizontalLayout_2->addWidget(label_game_visual);

        listTeamB = new QListWidget(centralWidget);
        listTeamB->setObjectName(QStringLiteral("listTeamB"));

        horizontalLayout_2->addWidget(listTeamB);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(120, 0));
        groupBox->setMaximumSize(QSize(240, 16777215));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 141, 381));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        idLabel = new QLabel(layoutWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        QFont font;
        font.setPointSize(9);
        idLabel->setFont(font);

        gridLayout_2->addWidget(idLabel, 0, 0, 1, 1);

        playerNameLabel = new QLabel(layoutWidget);
        playerNameLabel->setObjectName(QStringLiteral("playerNameLabel"));

        gridLayout_2->addWidget(playerNameLabel, 1, 0, 1, 1);

        playerSpeedLabel = new QLabel(layoutWidget);
        playerSpeedLabel->setObjectName(QStringLiteral("playerSpeedLabel"));

        gridLayout_2->addWidget(playerSpeedLabel, 2, 0, 1, 1);

        positionLabel = new QLabel(layoutWidget);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));

        gridLayout_2->addWidget(positionLabel, 3, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));

        verticalLayout->addWidget(pushButton_play);

        pushButton_single_play = new QPushButton(layoutWidget);
        pushButton_single_play->setObjectName(QStringLiteral("pushButton_single_play"));

        verticalLayout->addWidget(pushButton_single_play);

        pushButton_send_id = new QPushButton(layoutWidget);
        pushButton_send_id->setObjectName(QStringLiteral("pushButton_send_id"));

        verticalLayout->addWidget(pushButton_send_id);

        pushButton_initialize_object = new QPushButton(layoutWidget);
        pushButton_initialize_object->setObjectName(QStringLiteral("pushButton_initialize_object"));

        verticalLayout->addWidget(pushButton_initialize_object);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_current_time = new QLabel(layoutWidget);
        label_current_time->setObjectName(QStringLiteral("label_current_time"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_current_time->sizePolicy().hasHeightForWidth());
        label_current_time->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_current_time);

        slider_global_frame = new QSlider(layoutWidget);
        slider_global_frame->setObjectName(QStringLiteral("slider_global_frame"));
        slider_global_frame->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider_global_frame);

        label_max_time = new QLabel(layoutWidget);
        label_max_time->setObjectName(QStringLiteral("label_max_time"));
        sizePolicy1.setHeightForWidth(label_max_time->sizePolicy().hasHeightForWidth());
        label_max_time->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_max_time);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        splitter->addWidget(groupBox);

        verticalLayout_2->addWidget(splitter);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1132, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
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
        menuFile->addAction(actionVideo_1);
        menuFile->addAction(actionVideo_2);
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
        label_stream_1->setText(QString());
        label_stream_2->setText(QString());
        label_game_visual->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Player Performance", 0));
        idLabel->setText(QApplication::translate("MainWindow", "ID", 0));
        playerNameLabel->setText(QApplication::translate("MainWindow", "Player Name", 0));
        playerSpeedLabel->setText(QApplication::translate("MainWindow", "Player Speed", 0));
        positionLabel->setText(QApplication::translate("MainWindow", "Position", 0));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", 0));
        pushButton_single_play->setText(QApplication::translate("MainWindow", "Single Frame Play", 0));
        pushButton_send_id->setText(QApplication::translate("MainWindow", "Send ID", 0));
        pushButton_initialize_object->setText(QApplication::translate("MainWindow", "Initialize Object", 0));
        label_current_time->setText(QApplication::translate("MainWindow", "00:00", 0));
        label_max_time->setText(QApplication::translate("MainWindow", "00:00", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
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
