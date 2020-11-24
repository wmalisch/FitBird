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
Walk::Walk(string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, int steps, std::string type, double elevationGain): Activity(name, user, date, start, end, duration, distance, type, elevationGain)	
{
	this->steps = steps;
	
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
void Walk::view() const	{
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "User: " << user->getName() << endl;
	char buffer1 [60];
	strftime(buffer1, 60, "%d-%m-%Y", &date); 
	cout << "Date: " << buffer1 << endl;
	char buffer2 [60];
	strftime(buffer2, 60, "%I:%M%p", &start); 
	cout << "Start time: " << buffer2 << endl;
	char buffer3 [60];
	strftime(buffer3, 60, "%I:%M%p", &end); 
	cout << "End time: " << buffer3 << endl;
	cout << "Duration: " << duration << endl;
	cout << "Distance: " << distance << endl;
	cout << "Steps: " << steps << endl;
	cout << "Type: " << type << endl;
	cout << "Elevation gain: " << elevationGain << endl;
	cout << "Calories burnt: " << caloriesBurnt << endl;
}

/*
 * Name        : saveString
 * Description : Sends back a string to use for csv to save to file as
 * Parameter(s): N/A
 * Return      : String to use to save walking activity
 */
std::string Walk::saveString() const	{
	string saveString = "";
	string userName = user->getName();
	
	saveString += "'" + userName + "',";
	saveString += "'" + type + "',";
	saveString += "'" + name + "',";
	saveString += to_string(date.tm_mday) + "," + to_string(date.tm_mon) + "," + to_string(date.tm_year) + ",";
	saveString += to_string(start.tm_hour) + "," + to_string(start.tm_min) + "," + to_string(end.tm_hour) + "," + to_string(end.tm_min) + ",";
	saveString += to_string(duration) + "," + to_string(distance) + ",";
	saveString += to_string(elevationGain) + "," + to_string(caloriesBurnt) + "," + to_string(steps) + "\n";
		
	return saveString;
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
void Walk::setSteps(int newSteps)	{
	steps = newSteps;
}

/*
 * Name        : calculateCaloriesBurnt
 * Description : Protected method to calculate the calories burnt for this activity and user
 * Parameter(s): user: The user to calculate the calories burnt of
 *				 activity: The activity to use to calculate the calories burnt with the user
 * Return      : Amount of calories burnt with this activity for the user
 */
int Walk::calculateCaloriesBurnt(User * user, Walk * activity) 	{
	//To do later for calculating calories
	return 0;
}