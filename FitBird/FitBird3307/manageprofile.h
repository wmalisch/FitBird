/**
 * @brief Header file describing a ManageProfile class
 * @details Header file to describe a Manage Profile page which will include options to update profile information
 * @author Anton Krougly
 *
 */
#ifndef MANAGEPROFILE_H
#define MANAGEPROFILE_H

#include <QDialog>

namespace Ui {
class ManageProfile;
}

class ManageProfile : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProfile(QWidget *parent = nullptr);
    ~ManageProfile();

private slots:
    void on_pushButton_updateProfile_clicked();

    void on_ManageProfile_accepted();

    void on_pushButton_clicked();

    void on_pushButton_updateStepGoal_clicked();

private:
    Ui::ManageProfile *ui;
};

#endif // MANAGEPROFILE_H
