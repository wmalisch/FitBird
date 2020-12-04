/**
 * @brief Code file to implement the GUI for the main menu page
 * @details Code file to implement the methods of all buttons and labels on menu page
 * @author Anton Krougly
 *
 */
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>
#include "facade.h"
using namespace std;

/**
 * @brief Constructor of a MainMenu object
 * @details Construct the MainMenu widgets
 * @author Anton Krougly
 * @param *parent: MainMenu parent widget
 *
 */
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of mainmenu page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
MainMenu::~MainMenu()
{
    delete ui;
}

/**
 * @brief Button that allows user to log in
 * @details Verifies credentials and opens up the dashboard upon successful login
 * @author Anton Krougly
 *
 */
void MainMenu::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    vector<string> arguments {"login", username.toStdString(), password.toStdString()};

    try
    {
        Facade::currentUser = Facade::instance()->login(&arguments);
        QMessageBox::information(this, "Login", "Username and Password is correct. Welcome! :)");
        hide();
        dashBoard = new DashBoard(this);
        dashBoard->show();
    }
    catch(exception ex)
    {
        QMessageBox::warning(this, "Login", "Invalid Credentials");
    }
    catch(...)
    {
        QMessageBox::warning(this, "Login", "Invalid Credentials");
    }
}

/**
 * @brief Button that allows user to register a new account
 * @details Opens up the sign up page to allow user to create new account
 * @author Anton Krougly
 *
 */
void MainMenu::on_pushButton_register_clicked()
{
    signUp = new SignUp(this);
    signUp->show();
}

