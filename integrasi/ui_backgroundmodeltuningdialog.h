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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *min_area_1;
    QSlider *slider_min_area_1;
    QLabel *label_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *max_area_1;
    QSlider *slider_max_area_1;
    QLabel *label_9;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *morph_1;
    QSlider *slider_morp_element_size_1;
    QLabel *label_11;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QLabel *gaussian_1;
    QSlider *slider_gaussian_size_1;
    QLabel *label_13;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_11;
    QLabel *occlusion_1;
    QSlider *slider_occlusion_threshold_1;
    QLabel *label_25;
    QLabel *label_37;
    QHBoxLayout *horizontalLayout_15;
    QLabel *association_1;
    QSlider *slider_association_threshold_1;
    QLabel *label_36;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_12;
    QLabel *transformed_1;
    QSlider *slider_transformed_threshold_1;
    QLabel *label_28;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_82;
    QHBoxLayout *horizontalLayout_35;
    QLabel *min_area_2;
    QSlider *slider_min_area_2;
    QLabel *label_84;
    QLabel *label_85;
    QHBoxLayout *horizontalLayout_36;
    QLabel *max_area_2;
    QSlider *slider_max_area_2;
    QLabel *label_87;
    QLabel *label_88;
    QHBoxLayout *horizontalLayout_37;
    QLabel *morph_2;
    QSlider *slider_morp_element_size_2;
    QLabel *label_90;
    QLabel *label_93;
    QHBoxLayout *horizontalLayout_38;
    QLabel *gaussian_2;
    QSlider *slider_gaussian_size_2;
    QLabel *label_95;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_13;
    QLabel *occlusion_2;
    QSlider *slider_occlusion_threshold_2;
    QLabel *label_31;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_16;
    QLabel *association_2;
    QSlider *slider_association_threshold_2;
    QLabel *label_40;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_14;
    QLabel *transformed_2;
    QSlider *slider_transformed_threshold_2;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_91;
    QLabel *label_92;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *pushButton_load;
    QPushButton *pushButton_load_default_setting;
    QPushButton *pushButton_save;
    QHBoxLayout *horizontalLayout_34;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BackgroundModelTuningDialog)
    {
        if (BackgroundModelTuningDialog->objectName().isEmpty())
            BackgroundModelTuningDialog->setObjectName(QStringLiteral("BackgroundModelTuningDialog"));
        BackgroundModelTuningDialog->resize(626, 499);
        verticalLayout_3 = new QVBoxLayout(BackgroundModelTuningDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
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
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        min_area_1 = new QLabel(groupBox);
        min_area_1->setObjectName(QStringLiteral("min_area_1"));

        horizontalLayout_2->addWidget(min_area_1);

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


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        max_area_1 = new QLabel(groupBox);
        max_area_1->setObjectName(QStringLiteral("max_area_1"));

        horizontalLayout_3->addWidget(max_area_1);

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


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        morph_1 = new QLabel(groupBox);
        morph_1->setObjectName(QStringLiteral("morph_1"));

        horizontalLayout_4->addWidget(morph_1);

        slider_morp_element_size_1 = new QSlider(groupBox);
        slider_morp_element_size_1->setObjectName(QStringLiteral("slider_morp_element_size_1"));
        sizePolicy1.setHeightForWidth(slider_morp_element_size_1->sizePolicy().hasHeightForWidth());
        slider_morp_element_size_1->setSizePolicy(sizePolicy1);
        slider_morp_element_size_1->setMinimum(0);
        slider_morp_element_size_1->setMaximum(11);
        slider_morp_element_size_1->setSingleStep(2);
        slider_morp_element_size_1->setPageStep(2);
        slider_morp_element_size_1->setSliderPosition(0);
        slider_morp_element_size_1->setOrientation(Qt::Horizontal);
        slider_morp_element_size_1->setInvertedAppearance(false);
        slider_morp_element_size_1->setInvertedControls(false);
        slider_morp_element_size_1->setTickPosition(QSlider::TicksBelow);
        slider_morp_element_size_1->setTickInterval(2);

        horizontalLayout_4->addWidget(slider_morp_element_size_1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout_4);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_14);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gaussian_1 = new QLabel(groupBox);
        gaussian_1->setObjectName(QStringLiteral("gaussian_1"));

        horizontalLayout_5->addWidget(gaussian_1);

        slider_gaussian_size_1 = new QSlider(groupBox);
        slider_gaussian_size_1->setObjectName(QStringLiteral("slider_gaussian_size_1"));
        sizePolicy1.setHeightForWidth(slider_gaussian_size_1->sizePolicy().hasHeightForWidth());
        slider_gaussian_size_1->setSizePolicy(sizePolicy1);
        slider_gaussian_size_1->setMinimum(0);
        slider_gaussian_size_1->setMaximum(15);
        slider_gaussian_size_1->setSingleStep(5);
        slider_gaussian_size_1->setPageStep(2);
        slider_gaussian_size_1->setSliderPosition(0);
        slider_gaussian_size_1->setOrientation(Qt::Horizontal);
        slider_gaussian_size_1->setTickPosition(QSlider::TicksBelow);
        slider_gaussian_size_1->setTickInterval(2);

        horizontalLayout_5->addWidget(slider_gaussian_size_1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout->addLayout(horizontalLayout_5);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);
        label_23->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_23);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        occlusion_1 = new QLabel(groupBox);
        occlusion_1->setObjectName(QStringLiteral("occlusion_1"));

        horizontalLayout_11->addWidget(occlusion_1);

        slider_occlusion_threshold_1 = new QSlider(groupBox);
        slider_occlusion_threshold_1->setObjectName(QStringLiteral("slider_occlusion_threshold_1"));
        sizePolicy1.setHeightForWidth(slider_occlusion_threshold_1->sizePolicy().hasHeightForWidth());
        slider_occlusion_threshold_1->setSizePolicy(sizePolicy1);
        slider_occlusion_threshold_1->setMinimum(0);
        slider_occlusion_threshold_1->setMaximum(20);
        slider_occlusion_threshold_1->setSliderPosition(0);
        slider_occlusion_threshold_1->setOrientation(Qt::Horizontal);
        slider_occlusion_threshold_1->setTickPosition(QSlider::TicksBelow);
        slider_occlusion_threshold_1->setTickInterval(1);

        horizontalLayout_11->addWidget(slider_occlusion_threshold_1);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_11->addWidget(label_25);


        verticalLayout->addLayout(horizontalLayout_11);

        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy1.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy1);
        label_37->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_37);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        association_1 = new QLabel(groupBox);
        association_1->setObjectName(QStringLiteral("association_1"));

        horizontalLayout_15->addWidget(association_1);

        slider_association_threshold_1 = new QSlider(groupBox);
        slider_association_threshold_1->setObjectName(QStringLiteral("slider_association_threshold_1"));
        sizePolicy1.setHeightForWidth(slider_association_threshold_1->sizePolicy().hasHeightForWidth());
        slider_association_threshold_1->setSizePolicy(sizePolicy1);
        slider_association_threshold_1->setMinimum(0);
        slider_association_threshold_1->setMaximum(10);
        slider_association_threshold_1->setSliderPosition(0);
        slider_association_threshold_1->setOrientation(Qt::Horizontal);
        slider_association_threshold_1->setTickPosition(QSlider::TicksBelow);
        slider_association_threshold_1->setTickInterval(1);

        horizontalLayout_15->addWidget(slider_association_threshold_1);

        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_15->addWidget(label_36);


        verticalLayout->addLayout(horizontalLayout_15);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy1.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy1);
        label_26->setMinimumSize(QSize(0, 10));

        verticalLayout->addWidget(label_26);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        transformed_1 = new QLabel(groupBox);
        transformed_1->setObjectName(QStringLiteral("transformed_1"));

        horizontalLayout_12->addWidget(transformed_1);

        slider_transformed_threshold_1 = new QSlider(groupBox);
        slider_transformed_threshold_1->setObjectName(QStringLiteral("slider_transformed_threshold_1"));
        sizePolicy1.setHeightForWidth(slider_transformed_threshold_1->sizePolicy().hasHeightForWidth());
        slider_transformed_threshold_1->setSizePolicy(sizePolicy1);
        slider_transformed_threshold_1->setMinimum(0);
        slider_transformed_threshold_1->setMaximum(15);
        slider_transformed_threshold_1->setValue(0);
        slider_transformed_threshold_1->setOrientation(Qt::Horizontal);
        slider_transformed_threshold_1->setTickPosition(QSlider::TicksBelow);
        slider_transformed_threshold_1->setTickInterval(1);

        horizontalLayout_12->addWidget(slider_transformed_threshold_1);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_12->addWidget(label_28);


        verticalLayout->addLayout(horizontalLayout_12);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BackgroundModelTuningDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(300, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_82 = new QLabel(groupBox_2);
        label_82->setObjectName(QStringLiteral("label_82"));
        sizePolicy1.setHeightForWidth(label_82->sizePolicy().hasHeightForWidth());
        label_82->setSizePolicy(sizePolicy1);
        label_82->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_82);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        min_area_2 = new QLabel(groupBox_2);
        min_area_2->setObjectName(QStringLiteral("min_area_2"));

        horizontalLayout_35->addWidget(min_area_2);

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


        verticalLayout_2->addLayout(horizontalLayout_35);

        label_85 = new QLabel(groupBox_2);
        label_85->setObjectName(QStringLiteral("label_85"));
        sizePolicy1.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy1);
        label_85->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_85);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        max_area_2 = new QLabel(groupBox_2);
        max_area_2->setObjectName(QStringLiteral("max_area_2"));

        horizontalLayout_36->addWidget(max_area_2);

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


        verticalLayout_2->addLayout(horizontalLayout_36);

        label_88 = new QLabel(groupBox_2);
        label_88->setObjectName(QStringLiteral("label_88"));
        sizePolicy1.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy1);
        label_88->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_88);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        morph_2 = new QLabel(groupBox_2);
        morph_2->setObjectName(QStringLiteral("morph_2"));

        horizontalLayout_37->addWidget(morph_2);

        slider_morp_element_size_2 = new QSlider(groupBox_2);
        slider_morp_element_size_2->setObjectName(QStringLiteral("slider_morp_element_size_2"));
        sizePolicy1.setHeightForWidth(slider_morp_element_size_2->sizePolicy().hasHeightForWidth());
        slider_morp_element_size_2->setSizePolicy(sizePolicy1);
        slider_morp_element_size_2->setMinimum(0);
        slider_morp_element_size_2->setMaximum(11);
        slider_morp_element_size_2->setSingleStep(2);
        slider_morp_element_size_2->setPageStep(2);
        slider_morp_element_size_2->setSliderPosition(0);
        slider_morp_element_size_2->setOrientation(Qt::Horizontal);
        slider_morp_element_size_2->setInvertedAppearance(false);
        slider_morp_element_size_2->setInvertedControls(false);
        slider_morp_element_size_2->setTickPosition(QSlider::TicksBelow);
        slider_morp_element_size_2->setTickInterval(2);

        horizontalLayout_37->addWidget(slider_morp_element_size_2);

        label_90 = new QLabel(groupBox_2);
        label_90->setObjectName(QStringLiteral("label_90"));

        horizontalLayout_37->addWidget(label_90);


        verticalLayout_2->addLayout(horizontalLayout_37);

        label_93 = new QLabel(groupBox_2);
        label_93->setObjectName(QStringLiteral("label_93"));
        sizePolicy1.setHeightForWidth(label_93->sizePolicy().hasHeightForWidth());
        label_93->setSizePolicy(sizePolicy1);
        label_93->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_93);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        gaussian_2 = new QLabel(groupBox_2);
        gaussian_2->setObjectName(QStringLiteral("gaussian_2"));

        horizontalLayout_38->addWidget(gaussian_2);

        slider_gaussian_size_2 = new QSlider(groupBox_2);
        slider_gaussian_size_2->setObjectName(QStringLiteral("slider_gaussian_size_2"));
        sizePolicy1.setHeightForWidth(slider_gaussian_size_2->sizePolicy().hasHeightForWidth());
        slider_gaussian_size_2->setSizePolicy(sizePolicy1);
        slider_gaussian_size_2->setMinimum(0);
        slider_gaussian_size_2->setMaximum(15);
        slider_gaussian_size_2->setSingleStep(2);
        slider_gaussian_size_2->setSliderPosition(0);
        slider_gaussian_size_2->setOrientation(Qt::Horizontal);
        slider_gaussian_size_2->setTickPosition(QSlider::TicksBelow);
        slider_gaussian_size_2->setTickInterval(1);

        horizontalLayout_38->addWidget(slider_gaussian_size_2);

        label_95 = new QLabel(groupBox_2);
        label_95->setObjectName(QStringLiteral("label_95"));

        horizontalLayout_38->addWidget(label_95);


        verticalLayout_2->addLayout(horizontalLayout_38);

        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);
        label_29->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_29);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        occlusion_2 = new QLabel(groupBox_2);
        occlusion_2->setObjectName(QStringLiteral("occlusion_2"));

        horizontalLayout_13->addWidget(occlusion_2);

        slider_occlusion_threshold_2 = new QSlider(groupBox_2);
        slider_occlusion_threshold_2->setObjectName(QStringLiteral("slider_occlusion_threshold_2"));
        sizePolicy1.setHeightForWidth(slider_occlusion_threshold_2->sizePolicy().hasHeightForWidth());
        slider_occlusion_threshold_2->setSizePolicy(sizePolicy1);
        slider_occlusion_threshold_2->setMinimum(0);
        slider_occlusion_threshold_2->setMaximum(20);
        slider_occlusion_threshold_2->setSliderPosition(0);
        slider_occlusion_threshold_2->setOrientation(Qt::Horizontal);
        slider_occlusion_threshold_2->setTickPosition(QSlider::TicksBelow);
        slider_occlusion_threshold_2->setTickInterval(1);

        horizontalLayout_13->addWidget(slider_occlusion_threshold_2);

        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_13->addWidget(label_31);


        verticalLayout_2->addLayout(horizontalLayout_13);

        label_38 = new QLabel(groupBox_2);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy1.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy1);
        label_38->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_38);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        association_2 = new QLabel(groupBox_2);
        association_2->setObjectName(QStringLiteral("association_2"));

        horizontalLayout_16->addWidget(association_2);

        slider_association_threshold_2 = new QSlider(groupBox_2);
        slider_association_threshold_2->setObjectName(QStringLiteral("slider_association_threshold_2"));
        sizePolicy1.setHeightForWidth(slider_association_threshold_2->sizePolicy().hasHeightForWidth());
        slider_association_threshold_2->setSizePolicy(sizePolicy1);
        slider_association_threshold_2->setMinimum(0);
        slider_association_threshold_2->setMaximum(10);
        slider_association_threshold_2->setSliderPosition(0);
        slider_association_threshold_2->setOrientation(Qt::Horizontal);
        slider_association_threshold_2->setTickPosition(QSlider::TicksBelow);
        slider_association_threshold_2->setTickInterval(1);

        horizontalLayout_16->addWidget(slider_association_threshold_2);

        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName(QStringLiteral("label_40"));

        horizontalLayout_16->addWidget(label_40);


        verticalLayout_2->addLayout(horizontalLayout_16);

        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy1.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy1);
        label_34->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(label_34);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        transformed_2 = new QLabel(groupBox_2);
        transformed_2->setObjectName(QStringLiteral("transformed_2"));

        horizontalLayout_14->addWidget(transformed_2);

        slider_transformed_threshold_2 = new QSlider(groupBox_2);
        slider_transformed_threshold_2->setObjectName(QStringLiteral("slider_transformed_threshold_2"));
        sizePolicy1.setHeightForWidth(slider_transformed_threshold_2->sizePolicy().hasHeightForWidth());
        slider_transformed_threshold_2->setSizePolicy(sizePolicy1);
        slider_transformed_threshold_2->setMinimum(0);
        slider_transformed_threshold_2->setMaximum(15);
        slider_transformed_threshold_2->setValue(0);
        slider_transformed_threshold_2->setOrientation(Qt::Horizontal);
        slider_transformed_threshold_2->setTickPosition(QSlider::TicksBelow);
        slider_transformed_threshold_2->setTickInterval(1);

        horizontalLayout_14->addWidget(slider_transformed_threshold_2);

        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        horizontalLayout_14->addWidget(label_33);


        verticalLayout_2->addLayout(horizontalLayout_14);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout);

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


        verticalLayout_3->addLayout(horizontalLayout_33);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        pushButton_load = new QPushButton(BackgroundModelTuningDialog);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout_32->addWidget(pushButton_load);

        pushButton_load_default_setting = new QPushButton(BackgroundModelTuningDialog);
        pushButton_load_default_setting->setObjectName(QStringLiteral("pushButton_load_default_setting"));

        horizontalLayout_32->addWidget(pushButton_load_default_setting);

        pushButton_save = new QPushButton(BackgroundModelTuningDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout_32->addWidget(pushButton_save);


        verticalLayout_3->addLayout(horizontalLayout_32);

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


        verticalLayout_3->addLayout(horizontalLayout_34);


        retranslateUi(BackgroundModelTuningDialog);

        QMetaObject::connectSlotsByName(BackgroundModelTuningDialog);
    } // setupUi

    void retranslateUi(QDialog *BackgroundModelTuningDialog)
    {
        BackgroundModelTuningDialog->setWindowTitle(QApplication::translate("BackgroundModelTuningDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("BackgroundModelTuningDialog", "Parameter Tuning - Camera 1", 0));
        label->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Min Area", 0));
        min_area_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_7->setText(QApplication::translate("BackgroundModelTuningDialog", "300", 0));
        label_3->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Max Area", 0));
        max_area_1->setText(QApplication::translate("BackgroundModelTuningDialog", "100", 0));
        label_9->setText(QApplication::translate("BackgroundModelTuningDialog", "1000", 0));
        label_5->setText(QApplication::translate("BackgroundModelTuningDialog", "Morphology Structuring Element Size", 0));
        morph_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_11->setText(QApplication::translate("BackgroundModelTuningDialog", "11", 0));
        label_14->setText(QApplication::translate("BackgroundModelTuningDialog", "Gaussian Blur Size of Filter", 0));
        gaussian_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_13->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        label_23->setText(QApplication::translate("BackgroundModelTuningDialog", "Pixel Threshold of Occlusion", 0));
        occlusion_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_25->setText(QApplication::translate("BackgroundModelTuningDialog", "20", 0));
        label_37->setText(QApplication::translate("BackgroundModelTuningDialog", "Pixel Threshold of Association", 0));
        association_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_36->setText(QApplication::translate("BackgroundModelTuningDialog", "10", 0));
        label_26->setText(QApplication::translate("BackgroundModelTuningDialog", "Transformed Threshold of Occlusion", 0));
        transformed_1->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_28->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        groupBox_2->setTitle(QApplication::translate("BackgroundModelTuningDialog", "Parameter Tuning - Camera 2", 0));
        label_82->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Min Area", 0));
        min_area_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_84->setText(QApplication::translate("BackgroundModelTuningDialog", "300", 0));
        label_85->setText(QApplication::translate("BackgroundModelTuningDialog", "Blob Detector Max Area", 0));
        max_area_2->setText(QApplication::translate("BackgroundModelTuningDialog", "100", 0));
        label_87->setText(QApplication::translate("BackgroundModelTuningDialog", "1000", 0));
        label_88->setText(QApplication::translate("BackgroundModelTuningDialog", "Morphology Structuring Element Size", 0));
        morph_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_90->setText(QApplication::translate("BackgroundModelTuningDialog", "11", 0));
        label_93->setText(QApplication::translate("BackgroundModelTuningDialog", "Gaussian Blur Size of Filter", 0));
        gaussian_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_95->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        label_29->setText(QApplication::translate("BackgroundModelTuningDialog", "Pixel Threshold of Occlusion", 0));
        occlusion_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_31->setText(QApplication::translate("BackgroundModelTuningDialog", "20", 0));
        label_38->setText(QApplication::translate("BackgroundModelTuningDialog", "Pixel Threshold of Association", 0));
        association_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_40->setText(QApplication::translate("BackgroundModelTuningDialog", "10", 0));
        label_34->setText(QApplication::translate("BackgroundModelTuningDialog", "Transformed Threshold of Occlusion", 0));
        transformed_2->setText(QApplication::translate("BackgroundModelTuningDialog", "0", 0));
        label_33->setText(QApplication::translate("BackgroundModelTuningDialog", "15", 0));
        label_91->setText(QApplication::translate("BackgroundModelTuningDialog", "Status: ", 0));
        label_92->setText(QApplication::translate("BackgroundModelTuningDialog", "Unknown", 0));
        pushButton_load->setText(QApplication::translate("BackgroundModelTuningDialog", "Load Settings from File...", 0));
        pushButton_load_default_setting->setText(QApplication::translate("BackgroundModelTuningDialog", "Load Default Setting File...", 0));
        pushButton_save->setText(QApplication::translate("BackgroundModelTuningDialog", "Save Settings to File...", 0));
    } // retranslateUi

};

namespace Ui {
    class BackgroundModelTuningDialog: public Ui_BackgroundModelTuningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDMODELTUNINGDIALOG_H
