/**
 * @brief Code file to implement the methods of the Activity class
 * @details Code file to implement the methods of the base Activity used to track a users fitness activity
 * @author Matthew Temniuk
 *
 */
#include "../headers/Activity.h"
 
using namespace std;

/**
 * @brief Constructor of an Activity object
 * @details Construct the values of activity and create the activity
 * @author Matthew Temniuk
 * @param name: The name of the activity
 * @param user: The user the activity is associated with
 * @param date: The date the activity was done
 * @param start: The start time of the activity
 * @param end: The end time of the activity
 * @param duration: The time from start to conclusion  of activity
 * @param distance: The distance traveled on the activity
 * @param type: The type of activity
 * @param elevationGain: The elevation gain of the activity
 * 
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

/**
 * @brief Deletion of a Activity object
 * @details Delete the Activity does nothing special
 * @author Matthew Temniuk
 *
 */
Activity::~Activity()	{
	
}

/**
 * @brief Prints out information of the activity
 * @details Print to the screen the details of the activity
 * @author Matthew Temniuk
 *
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

/**
 * @brief Returns a string to use to save for a csv file
 * @details Formats the string to be saved into file to keep as storage
 * @author Matthew Temniuk
 * @return String to use to save activity
 *
 */
string Activity::saveString() const	{
	string saveString = "";
	string userName = user->getName();
	
	saveString += "'" + userName + "',";
	saveString += "'" + type + "',";
	saveString += "'" + name + "',";
	saveString += to_string(date.tm_mday) + "," + to_string(date.tm_mon) + "," + to_string(date.tm_year) + ",";
	saveString += to_string(start.tm_hour) + "," + to_string(start.tm_min) + "," + to_string(end.tm_hour) + "," + to_string(end.tm_min) + ",";
	saveString += to_string(duration) + "," + to_string(distance) + ",";
	saveString += to_string(elevationGain) + "\n";
		
	return saveString;
}


/**
 * @brief Getter method of the name of activity
 * @details Getter method of the name of activity
 * @author Matthew Temniuk
 * @return name of activity
 *
 */
std::string Activity::getName() const	{
	return name;
}

/**
 * @brief Getter method of the user of activity
 * @details Getter method of the user of activity
 * @author Matthew Temniuk
 * @return Pointer to the user that did this activity
 *
 */
User * Activity::getUser() const	{
	return user;
}

/**
 * @brief Getter method of the date of activity
 * @details Getter method of the date of activity
 * @author Matthew Temniuk
 * @return struct tm that has the day, month and year of the activity
 *
 */
struct tm Activity::getDate() const	{
	return date;
}

/**
 * @brief Getter method of the start time of activity
 * @details Getter method of the start time of activity
 * @author Matthew Temniuk
 * @return struct tm that has the starting hour and minute of the activity
 *
 */
struct tm Activity::getStart() const	{
	return start;
}

/**
 * @brief Getter method of the end time of activity
 * @details Getter method of the end time of activity
 * @author Matthew Temniuk
 * @return struct tm that has the ending hour and minute of the activity
 *
 */
struct tm Activity::getEnd() const	{
	return end;
}

/**
 * @brief Getter method of the duration of activity
 * @details Getter method of the duration of activity
 * @author Matthew Temniuk
 * @return duration of the activity
 *
 */
int Activity::getDuration() const	{
	return duration;
}

/**
 * @brief Getter method of the distance of activity
 * @details Getter method of the distance of activity
 * @author Matthew Temniuk
 * @return distance of the activity
 * 
 */
double Activity::getDistance() const	{
	return distance;
}

/**
 * @brief Getter method of the type of activity
 * @details Getter method of the type of activity
 * @author Matthew Temniuk
 * @return Type of activity
 *
 */
std::string Activity::getType() const	{
	return type;
}

/**
 * @brief Getter method of the elevation gain of activity
 * @details Getter method of the elevation gain of activity
 * @author Matthew Temniuk
 * @return elevation gain of the activity
 *
 */
double Activity::getElevationGain() const	{
	return elevationGain;
}

/**
 * @brief Setter method of the date of activity
 * @details Setter method of the date of activity
 * @author Matthew Temniuk
 * @param date: The date to set the activity to
 * 
 */
void Activity::setDate(struct tm date)	{
	this->date = date;
}

/**
 * @brief Setter method of the start time of activity
 * @details Setter method of the start time of activity
 * @author Matthew Temniuk
 * @param start: The start time to set the activity to
 * 
 */
void Activity::setStart(struct tm start)	{
	this->start = start;
}

/**
 * @brief Setter method of the end time of activity
 * @details Setter method of the end time of activity
 * @author Matthew Temniuk
 * @param end: The end time to set the activity to
 * 
 */
void Activity::setEnd(struct tm end)	{
	this->end = end;
}

/**
 * @brief Setter method of the duration of the activity
 * @details Setter method of the duration of the activity
 * @author Matthew Temniuk
 * @param duration: The duration to set the activity to
 * 
 */
void Activity::setDuration(int duration)	{
	this->duration = duration;
}

/**
 * @brief Return the calories brunt by the user
 * @details Return the calories brunt by the user
 * @author 
 * @param duration: The duration to set the activity to
 * 
 */
int Activity::calculateCaloriesBurnt(User * user, Activity * activity)	{
	//To do for later time
	return 0;
}
