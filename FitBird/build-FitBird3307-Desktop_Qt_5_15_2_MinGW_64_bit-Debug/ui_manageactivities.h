/********************************************************************************
** Form generated from reading UI file 'manageactivities.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEACTIVITIES_H
#define UI_MANAGEACTIVITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageActivities
{
public:
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *lineEdit_sHour;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_18;
    QLineEdit *lineEdit_sMin;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QLineEdit *lineEdit_eHour;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_19;
    QLineEdit *lineEdit_eMin;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLineEdit *lineEdit_duration;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QLineEdit *lineEdit_type;
    QHBoxLayout *horizontalLayout;
    QLabel *label_steps;
    QLineEdit *lineEdit_steps;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QLineEdit *lineEdit_elevation;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QLineEdit *lineEdit_distance;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLineEdit *lineEdit_day;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLineEdit *lineEdit_month;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *lineEdit_year;
    QPushButton *pushButton_addActivity;
    QPushButton *pushButton_addWithDate;
    QGroupBox *groupBox;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_23;
    QLineEdit *lineEdit_deleteName;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_24;
    QLineEdit *lineEdit_deleteDay;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_25;
    QLineEdit *lineEdit_deleteMonth;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_26;
    QLineEdit *lineEdit_deleteYear;
    QPushButton *pushButton_deleteActivity;
    QPushButton *pushButton_viewActivityHistory;

    void setupUi(QDialog *ManageActivities)
    {
        if (ManageActivities->objectName().isEmpty())
            ManageActivities->setObjectName(QString::fromUtf8("ManageActivities"));
        ManageActivities->resize(721, 670);
        groupBox_2 = new QGroupBox(ManageActivities);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 20, 271, 581));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 390, 141, 16));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 241, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout_5->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        lineEdit_sHour = new QLineEdit(layoutWidget);
        lineEdit_sHour->setObjectName(QString::fromUtf8("lineEdit_sHour"));

        horizontalLayout_7->addWidget(lineEdit_sHour);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_15->addWidget(label_18);

        lineEdit_sMin = new QLineEdit(layoutWidget);
        lineEdit_sMin->setObjectName(QString::fromUtf8("lineEdit_sMin"));

        horizontalLayout_15->addWidget(lineEdit_sMin);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_11->addWidget(label_14);

        lineEdit_eHour = new QLineEdit(layoutWidget);
        lineEdit_eHour->setObjectName(QString::fromUtf8("lineEdit_eHour"));

        horizontalLayout_11->addWidget(lineEdit_eHour);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_16->addWidget(label_19);

        lineEdit_eMin = new QLineEdit(layoutWidget);
        lineEdit_eMin->setObjectName(QString::fromUtf8("lineEdit_eMin"));

        horizontalLayout_16->addWidget(lineEdit_eMin);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_10->addWidget(label_13);

        lineEdit_duration = new QLineEdit(layoutWidget);
        lineEdit_duration->setObjectName(QString::fromUtf8("lineEdit_duration"));

        horizontalLayout_10->addWidget(lineEdit_duration);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_13->addWidget(label_16);

        lineEdit_type = new QLineEdit(layoutWidget);
        lineEdit_type->setObjectName(QString::fromUtf8("lineEdit_type"));

        horizontalLayout_13->addWidget(lineEdit_type);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_steps = new QLabel(layoutWidget);
        label_steps->setObjectName(QString::fromUtf8("label_steps"));

        horizontalLayout->addWidget(label_steps);

        lineEdit_steps = new QLineEdit(layoutWidget);
        lineEdit_steps->setObjectName(QString::fromUtf8("lineEdit_steps"));

        horizontalLayout->addWidget(lineEdit_steps);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_14->addWidget(label_17);

        lineEdit_elevation = new QLineEdit(layoutWidget);
        lineEdit_elevation->setObjectName(QString::fromUtf8("lineEdit_elevation"));

        horizontalLayout_14->addWidget(lineEdit_elevation);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_12->addWidget(label_15);

        lineEdit_distance = new QLineEdit(layoutWidget);
        lineEdit_distance->setObjectName(QString::fromUtf8("lineEdit_distance"));

        horizontalLayout_12->addWidget(lineEdit_distance);


        verticalLayout->addLayout(horizontalLayout_12);

        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 410, 241, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        lineEdit_day = new QLineEdit(layoutWidget_2);
        lineEdit_day->setObjectName(QString::fromUtf8("lineEdit_day"));

        horizontalLayout_6->addWidget(lineEdit_day);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        lineEdit_month = new QLineEdit(layoutWidget_2);
        lineEdit_month->setObjectName(QString::fromUtf8("lineEdit_month"));

        horizontalLayout_8->addWidget(lineEdit_month);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        lineEdit_year = new QLineEdit(layoutWidget_2);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));

        horizontalLayout_9->addWidget(lineEdit_year);


        verticalLayout_2->addLayout(horizontalLayout_9);

        pushButton_addActivity = new QPushButton(groupBox_2);
        pushButton_addActivity->setObjectName(QString::fromUtf8("pushButton_addActivity"));
        pushButton_addActivity->setGeometry(QRect(10, 540, 111, 31));
        pushButton_addWithDate = new QPushButton(groupBox_2);
        pushButton_addWithDate->setObjectName(QString::fromUtf8("pushButton_addWithDate"));
        pushButton_addWithDate->setGeometry(QRect(140, 540, 111, 31));
        groupBox = new QGroupBox(ManageActivities);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(400, 30, 211, 271));
        layoutWidget_9 = new QWidget(groupBox);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(10, 40, 191, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_23 = new QLabel(layoutWidget_9);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_20->addWidget(label_23);

        lineEdit_deleteName = new QLineEdit(layoutWidget_9);
        lineEdit_deleteName->setObjectName(QString::fromUtf8("lineEdit_deleteName"));

        horizontalLayout_20->addWidget(lineEdit_deleteName);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_24 = new QLabel(layoutWidget_9);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_21->addWidget(label_24);

        lineEdit_deleteDay = new QLineEdit(layoutWidget_9);
        lineEdit_deleteDay->setObjectName(QString::fromUtf8("lineEdit_deleteDay"));

        horizontalLayout_21->addWidget(lineEdit_deleteDay);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_25 = new QLabel(layoutWidget_9);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_22->addWidget(label_25);

        lineEdit_deleteMonth = new QLineEdit(layoutWidget_9);
        lineEdit_deleteMonth->setObjectName(QString::fromUtf8("lineEdit_deleteMonth"));

        horizontalLayout_22->addWidget(lineEdit_deleteMonth);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_26 = new QLabel(layoutWidget_9);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_23->addWidget(label_26);

        lineEdit_deleteYear = new QLineEdit(layoutWidget_9);
        lineEdit_deleteYear->setObjectName(QString::fromUtf8("lineEdit_deleteYear"));

        horizontalLayout_23->addWidget(lineEdit_deleteYear);


        verticalLayout_3->addLayout(horizontalLayout_23);

        pushButton_deleteActivity = new QPushButton(groupBox);
        pushButton_deleteActivity->setObjectName(QString::fromUtf8("pushButton_deleteActivity"));
        pushButton_deleteActivity->setGeometry(QRect(50, 230, 111, 31));
        pushButton_viewActivityHistory = new QPushButton(ManageActivities);
        pushButton_viewActivityHistory->setObjectName(QString::fromUtf8("pushButton_viewActivityHistory"));
        pushButton_viewActivityHistory->setGeometry(QRect(440, 460, 131, 41));

        retranslateUi(ManageActivities);

        QMetaObject::connectSlotsByName(ManageActivities);
    } // setupUi

    void retranslateUi(QDialog *ManageActivities)
    {
        ManageActivities->setWindowTitle(QCoreApplication::translate("ManageActivities", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ManageActivities", "Add Activity", nullptr));
        label_3->setText(QCoreApplication::translate("ManageActivities", "Optional Information (Date)", nullptr));
        label_8->setText(QCoreApplication::translate("ManageActivities", "Name:", nullptr));
        label_10->setText(QCoreApplication::translate("ManageActivities", "Starting Hour (int):", nullptr));
        label_18->setText(QCoreApplication::translate("ManageActivities", "Starting Min (int):", nullptr));
        label_14->setText(QCoreApplication::translate("ManageActivities", "Ending Hour (int):", nullptr));
        label_19->setText(QCoreApplication::translate("ManageActivities", "Ending Min (int):", nullptr));
        label_13->setText(QCoreApplication::translate("ManageActivities", "Duration (min):", nullptr));
        label_16->setText(QCoreApplication::translate("ManageActivities", "Type ('Walk'):", nullptr));
        label_steps->setText(QCoreApplication::translate("ManageActivities", "Steps (int):", nullptr));
        label_17->setText(QCoreApplication::translate("ManageActivities", "Elevation (int):", nullptr));
        label_15->setText(QCoreApplication::translate("ManageActivities", "Distance (feet):", nullptr));
        label_9->setText(QCoreApplication::translate("ManageActivities", "Day (int):", nullptr));
        label_11->setText(QCoreApplication::translate("ManageActivities", "Month (int):", nullptr));
        label_12->setText(QCoreApplication::translate("ManageActivities", "Year (int):", nullptr));
        pushButton_addActivity->setText(QCoreApplication::translate("ManageActivities", "Add", nullptr));
        pushButton_addWithDate->setText(QCoreApplication::translate("ManageActivities", "Add with Date", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ManageActivities", "Delete Activity", nullptr));
        label_23->setText(QCoreApplication::translate("ManageActivities", "Name:", nullptr));
        label_24->setText(QCoreApplication::translate("ManageActivities", "Day (int):", nullptr));
        label_25->setText(QCoreApplication::translate("ManageActivities", "Month (int):", nullptr));
        label_26->setText(QCoreApplication::translate("ManageActivities", "Year (int):", nullptr));
        pushButton_deleteActivity->setText(QCoreApplication::translate("ManageActivities", "Delete", nullptr));
        pushButton_viewActivityHistory->setText(QCoreApplication::translate("ManageActivities", "View Activity History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageActivities: public Ui_ManageActivities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEACTIVITIES_H
