/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_SignUp
{
public:
    QGroupBox *groupBox_signUp;
    QPushButton *pushButton_createAccount;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_newUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_newPassword;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_newAge;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_newHeight;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_newWeight;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_newSex;
    QLabel *label_CreateAccount;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(517, 420);
        groupBox_signUp = new QGroupBox(SignUp);
        groupBox_signUp->setObjectName(QString::fromUtf8("groupBox_signUp"));
        groupBox_signUp->setGeometry(QRect(120, 80, 271, 311));
        pushButton_createAccount = new QPushButton(groupBox_signUp);
        pushButton_createAccount->setObjectName(QString::fromUtf8("pushButton_createAccount"));
        pushButton_createAccount->setGeometry(QRect(80, 270, 111, 21));
        layoutWidget = new QWidget(groupBox_signUp);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 231, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_newUsername = new QLineEdit(layoutWidget);
        lineEdit_newUsername->setObjectName(QString::fromUtf8("lineEdit_newUsername"));

        horizontalLayout->addWidget(lineEdit_newUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_newPassword = new QLineEdit(layoutWidget);
        lineEdit_newPassword->setObjectName(QString::fromUtf8("lineEdit_newPassword"));

        horizontalLayout_2->addWidget(lineEdit_newPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        lineEdit_newAge = new QLineEdit(layoutWidget);
        lineEdit_newAge->setObjectName(QString::fromUtf8("lineEdit_newAge"));

        horizontalLayout_10->addWidget(lineEdit_newAge);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_newHeight = new QLineEdit(layoutWidget);
        lineEdit_newHeight->setObjectName(QString::fromUtf8("lineEdit_newHeight"));

        horizontalLayout_9->addWidget(lineEdit_newHeight);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_newWeight = new QLineEdit(layoutWidget);
        lineEdit_newWeight->setObjectName(QString::fromUtf8("lineEdit_newWeight"));

        horizontalLayout_8->addWidget(lineEdit_newWeight);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_newSex = new QLineEdit(layoutWidget);
        lineEdit_newSex->setObjectName(QString::fromUtf8("lineEdit_newSex"));

        horizontalLayout_7->addWidget(lineEdit_newSex);


        verticalLayout->addLayout(horizontalLayout_7);

        label_CreateAccount = new QLabel(SignUp);
        label_CreateAccount->setObjectName(QString::fromUtf8("label_CreateAccount"));
        label_CreateAccount->setGeometry(QRect(200, 30, 141, 41));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Dialog", nullptr));
        groupBox_signUp->setTitle(QCoreApplication::translate("SignUp", "SignUp", nullptr));
        pushButton_createAccount->setText(QCoreApplication::translate("SignUp", "Create Account!", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "Password:", nullptr));
        label_10->setText(QCoreApplication::translate("SignUp", "Age:", nullptr));
        label_9->setText(QCoreApplication::translate("SignUp", "Height (cm):", nullptr));
        label_8->setText(QCoreApplication::translate("SignUp", "Weight (kg):", nullptr));
        label_7->setText(QCoreApplication::translate("SignUp", "Sex (M/F)*:", nullptr));
        label_CreateAccount->setText(QCoreApplication::translate("SignUp", "Please fill in information!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
