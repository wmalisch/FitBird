/********************************************************************************
** Form generated from reading UI file 'manageprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEPROFILE_H
#define UI_MANAGEPROFILE_H

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

class Ui_ManageProfile
{
public:
    QGroupBox *groupBox_updateProfile;
    QLabel *label;
    QPushButton *pushButton_updateProfile;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_weight;
    QLineEdit *lineEdit_newWeight;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_sex;
    QLineEdit *lineEdit_newSex;
    QHBoxLayout *horizontalLayout;
    QLabel *label_age;
    QLineEdit *lineEdit_newAge;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_height;
    QLineEdit *lineEdit_newHeight;
    QLabel *label_currName;
    QLabel *label_2;
    QLabel *label_currWeight;
    QLabel *label_currSex;
    QLabel *label_currAge;
    QLabel *label_currHeight;
    QPushButton *pushButton;
    QLabel *label_stepGoal;
    QPushButton *pushButton_updateStepGoal;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_newStepGoal;

    void setupUi(QDialog *ManageProfile)
    {
        if (ManageProfile->objectName().isEmpty())
            ManageProfile->setObjectName(QString::fromUtf8("ManageProfile"));
        ManageProfile->resize(544, 524);
        groupBox_updateProfile = new QGroupBox(ManageProfile);
        groupBox_updateProfile->setObjectName(QString::fromUtf8("groupBox_updateProfile"));
        groupBox_updateProfile->setGeometry(QRect(230, 50, 291, 351));
        label = new QLabel(groupBox_updateProfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 40, 81, 21));
        pushButton_updateProfile = new QPushButton(groupBox_updateProfile);
        pushButton_updateProfile->setObjectName(QString::fromUtf8("pushButton_updateProfile"));
        pushButton_updateProfile->setGeometry(QRect(90, 290, 131, 31));
        layoutWidget_10 = new QWidget(groupBox_updateProfile);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(30, 40, 241, 231));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_weight = new QLabel(layoutWidget_10);
        label_weight->setObjectName(QString::fromUtf8("label_weight"));

        horizontalLayout_2->addWidget(label_weight);

        lineEdit_newWeight = new QLineEdit(layoutWidget_10);
        lineEdit_newWeight->setObjectName(QString::fromUtf8("lineEdit_newWeight"));

        horizontalLayout_2->addWidget(lineEdit_newWeight);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_sex = new QLabel(layoutWidget_10);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));

        horizontalLayout_4->addWidget(label_sex);

        lineEdit_newSex = new QLineEdit(layoutWidget_10);
        lineEdit_newSex->setObjectName(QString::fromUtf8("lineEdit_newSex"));

        horizontalLayout_4->addWidget(lineEdit_newSex);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_age = new QLabel(layoutWidget_10);
        label_age->setObjectName(QString::fromUtf8("label_age"));

        horizontalLayout->addWidget(label_age);

        lineEdit_newAge = new QLineEdit(layoutWidget_10);
        lineEdit_newAge->setObjectName(QString::fromUtf8("lineEdit_newAge"));

        horizontalLayout->addWidget(lineEdit_newAge);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_height = new QLabel(layoutWidget_10);
        label_height->setObjectName(QString::fromUtf8("label_height"));

        horizontalLayout_3->addWidget(label_height);

        lineEdit_newHeight = new QLineEdit(layoutWidget_10);
        lineEdit_newHeight->setObjectName(QString::fromUtf8("lineEdit_newHeight"));

        horizontalLayout_3->addWidget(lineEdit_newHeight);


        verticalLayout_4->addLayout(horizontalLayout_3);

        label_currName = new QLabel(ManageProfile);
        label_currName->setObjectName(QString::fromUtf8("label_currName"));
        label_currName->setGeometry(QRect(40, 140, 181, 16));
        label_2 = new QLabel(ManageProfile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 171, 31));
        label_currWeight = new QLabel(ManageProfile);
        label_currWeight->setObjectName(QString::fromUtf8("label_currWeight"));
        label_currWeight->setGeometry(QRect(40, 220, 181, 16));
        label_currSex = new QLabel(ManageProfile);
        label_currSex->setObjectName(QString::fromUtf8("label_currSex"));
        label_currSex->setGeometry(QRect(40, 310, 181, 16));
        label_currAge = new QLabel(ManageProfile);
        label_currAge->setObjectName(QString::fromUtf8("label_currAge"));
        label_currAge->setGeometry(QRect(40, 180, 181, 16));
        label_currHeight = new QLabel(ManageProfile);
        label_currHeight->setObjectName(QString::fromUtf8("label_currHeight"));
        label_currHeight->setGeometry(QRect(40, 260, 181, 16));
        pushButton = new QPushButton(ManageProfile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 80, 111, 31));
        label_stepGoal = new QLabel(ManageProfile);
        label_stepGoal->setObjectName(QString::fromUtf8("label_stepGoal"));
        label_stepGoal->setGeometry(QRect(40, 360, 181, 16));
        pushButton_updateStepGoal = new QPushButton(ManageProfile);
        pushButton_updateStepGoal->setObjectName(QString::fromUtf8("pushButton_updateStepGoal"));
        pushButton_updateStepGoal->setGeometry(QRect(350, 460, 75, 23));
        layoutWidget = new QWidget(ManageProfile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 460, 281, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit_newStepGoal = new QLineEdit(layoutWidget);
        lineEdit_newStepGoal->setObjectName(QString::fromUtf8("lineEdit_newStepGoal"));

        horizontalLayout_5->addWidget(lineEdit_newStepGoal);


        retranslateUi(ManageProfile);

        QMetaObject::connectSlotsByName(ManageProfile);
    } // setupUi

    void retranslateUi(QDialog *ManageProfile)
    {
        ManageProfile->setWindowTitle(QCoreApplication::translate("ManageProfile", "Dialog", nullptr));
        groupBox_updateProfile->setTitle(QCoreApplication::translate("ManageProfile", "Update Profile", nullptr));
        label->setText(QString());
        pushButton_updateProfile->setText(QCoreApplication::translate("ManageProfile", "Update Profile", nullptr));
        label_weight->setText(QCoreApplication::translate("ManageProfile", "Weight (kg):", nullptr));
        label_sex->setText(QCoreApplication::translate("ManageProfile", "Sex (M/F):", nullptr));
        label_age->setText(QCoreApplication::translate("ManageProfile", "Age:", nullptr));
        label_height->setText(QCoreApplication::translate("ManageProfile", "Height (cm):", nullptr));
        label_currName->setText(QCoreApplication::translate("ManageProfile", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("ManageProfile", "Press to view Current Information", nullptr));
        label_currWeight->setText(QCoreApplication::translate("ManageProfile", "Weight (kg):", nullptr));
        label_currSex->setText(QCoreApplication::translate("ManageProfile", "Sex (M/F): ", nullptr));
        label_currAge->setText(QCoreApplication::translate("ManageProfile", "Age: ", nullptr));
        label_currHeight->setText(QCoreApplication::translate("ManageProfile", "Height (cm):", nullptr));
        pushButton->setText(QCoreApplication::translate("ManageProfile", "View Info", nullptr));
        label_stepGoal->setText(QCoreApplication::translate("ManageProfile", "Step Goal:", nullptr));
        pushButton_updateStepGoal->setText(QCoreApplication::translate("ManageProfile", "Update", nullptr));
        label_4->setText(QCoreApplication::translate("ManageProfile", "New Step Goal:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageProfile: public Ui_ManageProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEPROFILE_H
