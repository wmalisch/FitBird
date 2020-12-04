/********************************************************************************
** Form generated from reading UI file 'activityhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYHISTORY_H
#define UI_ACTIVITYHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ActivityHistory
{
public:
    QLabel *label_activityHistory;

    void setupUi(QDialog *ActivityHistory)
    {
        if (ActivityHistory->objectName().isEmpty())
            ActivityHistory->setObjectName(QString::fromUtf8("ActivityHistory"));
        ActivityHistory->resize(900, 702);
        label_activityHistory = new QLabel(ActivityHistory);
        label_activityHistory->setObjectName(QString::fromUtf8("label_activityHistory"));
        label_activityHistory->setGeometry(QRect(30, 10, 841, 591));

        retranslateUi(ActivityHistory);

        QMetaObject::connectSlotsByName(ActivityHistory);
    } // setupUi

    void retranslateUi(QDialog *ActivityHistory)
    {
        ActivityHistory->setWindowTitle(QCoreApplication::translate("ActivityHistory", "Dialog", nullptr));
        label_activityHistory->setText(QCoreApplication::translate("ActivityHistory", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActivityHistory: public Ui_ActivityHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYHISTORY_H
