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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
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
    QAction *actionData_View;
    QAction *actionFirst_Image_1;
    QAction *actionFirst_Image_2;
    QAction *actionDistortion_Correction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    ClickDisplay *label_stream_1;
    ClickDisplay *label_stream_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QListWidget *listTeamA;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    ClickDisplay *label_game_visual;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QListWidget *listTeamB;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *stautusSetVideoFile;
    QLabel *statusSetParamter;
    QLabel *statusCalibration;
    QLabel *statusSetMask;
    QTextBrowser *logActivity;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_play;
    QPushButton *pushButton_initialize_background_model;
    QPushButton *pushButton_load_default_video;
    QPushButton *pushButton_single_play;
    QPushButton *pushButton_send_id;
    QFrame *line_3;
    QLabel *logo;
    QFrame *line_4;
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
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1198, 683);
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
        actionData_View = new QAction(MainWindow);
        actionData_View->setObjectName(QStringLiteral("actionData_View"));
        actionFirst_Image_1 = new QAction(MainWindow);
        actionFirst_Image_1->setObjectName(QStringLiteral("actionFirst_Image_1"));
        actionFirst_Image_2 = new QAction(MainWindow);
        actionFirst_Image_2->setObjectName(QStringLiteral("actionFirst_Image_2"));
        actionDistortion_Correction = new QAction(MainWindow);
        actionDistortion_Correction->setObjectName(QStringLiteral("actionDistortion_Correction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
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


        verticalLayout_7->addLayout(horizontalLayout_5);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(250, 16777215));

        verticalLayout_5->addWidget(label_2);

        listTeamA = new QListWidget(centralWidget);
        listTeamA->setObjectName(QStringLiteral("listTeamA"));
        listTeamA->setMaximumSize(QSize(250, 16777215));
        listTeamA->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"Tlwg Typist\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(listTeamA);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout_6->addLayout(horizontalLayout_2);

        label_game_visual = new ClickDisplay(centralWidget);
        label_game_visual->setObjectName(QStringLiteral("label_game_visual"));
        label_game_visual->setMinimumSize(QSize(320, 240));
        label_game_visual->setMaximumSize(QSize(480, 320));
        label_game_visual->setStyleSheet(QStringLiteral(""));
        label_game_visual->setScaledContents(false);
        label_game_visual->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_game_visual);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(250, 16777215));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        listTeamB = new QListWidget(centralWidget);
        listTeamB->setObjectName(QStringLiteral("listTeamB"));
        listTeamB->setMaximumSize(QSize(250, 16777215));
        listTeamB->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"Tlwg Typist\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(listTeamB);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_7);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setMaximumSize(QSize(240, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stautusSetVideoFile = new QLabel(groupBox);
        stautusSetVideoFile->setObjectName(QStringLiteral("stautusSetVideoFile"));
        QFont font;
        font.setPointSize(9);
        stautusSetVideoFile->setFont(font);
        stautusSetVideoFile->setScaledContents(true);

        gridLayout_2->addWidget(stautusSetVideoFile, 0, 0, 1, 1);

        statusSetParamter = new QLabel(groupBox);
        statusSetParamter->setObjectName(QStringLiteral("statusSetParamter"));

        gridLayout_2->addWidget(statusSetParamter, 1, 0, 1, 1);

        statusCalibration = new QLabel(groupBox);
        statusCalibration->setObjectName(QStringLiteral("statusCalibration"));

        gridLayout_2->addWidget(statusCalibration, 3, 0, 1, 1);

        statusSetMask = new QLabel(groupBox);
        statusSetMask->setObjectName(QStringLiteral("statusSetMask"));

        gridLayout_2->addWidget(statusSetMask, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        logActivity = new QTextBrowser(groupBox);
        logActivity->setObjectName(QStringLiteral("logActivity"));
        logActivity->setMinimumSize(QSize(0, 100));
        logActivity->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Tlwg Typo\";\n"
"color: rgb(255, 255, 255);"));
        logActivity->setLineWidth(0);

        verticalLayout->addWidget(logActivity);

        verticalSpacer = new QSpacerItem(20, 365, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_play = new QPushButton(groupBox);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(pushButton_play);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(pushButton_play);

        pushButton_initialize_background_model = new QPushButton(groupBox);
        buttonGroup->addButton(pushButton_initialize_background_model);
        pushButton_initialize_background_model->setObjectName(QStringLiteral("pushButton_initialize_background_model"));
        pushButton_initialize_background_model->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(pushButton_initialize_background_model);

        pushButton_load_default_video = new QPushButton(groupBox);
        buttonGroup->addButton(pushButton_load_default_video);
        pushButton_load_default_video->setObjectName(QStringLiteral("pushButton_load_default_video"));
        pushButton_load_default_video->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(pushButton_load_default_video);

        pushButton_single_play = new QPushButton(groupBox);
        buttonGroup->addButton(pushButton_single_play);
        pushButton_single_play->setObjectName(QStringLiteral("pushButton_single_play"));
        pushButton_single_play->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(pushButton_single_play);

        pushButton_send_id = new QPushButton(groupBox);
        buttonGroup->addButton(pushButton_send_id);
        pushButton_send_id->setObjectName(QStringLiteral("pushButton_send_id"));
        pushButton_send_id->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(pushButton_send_id);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        logo = new QLabel(groupBox);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setMaximumSize(QSize(200, 75));
        logo->setScaledContents(true);

        verticalLayout->addWidget(logo);

        splitter->addWidget(groupBox);

        verticalLayout_2->addWidget(splitter);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_current_time = new QLabel(centralWidget);
        label_current_time->setObjectName(QStringLiteral("label_current_time"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_current_time->sizePolicy().hasHeightForWidth());
        label_current_time->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_current_time);

        slider_global_frame = new QSlider(centralWidget);
        slider_global_frame->setObjectName(QStringLiteral("slider_global_frame"));
        slider_global_frame->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider_global_frame);

        label_max_time = new QLabel(centralWidget);
        label_max_time->setObjectName(QStringLiteral("label_max_time"));
        sizePolicy1.setHeightForWidth(label_max_time->sizePolicy().hasHeightForWidth());
        label_max_time->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_max_time);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1198, 17));
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
        menuFile->addAction(actionFirst_Image_1);
        menuFile->addAction(actionFirst_Image_2);
        menuEdit->addAction(actionTuning_Background_Model);
        menuEdit->addAction(actionField_Selection);
        menuEdit->addAction(actionDistortion_Correction);
        menuView->addAction(actionPer_Camera_Raw_View);
        menuView->addAction(actionTracking_View);
        menuView->addAction(actionData_View);
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
        actionData_View->setText(QApplication::translate("MainWindow", "Data View", 0));
        actionFirst_Image_1->setText(QApplication::translate("MainWindow", "First Image 1", 0));
        actionFirst_Image_2->setText(QApplication::translate("MainWindow", "First Image 2", 0));
        actionDistortion_Correction->setText(QApplication::translate("MainWindow", "Distortion Correction", 0));
        label_stream_1->setText(QString());
        label_stream_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Team A", 0));
        label_game_visual->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Team B", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Status", 0));
        stautusSetVideoFile->setText(QApplication::translate("MainWindow", "Set Video File", 0));
        statusSetParamter->setText(QApplication::translate("MainWindow", "Set Object Detection Parameter", 0));
        statusCalibration->setText(QApplication::translate("MainWindow", "Calibration", 0));
        statusSetMask->setText(QApplication::translate("MainWindow", "Set Masking Field", 0));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", 0));
        pushButton_initialize_background_model->setText(QApplication::translate("MainWindow", "Initialize Background Model", 0));
        pushButton_load_default_video->setText(QApplication::translate("MainWindow", "Load Default Video", 0));
        pushButton_single_play->setText(QApplication::translate("MainWindow", "Single Frame Play", 0));
        pushButton_send_id->setText(QApplication::translate("MainWindow", "Send ID", 0));
        logo->setText(QApplication::translate("MainWindow", "logo", 0));
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
