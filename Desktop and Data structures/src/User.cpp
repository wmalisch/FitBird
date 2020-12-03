/**
 * @brief Code to implement the User class describing the fitness user
 * @details Code file to implement the methods of the User class, that handles login and storing data of the user
 * @author Matthew Temniuk
 *
 */
 #include "../headers/User.h"
 
 using namespace std;
 
 /**
 * @brief Constructor for the user 
 * @details Constructor for the user to input values desired to create the user
 * @author Matthew Temniuk
 * @param name: The username of the user
 * @param password: The password to set for the user
 * @param age: Age of the user
 * @param weight: The weight in kg of the user
 * @param height: The height in cm of the user
 * @param sex: The sex of the user
 *
 */
User::User(string name, string password, int age, int weight, int height, string sex)	{
	this->name = name;
	this->password = password;
	this->age = age;
	this->weight = weight;
	this->height = height;
	this->sex = sex;
	stepGoal = 0;
}

/**
 * @brief Deletion of a user object
 * @details Delete the User and delete all the activities in it's activity list
 * @author Matthew Temniuk
 *
 */
User::~User()	{
	//Delete the activities
	for(int index = 0; index < activities.size(); index++)	{
		Activity * activity = activities.at(index);
		delete activity;
	}
}

/**
 * @brief Method to verify if the parameter pass is the same as the users password
 * @details Check if the password given is the password for the user
 * @author Matthew Temniuk
 * @param pass: The entered value for the password to compare to
 * @return True if pass is the password of the user, false otherwise
 *
 */
bool User::verify(string pass) const	{
	if(pass == password)	{
		return true;
	}
	return false;
}

/**
 * @brief Method to print out the user profile
 * @details Formats and outputs the user profile to the screen 
 * @author Matthew Temniuk
 * 
 */
void User::view() const	{
	cout << endl;
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "weight: " << weight << endl;
	cout << "height: " << height << endl;
	cout << "sex: " << sex << endl;
	cout << "Step goal: " << stepGoal << endl;
}

/**
 * @brief Sends back a string to use for csv to save to file as
 * @details Returns the string to how the user should be saved into a save file
 * @author Matthew Temniuk
 * @return String to use to save user to file
 *
 */
string User::saveString() const 	{
	string saveString = "";
	
	saveString += "'" + name + "',";
	saveString += "'" + password + "',";
	saveString += "'" + sex + "',";
	saveString += to_string(age) + "," + to_string(weight) + "," + to_string(height) + "," + to_string(stepGoal) + "\n";
		
	return saveString;
}


/**
 * @brief Show the progress done ordered by the user input
 * @details Shows the progress over time of the user by showing activities and the users progress of step goals sorted by user input
 * @author 
 * @param orderedBy: A string that tells what field the progress should be sorted by
 *
 */
void showProgress(string orderedBy)	{
	//To be implemented
}


/**
 * @brief Shows all the activities of the user
 * @details Show every activity entered for this user
 * @author Matthew Temniuk
 *
 */
void User::showActivities() const	{
	for(int index = 0; index < activities.size(); index++)	{
		cout << endl;
		(activities.at(index))->view();
	}
}

/**
 * @brief Add the activity to this users list
 * @details Adds the new activity to the user if an activity already has the same name and date
 * @author Matthew Temniuk
 * @param newActivity: The new activity to enter if not already same date and name of activity in user
 * 
 */
void User::addActivity(Activity * newActivity)	{
	//Try to find if activity is already in activities
	bool add = true;
	for(int index = 0; index < activities.size(); index++)	{
		Activity * activity = activities.at(index);
		if(activity->getName() == newActivity->getName())	{
			struct tm date1 = activity->getDate();
			struct tm date2 = newActivity->getDate();
			
			if(date1.tm_mday == date2.tm_mday && date1.tm_mon == date2.tm_mon && date1.tm_year == date2.tm_year)	{
				add = false;
				break;
			}
		}
	}
	if(add)	{
		activities.push_back(newActivity);
	}else	{
		cout << "\nActivity on that day with entered name already exists" << endl;
	}
}

/**
 * @brief Remove the activity of the user with the name and matches the date
 * @details Remove the activity from the list from this user with the name and the same date information
 * @author Matthew Temniuk
 * @param name: The name of the activity to remove
 * @param day: The day of activity to remove
 * @param month: The month of activity to remove
 * @param year: The year of activity to remove
 * 
 */
void User::removeActivity(string name, int day, int month, int year)	{
	for(int index = 0; index < activities.size(); index++)	{
		Activity * activity = activities.at(index);
		if(name == activity->getName())	{
			struct tm date = activity->getDate();
			if(date.tm_mday == day && date.tm_mon == month && date.tm_year  == year)	{
				
				activities.erase(activities.begin() + index);
			}
		}
	}
}

/**
 * @brief Getter method for the name of the user
 * @details Getter method for the name of the user
 * @author Matthew Temniuk
 * @return Name of the user
 *
 */
string User::getName() const	{
	return name;
}

/**
 * @brief Getter method for the age of the user
 * @details Getter method for the age of the user
 * @author Matthew Temniuk
 * @return Age of the user
 *
 */
int User::getAge() const	{
	return age;
}

/**
 * @brief Getter method for the weight of the user
 * @details Getter method for the weight of the user
 * @author Matthew Temniuk
 * @return Weight of the user
 *
 */
int User::getWeight() const	{
	return height;
}

/**
 * @brief Getter method for the height of the user
 * @details Getter method for the height of the user
 * @author Matthew Temniuk
 * @return Height of the user
 *
 */
int User::getHeight() const	{
	return height;
}

/**
 * @brief Getter method for the sex of the user
 * @details Getter method for the sex of the user
 * @author Matthew Temniuk
 * @return Sex of the user
 *
 */
string User::getSex() const	{
	return sex;
}


/**
 * @brief Getter method for the list of activities of the user
 * @details Getter method for the list of activities of the user
 * @author Matthew Temniuk
 * @return Vector of activities of user
 *
 */
vector<Activity *> User::getActivities() const	{
	return activities;
}
	
/**
 * @brief Getter method for the step goal of the user
 * @details Getter method for the step goal of the user
 * @author Matthew Temniuk
 * @return Step goal of the user
 *
 */
int User::getStepGoal() const	{
	return stepGoal;
}

/**
 * @brief Setter method for the age of the user
 * @details Setter method for the age of the user
 * @author Matthew Temniuk
 * @param newAge: The age to set for the user
 * 
 */
void User::setAge(int newAge)	{
	age = newAge;
}

/**
 * @brief Setter method for the weight of the user
 * @details Setter method for the weight of the user
 * @author Matthew Temniuk
 * @param newWeight: The weight to set for the user
 *
 */
void User::setWeight(int newWeight)	{
	weight = newWeight;
}

/**
 * @brief Setter method for the height of the user
 * @details Setter method for the height of the user
 * @author Matthew Temniuk
 * @param newHeight: The height to set for the user
 *
 */
void User::setHeight(int newHeight)	{
	height = newHeight;
}

/**
 * @brief Setter method for the sex of the user
 * @details Setter method for the sex of the user
 * @author Matthew Temniuk
 * @param newSex: The sex to set for the user
 * 
 */
void User::setSex(string newSex)	{
	sex = newSex;
}

/**
 * @brief Setter method for the step goal of the user
 * @details Setter method for the step goal of the user
 * @author Matthew Temniuk
 * @param newSteps: The step goal to set for the user
 * 
 */
void User::setStepGoal(int newSteps)	{
	stepGoal = newSteps;
}
		