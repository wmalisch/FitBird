/**
 * @brief Code file to implement the GUI for the dashboard
 * @details Code file to implement the methods of all buttons and labels on dashboard
 * @author Anton Krougly
 *
 */

#include "dashboard.h"
#include "ui_dashboard.h"

/**
 * @brief Constructor of a Dashboard object
 * @details Construct the dashboard widgets
 * @author Anton Krougly
 * @param *parent: Dashboard parent widget
 *
 */
DashBoard::DashBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

/**
 * @brief Deletion of dashboard page
 * @details Nothing special
 * @author Anton Krougly
 *
 */
DashBoard::~DashBoard()
{
    delete ui;
}

/**
 * @brief Button that leads to profile page
 * @details Opens up profile page
 * @author Anton Krougly
 *
 */
void DashBoard::on_pushButton_manageProfile_clicked()
{
    manageProfile = new ManageProfile(this);
    manageProfile->show();
}

/**
 * @brief Button that leads to activities page
 * @details Opens up activity page
 * @author Anton Krougly
 *
 */
void DashBoard::on_pushButton_manageActivities_clicked()
{
    manageActivities = new ManageActivities(this);
    manageActivities->show();
}
