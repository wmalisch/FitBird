/**
 * @brief Code file to implement the GUI for the profile page
 * @details Code file to implement the methods of all buttons and labels on profile page
 * @author Anton Krougly
 *
 */
#include "manageprofile.h"
#include "ui_manageprofile.h"
#include "facade.h"
#include <QMessageBox>
using namespace std;

/**
 * @brief Constructor of a ManageProfile object
 * @details Construct the ManageProfile widgets
 * @author Anton Krougly
 * @param *parent: ManageProfile parent widget
 *
 */
ManageProfile::ManageProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageProfile)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of ManageProfile page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
ManageProfile::~ManageProfile()
{
    delete ui;
}

/**
 * @brief Button that allows user to update information on their profile
 * @details Verifies all parameters enetered by user and updates profile info
 * @author Anton Krougly
 *
 */
void ManageProfile::on_pushButton_updateProfile_clicked()
{
    QString age = ui->lineEdit_newAge->text();
    if (age.toInt() != Facade::currentUser->getAge())
        Facade::currentUser->setAge(age.toInt());

    QString height = ui->lineEdit_newHeight->text();
    if (height.toInt() != Facade::currentUser->getHeight())
        Facade::currentUser->setHeight(height.toInt());

    QString weight = ui->lineEdit_newWeight->text();
    if (weight.toInt() != Facade::currentUser->getWeight())
        Facade::currentUser->setWeight(weight.toInt());

    QString sex = ui->lineEdit_newSex->text();
    if (sex.toStdString() != Facade::currentUser->getSex())
        Facade::currentUser->setSex(sex.toStdString());

    std::string getName = Facade::currentUser->getName();
    QString currName = QString::fromStdString(getName);
    ui->label_currName->setText("Name: " + currName);

    std::int32_t getAge = Facade::currentUser->getAge();
    QString currAge = QString::number(getAge);
    ui->label_currAge->setText("Age: " + currAge);

    std::int32_t getHeight = Facade::currentUser->getHeight();
    QString currHeight = QString::number(getHeight);
    ui->label_currHeight->setText("Height: " + currHeight);

    std::int32_t getWeight = Facade::currentUser->getWeight();
    QString currWeight = QString::number(getWeight);
    ui->label_currWeight->setText("Weight: " + currWeight);

    std::string getSex = Facade::currentUser->getSex();
    QString currSex = QString::fromStdString(getSex);
    ui->label_currSex->setText("Sex: " + currSex);

    QMessageBox::information(this, "Updated", "Your information has been updated!");
}


void ManageProfile::on_ManageProfile_accepted()
{
    // Does nothing. Was used for testing.
}

/**
 * @brief Button that allows user to see all current profile information
 * @details Displays all profile information on page
 * @author Anton Krougly
 *
 */
void ManageProfile::on_pushButton_clicked()
{
    std::string getName = Facade::currentUser->getName();
    QString name = QString::fromStdString(getName);
    ui->label_currName->setText("Name: " + name);

    std::int32_t getAge = Facade::currentUser->getAge();
    QString age = QString::number(getAge);
    ui->label_currAge->setText("Age: " + age);

    std::int32_t getHeight = Facade::currentUser->getHeight();
    QString height = QString::number(getHeight);
    ui->label_currHeight->setText("Height: " + height);

    std::int32_t getWeight = Facade::currentUser->getWeight();
    QString weight = QString::number(getWeight);
    ui->label_currWeight->setText("Weight: " + weight);

    std::string getSex = Facade::currentUser->getSex();
    QString sex = QString::fromStdString(getSex);
    ui->label_currSex->setText("Sex: " + sex);

    std::int32_t getStepGoal = Facade::currentUser->getStepGoal();
    QString stepGoal = QString::number(getStepGoal);
    ui->label_stepGoal->setText("Step Goal: " + stepGoal);
}

/**
 * @brief Button that allows user to update step goal
 * @details Updates step goal and displays it
 * @author Anton Krougly
 *
 */
void ManageProfile::on_pushButton_updateStepGoal_clicked()
{
    QString stepGoal = ui->lineEdit_newStepGoal->text();
    if (stepGoal.toInt() != Facade::currentUser->getStepGoal())
            Facade::currentUser->setStepGoal(stepGoal.toInt());

    std::int32_t getStepGoal = Facade::currentUser->getStepGoal();
    QString getstepGoal = QString::number(getStepGoal);
    ui->label_stepGoal->setText("Step Goal: " + stepGoal);
}
