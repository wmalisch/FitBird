/**
 * @brief Code file to implement the methods of the Walk class
 * @details Code file to implement methods of the Walk class for the user to create the Walk activity
 * @author Matthew Temniuk
 *
 */
#include "Walk.h"

using namespace std;

/**
 * @brief Creator for a Walk to be added to a user
 * @details Creator for a Walk to be added to a user. Setting the values given to the stored values
 * @author Matthew Temniuk
 * @param name: The name of the activity
 * @param user: The user the activity is associated with
 * @param date: The date the activity was done
 * @param start: The start time of the activity
 * @param end: The end time of the activity
 * @param duration: The time from start to conclusion  of activity
 * @param distance: The distance traveled on the activity
 * @param steps: The amount of steps taken in activity
 * @param type: The type of activity
 * @param elevationGain: The elevation gain of the activity
 * 
 */	
Walk::Walk(string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, int steps, std::string type, double elevationGain): Activity(name, user, date, start, end, duration, distance, type, elevationGain)	
{
	this->steps = steps;
	
	this->caloriesBurnt = this->calculateCaloriesBurnt(user, this);
}

/**
 * @brief Deletion of a Walk object
 * @details Deletion of a Walk object
 * @author Matthew Temniuk
 * 
 */
Walk::~Walk()	{
	
}

/**
 * @brief Prints out information of the Walk activity
 * @details Format the Walk activity information and print it out to the console
 * @author Matthew Temniuk
 *
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

/**
 * @brief Sends back a string to use for csv to save to file as
 * @details Returns a string of how to format the Walk activity to be saved into the save file
 * @author Matthew Temniuk
 * @return String to use to save walking activity
 * 
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
	saveString += to_string(elevationGain) + "," + to_string(steps) + "\n";
		
	return saveString;
}


/**
 * @brief Getter method of the steps of a walk activity
 * @details Getter method of the steps of a walk activity
 * @author Matthew Temniuk
 * @return name of activity
 *
 */
int Walk::getSteps() const	{
	return steps;
}

/**
 * @brief Setter method of the steps of a walk activity
 * @details Setter method of the steps of a walk activity
 * @author Matthew Temniuk
 * @param newSteps: New value to set the steps of the walk to
 * 
 */
void Walk::setSteps(int newSteps)	{
	steps = newSteps;
}

/**
 * @brief Protected method to calculate the calories burnt for this activity and user
 * @details Protected method used in constructor to calculate the calories burnt for the user and activity
 * @author 
 * @param user: The user to calculate the calories burnt of
 * @param activity: The activity to use to calculate the calories burnt with the user
 * @return Amount of calories burnt with this activity for the user
 *
 */
int Walk::calculateCaloriesBurnt(User * user, Walk * activity) 	{
	//To do later for calculating calories
	return 0;
}