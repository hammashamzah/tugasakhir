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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "freezetablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_DataWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    FreezeTableWidget *tableView_result;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_reconstruct;
    QPushButton *pushButton_cut;
    QPushButton *pushButton_paste;
    QPushButton *pushButton_refresh;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_save_raw;
    QPushButton *pushButton_load_raw;
    QPushButton *pushButton_display_data;
    QPushButton *pushButton_load;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *headerPlayBack;
    QLabel *label_teamNameA;
    QLabel *label_playback_time;
    QLabel *label_teamNameB;
    QLabel *label_playbackVisual;
    QVBoxLayout *playBackControlButton;
    QSlider *slider_playback;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_playbackSingleFrame;
    QPushButton *pushButton_playbackStart;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_summaryTeamA;
    QGroupBox *groupBox_summaryTeamB;
    QWidget *tab_3;

    void setupUi(QWidget *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(1051, 562);
        gridLayout = new QGridLayout(DataWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(DataWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView_result = new FreezeTableWidget(tab);
        tableView_result->setObjectName(QStringLiteral("tableView_result"));

        verticalLayout_3->addWidget(tableView_result);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_reconstruct = new QPushButton(tab);
        pushButton_reconstruct->setObjectName(QStringLiteral("pushButton_reconstruct"));

        horizontalLayout_2->addWidget(pushButton_reconstruct);

        pushButton_cut = new QPushButton(tab);
        pushButton_cut->setObjectName(QStringLiteral("pushButton_cut"));

        horizontalLayout_2->addWidget(pushButton_cut);

        pushButton_paste = new QPushButton(tab);
        pushButton_paste->setObjectName(QStringLiteral("pushButton_paste"));

        horizontalLayout_2->addWidget(pushButton_paste);

        pushButton_refresh = new QPushButton(tab);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));

        horizontalLayout_2->addWidget(pushButton_refresh);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_save = new QPushButton(tab);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);

        pushButton_save_raw = new QPushButton(tab);
        pushButton_save_raw->setObjectName(QStringLiteral("pushButton_save_raw"));

        horizontalLayout->addWidget(pushButton_save_raw);

        pushButton_load_raw = new QPushButton(tab);
        pushButton_load_raw->setObjectName(QStringLiteral("pushButton_load_raw"));

        horizontalLayout->addWidget(pushButton_load_raw);

        pushButton_display_data = new QPushButton(tab);
        pushButton_display_data->setObjectName(QStringLiteral("pushButton_display_data"));

        horizontalLayout->addWidget(pushButton_display_data);

        pushButton_load = new QPushButton(tab);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout->addWidget(pushButton_load);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        headerPlayBack = new QHBoxLayout();
        headerPlayBack->setObjectName(QStringLiteral("headerPlayBack"));
        label_teamNameA = new QLabel(tab_2);
        label_teamNameA->setObjectName(QStringLiteral("label_teamNameA"));
        label_teamNameA->setMaximumSize(QSize(200, 20));
        label_teamNameA->setFrameShape(QFrame::Panel);

        headerPlayBack->addWidget(label_teamNameA);

        label_playback_time = new QLabel(tab_2);
        label_playback_time->setObjectName(QStringLiteral("label_playback_time"));
        label_playback_time->setMaximumSize(QSize(16777215, 20));
        label_playback_time->setFrameShape(QFrame::StyledPanel);
        label_playback_time->setAlignment(Qt::AlignCenter);

        headerPlayBack->addWidget(label_playback_time);

        label_teamNameB = new QLabel(tab_2);
        label_teamNameB->setObjectName(QStringLiteral("label_teamNameB"));
        label_teamNameB->setMaximumSize(QSize(200, 20));
        label_teamNameB->setFrameShape(QFrame::Panel);
        label_teamNameB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        headerPlayBack->addWidget(label_teamNameB);


        verticalLayout_4->addLayout(headerPlayBack);

        label_playbackVisual = new QLabel(tab_2);
        label_playbackVisual->setObjectName(QStringLiteral("label_playbackVisual"));
        label_playbackVisual->setMinimumSize(QSize(500, 400));
        label_playbackVisual->setFrameShape(QFrame::Box);
        label_playbackVisual->setScaledContents(true);

        verticalLayout_4->addWidget(label_playbackVisual);

        playBackControlButton = new QVBoxLayout();
        playBackControlButton->setObjectName(QStringLiteral("playBackControlButton"));
        slider_playback = new QSlider(tab_2);
        slider_playback->setObjectName(QStringLiteral("slider_playback"));
        slider_playback->setOrientation(Qt::Horizontal);

        playBackControlButton->addWidget(slider_playback);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_playbackSingleFrame = new QPushButton(tab_2);
        pushButton_playbackSingleFrame->setObjectName(QStringLiteral("pushButton_playbackSingleFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_playbackSingleFrame->sizePolicy().hasHeightForWidth());
        pushButton_playbackSingleFrame->setSizePolicy(sizePolicy);
        pushButton_playbackSingleFrame->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_3->addWidget(pushButton_playbackSingleFrame);

        pushButton_playbackStart = new QPushButton(tab_2);
        pushButton_playbackStart->setObjectName(QStringLiteral("pushButton_playbackStart"));

        horizontalLayout_3->addWidget(pushButton_playbackStart);


        playBackControlButton->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(playBackControlButton);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_summaryTeamA = new QGroupBox(tab_2);
        groupBox_summaryTeamA->setObjectName(QStringLiteral("groupBox_summaryTeamA"));
        groupBox_summaryTeamA->setMinimumSize(QSize(240, 240));
        groupBox_summaryTeamA->setMaximumSize(QSize(240, 16777215));

        verticalLayout_6->addWidget(groupBox_summaryTeamA);

        groupBox_summaryTeamB = new QGroupBox(tab_2);
        groupBox_summaryTeamB->setObjectName(QStringLiteral("groupBox_summaryTeamB"));
        groupBox_summaryTeamB->setMinimumSize(QSize(240, 240));
        groupBox_summaryTeamB->setMaximumSize(QSize(240, 16777215));

        verticalLayout_6->addWidget(groupBox_summaryTeamB);


        horizontalLayout_4->addLayout(verticalLayout_6);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(DataWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QWidget *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "Form", 0));
        pushButton_reconstruct->setText(QApplication::translate("DataWindow", "Reconstruct Miss Data", 0));
        pushButton_cut->setText(QApplication::translate("DataWindow", "Cut", 0));
        pushButton_paste->setText(QApplication::translate("DataWindow", "Paste", 0));
        pushButton_refresh->setText(QApplication::translate("DataWindow", "Refresh", 0));
        pushButton_save->setText(QApplication::translate("DataWindow", "Save to File", 0));
        pushButton_save_raw->setText(QApplication::translate("DataWindow", "Save Raw to File", 0));
        pushButton_load_raw->setText(QApplication::translate("DataWindow", "Load Raw from File", 0));
        pushButton_display_data->setText(QApplication::translate("DataWindow", "Display Data", 0));
        pushButton_load->setText(QApplication::translate("DataWindow", "Load From File", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DataWindow", "Game Log Data", 0));
        label_teamNameA->setText(QApplication::translate("DataWindow", "Team A", 0));
        label_playback_time->setText(QApplication::translate("DataWindow", "Time", 0));
        label_teamNameB->setText(QApplication::translate("DataWindow", "Team B", 0));
        label_playbackVisual->setText(QApplication::translate("DataWindow", "TextLabel", 0));
        pushButton_playbackSingleFrame->setText(QApplication::translate("DataWindow", "Play Single Frame", 0));
        pushButton_playbackStart->setText(QApplication::translate("DataWindow", "Play", 0));
        groupBox_summaryTeamA->setTitle(QApplication::translate("DataWindow", "Summary Team A", 0));
        groupBox_summaryTeamB->setTitle(QApplication::translate("DataWindow", "Summary Team B", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DataWindow", "Visual Log Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("DataWindow", "Game Summary", 0));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
