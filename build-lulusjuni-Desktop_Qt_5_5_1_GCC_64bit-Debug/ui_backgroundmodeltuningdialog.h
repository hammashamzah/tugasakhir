/********************************************************************************
** Form generated from reading UI file 'backgroundmodeltuningdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDMODELTUNINGDIALOG_H
#define UI_BACKGROUNDMODELTUNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BackgroundModelTuningDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSlider *slider_min_area_1;
    QLabel *label_7;
    QCheckBox *checkBox_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSlider *slider_max_area_1;
    QLabel *label_9;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QSlider *slider_morp_element_size_1;
    QLabel *label_11;
    QCheckBox *checkBox;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QSlider *slider_gaussian_size_1;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_82;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_83;
    QSlider *slider_min_area_2;
    QLabel *label_84;
    QCheckBox *checkBox_8;
    QLabel *label_85;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_86;
    QSlider *slider_max_area_2;
    QLabel *label_87;
    QCheckBox *checkBox_9;
    QLabel *label_88;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_89;
    QSlider *slider_morp_element_size_2;
    QLabel *label_90;
    QCheckBox *checkBox_10;
    QLabel *label_93;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_94;
    QSlider *slider_gaussian_size_2;
    QLabel *label_95;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_91;
    QLabel *label_92;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *pushButton_load;
    QPushButton *pushButton_save;
    QHBoxLayout *horizontalLayout_34;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BackgroundModelTuningDialog)
    {
        if (BackgroundModelTuningDialog->objectName().isEmpty())
            BackgroundModelTuningDialog->setObjectName(QStringLiteral("BackgroundModelTuningDialog"));
        BackgroundModelTuningDialog->resize(626, 424);
        verticalLayout = new QVBoxLayout(BackgroundModelTuningDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(BackgroundModelTuningDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(300, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 10));

        verticalLayout_4->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        slider_min_area_1 = new QSlider(groupBox);
        slider_min_area_1->setObjectName(QStringLiteral("slider_min_area_1"));
        sizePolicy1.setHeightForWidth(slider_min_area_1->sizePolicy().hasHeightForWidth());
        slider_min_area_1->setSizePolicy(sizePolicy1);
        slider_min_area_1->setMaximum(300);
        slider_min_area_1->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slider_min_area_1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);


        verticalLayout_4->addLayout(horizontalLayout_2);

        checkBox_7 = new QCheckBox(groupBox);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        verticalLayout_4->addWidget(checkBox_7);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 10));

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        slider_max_area_1 = new QSlider(groupBox);
        slider_max_area_1->setObjectName(QStringLiteral("slider_max_area_1"));
        sizePolicy1.setHeightForWidth(slider_max_area_1->sizePolicy().hasHeightForWidth());
        slider_max_area_1->setSizePolicy(sizePolicy1);
        slider_max_area_1->setMinimum(100);
        slider_max_area_1->setMaximum(1000);
        slider_max_area_1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slider_max_area_1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);


        verticalLayout_4->addLayout(horizontalLayout_3);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_4->addWidget(checkBox_2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 10));

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        slider_morp_element_size_1 = new QSlider(groupBox);
        slider_morp_element_size_1->setObjectName(QStringLiteral("slider_morp_element_size_1"));
        sizePolicy1.setHeightForWidth(slider_morp_element_size_1->sizePolicy().hasHeightForWidth());
        slider_morp_element_size_1->setSizePolicy(sizePolicy1);
        slider_morp_element_size_1->setMinimum(3);
        slider_morp_element_size_1->setMaximum(11);
        slider_morp_element_size_1->setSingleStep(2);
        slider_morp_element_size_1->setPageStep(2);
        slider_morp_element_size_1->setOrientation(Qt::Horizontal);
        slider_morp_element_size_1->setInvertedAppearance(false);
        slider_morp_element_size_1->setInvertedControls(false);
        slider_morp_element_size_1->setTickPosition(QSlider::TicksBelow);
        slider_morp_element_size_1->setTickInterval(2);

        horizontalLayout_4->addWidget(slider_morp_element_size_1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);


        verticalLayout_4->addLayout(horizontalLayout_4);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(0, 10));

        verticalLayout_4->addWidget(label_14);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        slider_gaussian_size_1 = new QSlider(groupBox);
        slider_gaussian_size_1->setObjectName(QStringLiteral("slider_gaussian_size_1"));
        sizePolicy1.setHeightForWidth(slider_gaussian_size_1->sizePolicy().hasHeightForWidth());
        slider_gaussian_size_1->setSizePolicy(sizePolicy1);
        slider_gaussian_size_1->setMinimum(3);
        slider_gaussian_size_1->setMaximum(15);
        slider_gaussian_size_1->setOrientation(Qt::Horizontal);
        slider_gaussian_size_1->setTickPosition(QSlider::TicksBelow);
        slider_gaussian_size_1->setTickInterval(1);

        horizontalLayout_5->addWidget(slider_gaussian_size_1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));

        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BackgroundModelTuningDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(300, 0));
        verticalLayout_16 = new QVBoxLayout(groupBox_2);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_82 = new QLabel(groupBox_2);
        label_82->setObjectName(QStringLiteral("label_82"));
        sizePolicy1.setHeightForWidth(label_82->sizePolicy().hasHeightForWidth());
        label_82->setSizePolicy(sizePolicy1);
        label_82->setMinimumSize(QSize(0, 10));

        verticalLayout_17->addWidget(label_82);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        label_83 = new QLabel(groupBox_2);
        label_83->setObjectName(QStringLiteral("label_83"));

        horizontalLayout_35->addWidget(label_83);

        slider_min_area_2 = new QSlider(groupBox_2);
        slider_min_area_2->setObjectName(QStringLiteral("slider_min_area_2"));
        sizePolicy1.setHeightForWidth(slider_min_area_2->sizePolicy().hasHeightForWidth());
        slider_min_area_2->setSizePolicy(sizePolicy1);
        slider_min_area_2->setMaximum(300);
        slider_min_area_2->setOrientation(Qt::Horizontal);

        horizontalLayout_35->addWidget(slider_min_area_2);

        label_84 = new QLabel(groupBox_2);
        label_84->setObjectName(QStringLiteral("label_84"));

        horizontalLayout_35->addWidget(label_84);


        verticalLayout_17->addLayout(horizontalLayout_35);

        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        verticalLayout_17->addWidget(checkBox_8);

        label_85 = new QLabel(groupBox_2);
        label_85->setObjectName(QStringLiteral("label_85"));
        sizePolicy1.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy1);
        label_85->setMinimumSize(QSize(0, 10));

        verticalLayout_17->addWidget(label_85);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        label_86 = new QLabel(groupBox_2);
        label_86->setObjectName(QStringLiteral("label_86"));

        horizontalLayout_36->addWidget(label_86);

        slider_max_area_2 = new QSlider(groupBox_2);
        slider_max_area_2->setObjectName(QStringLiteral("slider_max_area_2"));
        sizePolicy1.setHeightForWidth(slider_max_area_2->sizePolicy().hasHeightForWidth());
        slider_max_area_2->setSizePolicy(sizePolicy1);
        slider_max_area_2->setMinimum(100);
        slider_max_area_2->setMaximum(1000);
        slider_max_area_2->setOrientation(Qt::Horizontal);

        horizontalLayout_36->addWidget(slider_max_area_2);

        label_87 = new QLabel(groupBox_2);
        label_87->setObjectName(QStringLiteral("label_87"));

        horizontalLayout_36->addWidget(label_87);


        verticalLayout_17->addLayout(horizontalLayout_36);

        checkBox_9 = new QCheckBox(groupBox_2);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        verticalLayout_17->addWidget(checkBox_9);

        label_88 = new QLabel(groupBox_2);
        label_88->setObjectName(QStringLiteral("label_88"));
        sizePolicy1.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy1);
        label_88->setMinimumSize(QSize(0, 10));

        verticalLayout_17->addWidget(label_88);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        label_89 = new QLabel(groupBox_2);
        label_89->setObjectName(QStringLiteral("label_89"));

        horizontalLayout_37->addWidget(label_89);

        slider_morp_element_size_2 = new QSlider(groupBox_2);
        slider_morp_element_size_2->setObjectName(QStringLiteral("slider_morp_element_size_2"));
        sizePolicy1.setHeightForWidth(slider_morp_element_size_2->sizePolicy().hasHeightForWidth());
        slider_morp_element_size_2->setSizePolicy(sizePolicy1);
        slider_morp_element_size_2->setMinimum(3);
        slider_morp_element_size_2->setMaximum(11);
        slider_morp_element_size_2->setSingleStep(2);
        slider_morp_element_size_2->setPageStep(2);
        slider_morp_element_size_2->setOrientation(Qt::Horizontal);
        slider_morp_element_size_2->setInvertedAppearance(false);
        slider_morp_element_size_2->setInvertedControls(false);
        slider_morp_element_size_2->setTickPosition(QSlider::TicksBelow);
        slider_morp_element_size_2->setTickInterval(2);

        horizontalLayout_37->addWidget(slider_morp_element_size_2);

        label_90 = new QLabel(groupBox_2);
        label_90->setObjectName(QStringLiteral("label_90"));

        horizontalLayout_37->addWidget(label_90);


        verticalLayout_17->addLayout(horizontalLayout_37);

        checkBox_10 = new QCheckBox(groupBox_2);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        verticalLayout_17->addWidget(checkBox_10);

        label_93 = new QLabel(groupBox_2);
        label_93->setObjectName(QStringLiteral("label_93"));
        sizePolicy1.setHeightForWidth(label_93->sizePolicy().hasHeightForWidth());
        label_93->setSizePolicy(sizePolicy1);
        label_93->setMinimumSize(QSize(0, 10));

        verticalLayout_17->addWidget(label_93);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        label_94 = new QLabel(groupBox_2);
        label_94->setObjectName(QStringLiteral("label_94"));

        horizontalLayout_38->addWidget(label_94);

        slider_gaussian_size_2 = new QSlider(groupBox_2);
        slider_gaussian_size_2->setObjectName(QStringLiteral("slider_gaussian_size_2"));
        sizePolicy1.setHeightForWidth(slider_gaussian_size_2->sizePolicy().hasHeightForWidth());
        slider_gaussian_size_2->setSizePolicy(sizePolicy1);
        slider_gaussian_size_2->setMinimum(3);
        slider_gaussian_size_2->setMaximum(15);
        slider_gaussian_size_2->setOrientation(Qt::Horizontal);
        slider_gaussian_size_2->setTickPosition(QSlider::TicksBelow);
        slider_gaussian_size_2->setTickInterval(1);

        horizontalLayout_38->addWidget(slider_gaussian_size_2);

        label_95 = new QLabel(groupBox_2);
        label_95->setObjectName(QStringLiteral("label_95"));

        horizontalLayout_38->addWidget(label_95);


        verticalLayout_17->addLayout(horizontalLayout_38);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));

        verticalLayout_17->addLayout(horizontalLayout_39);


        verticalLayout_16->addLayout(verticalLayout_17);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        label_91 = new QLabel(BackgroundModelTuningDialog);
        label_91->setObjectName(QStringLiteral("label_91"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_91->sizePolicy().hasHeightForWidth());
        label_91->setSizePolicy(sizePolicy2);

        horizontalLayout_33->addWidget(label_91);

        label_92 = new QLabel(BackgroundModelTuningDialog);
        label_92->setObjectName(QStringLiteral("label_92"));

        horizontalLayout_33->addWidget(label_92);


        verticalLayout->addLayout(horizontalLayout_33);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        pushButton_load = new QPushButton(BackgroundModelTuningDialog);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout_32->addWidget(pushButton_load);

        pushButton_save = new QPushButton(BackgroundModelTuningDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout_32->addWidget(pushButton_save);


        verticalLayout->addLayout(horizontalLayout_32);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(BackgroundModelTuningDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy3);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_34->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_34);


        retranslateUi(BackgroundModelTuningDialog);

        QMetaObject::connectSlotsByName(BackgroundModelTuningDialog);
    } // setupUi

    void retranslateUi(QDialog *BackgroundModelTuningDialog)
    {
        BackgroundModelTuningDialog->setWindowTitle(QApplication::translate("BackgroundModelTuningDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("BackgroundModelTuningDialog", "Parameter Tuning - Camera 1", 0));
        label->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Min Area", 0));
        label_6->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_7->setText(QApplication::translate("BackgroundModelTuningDialog", "300", 0));
        checkBox_7->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Blob Detector Max Area", 0));
        label_3->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Max Area", 0));
        label_8->setText(QApplication::translate("BackgroundModelTuningDialog", "100", 0));
        label_9->setText(QApplication::translate("BackgroundModelTuningDialog", "1000", 0));
        checkBox_2->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Morphology Opening", 0));
        label_5->setText(QApplication::translate("BackgroundModelTuningDialog", "Morphology Structuring Element Size", 0));
        label_10->setText(QApplication::translate("BackgroundModelTuningDialog", "3", 0));
        label_11->setText(QApplication::translate("BackgroundModelTuningDialog", "11", 0));
        checkBox->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Gaussian Blur", 0));
        label_14->setText(QApplication::translate("BackgroundModelTuningDialog", "Gaussian Blur Size of Filter", 0));
        label_12->setText(QApplication::translate("BackgroundModelTuningDialog", "3", 0));
        label_13->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        groupBox_2->setTitle(QApplication::translate("BackgroundModelTuningDialog", "Parameter Tuning - Camera 2", 0));
        label_82->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Min Area", 0));
        label_83->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_84->setText(QApplication::translate("BackgroundModelTuningDialog", "300", 0));
        checkBox_8->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Blob Detector Max Area", 0));
        label_85->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Max Area", 0));
        label_86->setText(QApplication::translate("BackgroundModelTuningDialog", "100", 0));
        label_87->setText(QApplication::translate("BackgroundModelTuningDialog", "1000", 0));
        checkBox_9->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Morphology Opening", 0));
        label_88->setText(QApplication::translate("BackgroundModelTuningDialog", "Morphology Structuring Element Size", 0));
        label_89->setText(QApplication::translate("BackgroundModelTuningDialog", "3", 0));
        label_90->setText(QApplication::translate("BackgroundModelTuningDialog", "11", 0));
        checkBox_10->setText(QApplication::translate("BackgroundModelTuningDialog", "Enable Gaussian Blur", 0));
        label_93->setText(QApplication::translate("BackgroundModelTuningDialog", "Gaussian Blur Size of Filter", 0));
        label_94->setText(QApplication::translate("BackgroundModelTuningDialog", "3", 0));
        label_95->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        label_91->setText(QApplication::translate("BackgroundModelTuningDialog", "Status: ", 0));
        label_92->setText(QApplication::translate("BackgroundModelTuningDialog", "Unknown", 0));
        pushButton_load->setText(QApplication::translate("BackgroundModelTuningDialog", "Load Settings from File...", 0));
        pushButton_save->setText(QApplication::translate("BackgroundModelTuningDialog", "Save Settings to File...", 0));
    } // retranslateUi

};

namespace Ui {
    class BackgroundModelTuningDialog: public Ui_BackgroundModelTuningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDMODELTUNINGDIALOG_H
