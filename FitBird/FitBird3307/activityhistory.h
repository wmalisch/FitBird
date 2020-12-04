/**
 * @brief Header file describing the ActivityHistory class
 * @details Header file to describe an activity history page which will include all of the past activities
 * @author Anton Krougly
 *
 */
#ifndef ACTIVITYHISTORY_H
#define ACTIVITYHISTORY_H

#include <QDialog>

namespace Ui {
class ActivityHistory;
}

class ActivityHistory : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityHistory(QWidget *parent = nullptr);
    ~ActivityHistory();


protected:
      void showEvent(QShowEvent *ev);

private:
    Ui::ActivityHistory *ui;
};

#endif // ACTIVITYHISTORY_H
