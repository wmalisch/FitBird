/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DashBoard
{
public:
    QGroupBox *groupBox_dashboard;
    QPushButton *pushButton_manageProfile;
    QPushButton *pushButton_manageActivities;

    void setupUi(QDialog *DashBoard)
    {
        if (DashBoard->objectName().isEmpty())
            DashBoard->setObjectName(QString::fromUtf8("DashBoard"));
        DashBoard->resize(483, 382);
        groupBox_dashboard = new QGroupBox(DashBoard);
        groupBox_dashboard->setObjectName(QString::fromUtf8("groupBox_dashboard"));
        groupBox_dashboard->setGeometry(QRect(80, 50, 331, 231));
        pushButton_manageProfile = new QPushButton(groupBox_dashboard);
        pushButton_manageProfile->setObjectName(QString::fromUtf8("pushButton_manageProfile"));
        pushButton_manageProfile->setGeometry(QRect(110, 80, 101, 31));
        pushButton_manageActivities = new QPushButton(groupBox_dashboard);
        pushButton_manageActivities->setObjectName(QString::fromUtf8("pushButton_manageActivities"));
        pushButton_manageActivities->setGeometry(QRect(110, 120, 101, 31));

        retranslateUi(DashBoard);

        QMetaObject::connectSlotsByName(DashBoard);
    } // setupUi

    void retranslateUi(QDialog *DashBoard)
    {
        DashBoard->setWindowTitle(QCoreApplication::translate("DashBoard", "Dialog", nullptr));
        groupBox_dashboard->setTitle(QCoreApplication::translate("DashBoard", "Dashboard", nullptr));
        pushButton_manageProfile->setText(QCoreApplication::translate("DashBoard", "Manage Profile", nullptr));
        pushButton_manageActivities->setText(QCoreApplication::translate("DashBoard", "Manage Activities", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashBoard: public Ui_DashBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
