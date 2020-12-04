/**
 * @brief Header file describing a SignUp class
 * @details Header file to describe a Sign up page which will allow a user to create a new account
 * @author Anton Krougly
 *
 */
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_createAccount_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
