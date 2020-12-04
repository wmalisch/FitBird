/**
 * @brief Header file describing a ManageActivities class
 * @details Header file to describe a Manage Activities page which will allow users to add, delete and view activities
 * @author Anton Krougly
 *
 */
#ifndef MANAGEACTIVITIES_H
#define MANAGEACTIVITIES_H

#include <QDialog>
#include "activityhistory.h"

namespace Ui {
class ManageActivities;
}

class ManageActivities : public QDialog
{
    Q_OBJECT

public:
    explicit ManageActivities(QWidget *parent = nullptr);
    ~ManageActivities();

private slots:
    void on_pushButton_addActivity_clicked();

    void on_pushButton_viewActivityHistory_clicked();

    void on_pushButton_addWithDate_clicked();

    void on_pushButton_deleteActivity_clicked();

private:
    Ui::ManageActivities *ui;
    ActivityHistory *activityHistory;
};

#endif // MANAGEACTIVITIES_H
