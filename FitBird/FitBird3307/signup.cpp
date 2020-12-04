/**
 * @brief Code file to implement the GUI for the SignUp page
 * @details Code file to implement the methods of all buttons and labels on SignUp page
 * @author Anton Krougly
 *
 */
#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include "facade.h"
using namespace std;

/**
 * @brief Constructor of a SignUp object
 * @details Construct the SignUp widgets
 * @author Anton Krougly
 * @param *parent: SignUp parent widget
 *
 */
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of SignUp page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
SignUp::~SignUp()
{
    delete ui;
}

/**
 * @brief Button that allows user to create a new account
 * @details Verifies all parameters enetered by user and creates a new account
 * @author Anton Krougly
 *
 */
void SignUp::on_pushButton_createAccount_clicked()
{
    QString username = ui->lineEdit_newUsername->text();
    QString password = ui->lineEdit_newPassword->text();
    QString age = ui->lineEdit_newAge->text();
    QString height = ui->lineEdit_newHeight->text();
    QString weight = ui->lineEdit_newWeight->text();
    QString sex = ui->lineEdit_newSex->text();

    vector<string> arguments {"addUser", username.toStdString(), password.toStdString(),
                age.toStdString(), weight.toStdString(), height.toStdString(), sex.toStdString()};

    try
    {
        Facade::instance()->addUser(&arguments);
        QMessageBox::information(this, "AddUser", "Thank you for creating an account! Go back to home page to log in. :)");
    }
    catch(...)
    {
        QMessageBox::warning(this, "Create", "Make sure ALL boxes are properly filled! Try again.");
    }
}

