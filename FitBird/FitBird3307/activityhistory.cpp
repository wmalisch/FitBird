/**
 * @brief Code file to implement the GUI for the ActivityHistory page
 * @details Code file to implement the page which will display all of the past activities for the user
 * @author Anton Krougly
 *
 */
#include "activityhistory.h"
#include "ui_activityhistory.h"
#include "facade.h"
#include "activity.h"
#include <QDateTime>

/**
 * @brief Constructor of a ActivityHistory object
 * @details Construct the widgets
 * @author Anton Krougly
 * @param *parent: Page parent widget
 *
 */
ActivityHistory::ActivityHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityHistory)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of ActivityHistory page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
ActivityHistory::~ActivityHistory()
{
    delete ui;
}

/**
 * @brief Signal that will show a page with all past activities
 * @details Upon opening the window, all past activities will be added to a list and displayed
 * @author Anton Krougly
 *
 */
void ActivityHistory::showEvent(QShowEvent *ev)
{
    QDialog::showEvent(ev);

    QString text;
    for(int index = 0; index < Facade::currentUser->getActivities().size(); index++)	{
        Activity * activity = Facade::currentUser->getActivities().at(index);
        QString act = QString::fromStdString(activity->getName());
        QString typ = QString::fromStdString(activity->getType());
        QString dist = QString::number(activity->getDistance());
        QString dur = QString::number(activity->getDuration());
        QString ele = QString::number(activity->getElevationGain());

        QString day = QDateTime(QDate(activity->getDate().tm_year, activity->getDate().tm_mon, activity->getDate().tm_mday), QTime(0, 0)).toString("yyyy, dd MMM");

        QString entry = QString("Name: %1 \t\t| Type: %2 \t\t| Distance: %3 \t\t| Duration: %4 \t\t| Elevation Gain: %5 \t\t| Day: %6").arg(act, typ, dist, dur, ele, day);

        text += entry;
        text += "\r\n";
    }

    ui->label_activityHistory->setText(text);
}
