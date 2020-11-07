/*
 * Activity.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Code file to implement the methods of the Activity class
 *
 */
#include "Activity.h"
 
using namespace std;

/*
 * Name        : Activity
 * Description : Constructor of an Activity object
 * Parameter(s): name: The name of the activity
 *				 user: The user the activity is associated with
 *				 date: The date the activity was done
 *				 start: The start time of the activity
 *				 end: The end time of the activity
 *				 duration: The time from start to conclusion  of activity
 *				 distance: The distance traveled on the activity
 *				 type: The type of activity
 *				 elevationGain: The elevation gain of the activity
 * Return      : N/A
 */
Activity::Activity(std::string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, std::string type, double elevationGain)	{
	this->name = name;
	this->user = user;
	this->date = date;
	this->start = start;
	this->end = end;
	this->duration = duration;
	this->distance = distance;
	this->type = type;
	this->elevationGain = elevationGain;
	
	this->caloriesBurnt = 0;
}

/*
 * Name        : ~Activity
 * Description : Deletion of a Activity object
 * Parameter(s): N/A
 * Return      : N/A
 */
Activity::~Activity()	{
	
}

/*
 * Name        : view
 * Description : Prints out information of the activity
 * Parameter(s): N/A
 * Return      : N/A
 */
void Activity::view() const	{
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
	cout << "Type: " << type << endl;
	cout << "Elevation gain: " << elevationGain << endl;
	cout << "Calories burnt: " << caloriesBurnt << endl;
	
}

/*
 * Name        : getName
 * Description : Getter method of the name of activity
 * Parameter(s): N/A
 * Return      : name of activity
 */
std::string Activity::getName() const	{
	return name;
}

/*
 * Name        : getUser
 * Description : Getter method of the user of activity
 * Parameter(s): N/A
 * Return      : Pointer to the user that did this activity
 */
User * Activity::getUser() const	{
	return user;
}

/*
 * Name        : getDate
 * Description : Getter method of the date of activity
 * Parameter(s): N/A
 * Return      : struct tm that has the day, month and year of the activity
 */
struct tm Activity::getDate() const	{
	return date;
}

/*
 * Name        : getStart
 * Description : Getter method of the start time of activity
 * Parameter(s): N/A
 * Return      : struct tm that has the starting hour and minute of the activity
 */
struct tm Activity::getStart() const	{
	return start;
}

/*
 * Name        : getEnd
 * Description : Getter method of the end time of activity
 * Parameter(s): N/A
 * Return      : struct tm that has the ending hour and minute of the activity
 */
struct tm Activity::getEnd() const	{
	return end;
}

/*
 * Name        : getDuration
 * Description : Getter method of the duration of activity
 * Parameter(s): N/A
 * Return      : duration of the activity
 */
int Activity::getDuration() const	{
	return duration;
}

/*
 * Name        : getDistance
 * Description : Getter method of the distance of activity
 * Parameter(s): N/A
 * Return      : distance of the activity
 */
double Activity::getDistance() const	{
	return distance;
}

/*
 * Name        : getType
 * Description : Getter method of the type of activity
 * Parameter(s): N/A
 * Return      : Type of activity
 */
std::string Activity::getType() const	{
	return type;
}

/*
 * Name        : getElevationGain
 * Description : Getter method of the elevation gain of activity
 * Parameter(s): N/A
 * Return      : elevation gain of the activity
 */
double Activity::getElevationGain() const	{
	return elevationGain;
}

/*
 * Name        : setDate
 * Description : Setter method of the date of activity
 * Parameter(s): date: The date to set the activity to
 * Return      : N/A
 */
void Activity::setDate(struct tm date)	{
	this->date = date;
}

/*
 * Name        : setStart
 * Description : Setter method of the start time of activity
 * Parameter(s): start: The start time to set the activity to
 * Return      : N/A
 */
void Activity::setStart(struct tm start)	{
	this->start = start;
}

/*
 * Name        : setEnd
 * Description : Setter method of the end time of activity
 * Parameter(s): end: The end time to set the activity to
 * Return      : N/A
 */
void Activity::setEnd(struct tm end)	{
	this->end = end;
}

/*
 * Name        : setDuration
 * Description : Setter method of the duration of the activity
 * Parameter(s): duration: The duration to set the activity to
 * Return      : N/A
 */
void Activity::setDuration(int duration)	{
	this->duration = duration;
}

/*
 * Name        : calculateCaloriesBurnt
 * Description : Return the calories brunt by the 
 * Parameter(s): duration: The duration to set the activity to
 * Return      : N/A
 */
int Activity::calculateCaloriesBurnt(User * user, Activity * activity)	{
	//To do for later time
	return 0;
}
