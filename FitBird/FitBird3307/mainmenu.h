/**
 * @brief Header file describing a MainMenu class
 * @details Header file to describe a MainMenu which will include options to login and sign up
 * @author Anton Krougly
 *
 */
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "signup.h"
#include "dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::MainMenu *ui;
    SignUp *signUp;
    DashBoard *dashBoard;
};
#endif // MAINMENU_H
