/**
 * @brief Code file to implement the GUI for the activites page
 * @details Code file to implement the methods of all buttons and labels on the activities page
 * @author Anton Krougly
 *
 */
#include "manageactivities.h"
#include "ui_manageactivities.h"
#include "facade.h"
#include <QMessageBox>
#include "activityhistory.h"
using namespace std;

/**
 * @brief Constructor of an activities object
 * @details Construct the activities widgets
 * @author Anton Krougly
 * @param *parent: Activities parent widget
 *
 */
ManageActivities::ManageActivities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageActivities)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of Activities page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
ManageActivities::~ManageActivities()
{
    delete ui;
}

/**
 * @brief Button that allows user to add a new activity manually
 * @details Verifies all parameters enterede by user and creates a new activity
 * @author Anton Krougly
 *
 */
void ManageActivities::on_pushButton_addActivity_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString startingHour = ui->lineEdit_sHour->text();
    QString startingMin = ui->lineEdit_sMin->text();
    QString endingHour = ui->lineEdit_eHour->text();
    QString endingMin = ui->lineEdit_eMin->text();
    QString duration = ui->lineEdit_duration->text();
    QString type = ui->lineEdit_type->text();
    QString steps = ui->lineEdit_steps->text();
    QString elevation = ui->lineEdit_elevation->text();
    QString distance = ui->lineEdit_distance->text();
    QString day = ui->lineEdit_day->text();
    QString month = ui->lineEdit_month->text();
    QString year = ui->lineEdit_year->text();

    vector<string> optionalArguments {"addActivity", name.toStdString(), startingHour.toStdString(), startingMin.toStdString(), endingHour.toStdString(), endingMin.toStdString(),
                duration.toStdString(), distance.toStdString(), type.toStdString(), elevation.toStdString(), steps.toStdString()};
    try
    {
        Facade::instance()->addActivity(Facade::currentUser, &optionalArguments);
        QMessageBox::information(this, "AddActivity", "Your activity has been added!");
    }
    catch(...)
    {
        QMessageBox::warning(this, "Create", "Make sure ALL boxes are properly filled! Try again.");
    }
}

/**
 * @brief Button that allows user to see all previously saved activities
 * @details Opens the activities log
 * @author Anton Krougly
 *
 */
void ManageActivities::on_pushButton_viewActivityHistory_clicked()
{
    activityHistory = new ActivityHistory(this);
    activityHistory->show();
}

/**
 * @brief Button that allows user to add a new activity manually
 * @details Verifies all parameters enterede by user and creates a new activity
 * @author Anton Krougly
 *
 */
void ManageActivities::on_pushButton_addWithDate_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString startingHour = ui->lineEdit_sHour->text();
    QString startingMin = ui->lineEdit_sMin->text();
    QString endingHour = ui->lineEdit_eHour->text();
    QString endingMin = ui->lineEdit_eMin->text();
    QString duration = ui->lineEdit_duration->text();
    QString type = ui->lineEdit_type->text();
    QString steps = ui->lineEdit_steps->text();
    QString elevation = ui->lineEdit_elevation->text();
    QString distance = ui->lineEdit_distance->text();
    QString day = ui->lineEdit_day->text();
    QString month = ui->lineEdit_month->text();
    QString year = ui->lineEdit_year->text();

    vector<string> arguments {"addActivity", name.toStdString(), day.toStdString(), month.toStdString(), year.toStdString(), startingHour.toStdString(), startingMin.toStdString(),
                endingHour.toStdString(), endingMin.toStdString(), duration.toStdString(), distance.toStdString(), type.toStdString(), elevation.toStdString(), steps.toStdString()};

    try
    {
        Facade::instance()->addActivity(Facade::currentUser, &arguments);
        QMessageBox::information(this, "AddActivity", "Your activity has been added!");
    }
    catch(...)
    {
        QMessageBox::warning(this, "Create", "Make sure ALL boxes are properly filled! Try again.");
    }
}

/**
 * @brief Button that allows user to delete an existing activity manually
 * @details Verifies all parameters enterede by user and delete an activity
 * @author Anton Krougly
 *
 */
void ManageActivities::on_pushButton_deleteActivity_clicked()
{
    QString name = ui->lineEdit_deleteName->text();
    QString year = ui->lineEdit_deleteYear->text();
    QString month = ui->lineEdit_deleteMonth->text();
    QString day = ui->lineEdit_deleteDay->text();

    vector<string> arguments {"deleteActivity", name.toStdString(), day.toStdString(), month.toStdString(), year.toStdString()};

    try
    {
        Facade::instance()->removeActivity(Facade::currentUser, &arguments);
        QMessageBox::information(this, "DeleteActivity", "Your activity has been deleted!");
    }
    catch(...)
    {
        QMessageBox::warning(this, "Create", "Make sure ALL boxes are properly filled! Try again.");
    }
}
