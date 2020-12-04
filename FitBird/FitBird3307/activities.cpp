#include "manageactivities.h"
#include "ui_manageactivities.h"
#include "facade.h"
#include <QMessageBox>
using namespace std;

Activities::Activities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Activities)
{
    ui->setupUi(this);
}

Activities::~Activities()
{
    delete ui;
}

void Activities::on_pushButton_addActivity_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString startingHour = ui->lineEdit_sHour->text();
    QString startingMin = ui->lineEdit_sMin->text();
    QString endingHour = ui->lineEdit_eHour->text();
    QString endingMin = ui->lineEdit_eMin->text();
    QString duration = ui->lineEdit_duration->text();
    QString type = ui->lineEdit_type->text();
    QString elevation = ui->lineEdit_elevation->text();
    QString distance = ui->lineEdit_distance->text();
    QString day = ui->lineEdit_day->text();
    QString month = ui->lineEdit_month->text();
    QString year = ui->lineEdit_year->text();

    vector<string> arguments {"addActivity", name.toStdString(), day.toStdString(), month.toStdString(), year.toStdString(), startingHour.toStdString(), startingMin.toStdString(),
                endingHour.toStdString(), endingMin.toStdString(), duration.toStdString(), distance.toStdString(), type.toStdString(), elevation.toStdString()};

    //vector<string> arguments {"addUser", name.toStdString(), type.toStdString(), endingHour.toInt(), endingHour.toInt(), endingHour.toInt(), endingHour.toInt()};
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
