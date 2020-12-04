/**
 * @brief Header file describing a DashBoard class
 * @details Header file to describe a DashBoard which will include options to manage a user's profile and activities
 * @author Anton Krougly
 *
 */
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "manageprofile.h"
#include "manageactivities.h"


namespace Ui {
class DashBoard;
}

class DashBoard : public QDialog
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private slots:
    void on_pushButton_manageProfile_clicked();

    void on_pushButton_manageActivities_clicked();

private:
    Ui::DashBoard *ui;
    ManageProfile *manageProfile;
    ManageActivities *manageActivities;

};

#endif // DASHBOARD_H
