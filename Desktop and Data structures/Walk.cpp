/*
 * Walk.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Code file to implement the methods of the Walk class
 *
 */
#include "Walk.h"

using namespace std;

/*
 * Name        : Walk
 * Description : Deletion of a Walk object
 * Parameter(s): name: The name of the activity
 *				 user: The user the activity is associated with
 *				 date: The date the activity was done
 *				 start: The start time of the activity
 *				 end: The end time of the activity
 *				 duration: The time from start to conclusion  of activity
 *				 distance: The distance traveled on the activity
 *				 steps: The amount of steps taken in activity
 *				 type: The type of activity
 *				 elevationGain: The elevation gain of the activity
 * Return      : N/A
 */	
Walk::Walk(string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, int steps, std::string type, double elevationGain)	{
	this->name = name;
	this->user = user;
	this->date = date;
	this->start = start;
	this->end = end;
	this->duration = duration;
	this->distance = distance;
	this->steps = steps;
	this->type = type;
	this->elevationGain = elevationGain;
	
	this->caloriesBurnt = this->calculateCaloriesBurnt(user, this);
}

/*
 * Name        : ~Walk
 * Description : Deletion of a Walk object
 * Parameter(s): N/A
 * Return      : N/A
 */
Walk::~Walk()	{
	
}

/*
 * Name        : view
 * Description : Prints out information of the Walk activity
 * Parameter(s): N/A
 * Return      : N/A
 */
Walk::view() const	{
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "User: " << user->getName() << endl;
	char buffer [80];
	strftime(buffer, 60, "%Y-%m-%d", &date); 
	cout << "Date: " << buffer << endl;
	strftime(buffer, 60, "%I:%M%p", &start); 
	cout << "Start time: " << buffer << endl;
	strftime(buffer, 60, "%I:%M%p", &end); 
	cout << "End time: " << buffer << endl;
	cout << "Duration: " << duration << endl;
	cout << "Distance: " << distance << endl;
	cout << "Steps: " << steps << endl;
	cout << "Type: " << type << endl;
	cout << "Elevation gain: " << elevationGain << endl;
	cout << "Calories burnt: " << caloriesBurnt << endl;
}

/*
 * Name        : getSteps
 * Description : Getter method of the steps of a walk activity
 * Parameter(s): N/A
 * Return      : name of activity
 */
int Walk::getSteps() const	{
	return steps;
}

/*
 * Name        : SetSteps
 * Description : Setter method of the steps of a walk activity
 * Parameter(s): steps: New value to set the steps of the walk to
 * Return      : N/A
 */
void Walk::setSteps(int steps)	{
	this->steps = steps;
}

/*
 * Name        : calculateCaloriesBurnt
 * Description : Protected method to calculate the calories burnt for this activity and user
 * Parameter(s): user: The user to calculate the calories burnt of
 *				 activity: The activity to use to calculate the calories burnt with the user
 * Return      : Amount of calories burnt with this activity for the user
 */
static int Walk::calculateCaloriesBurnt(User * user, Walk * activity) const	{
	//To do later for calculating calories
	return 0;
}