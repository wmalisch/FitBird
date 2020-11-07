/*
 * User.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Code file to implement the methods of the User class, that handles login and storing data of the user
 *
 */
 #include "User.h"
 
 using namespace std;
 
 /*
 * Name        : User
 * Description : Constructor for the user 
 * Parameter(s): name: The username of the user
 *				 password: The password to set for the user
 *				 age: Age of the user
 *				 weight: The weight in kg of the user
 *				 height: The height in cm of the user
 *				 sex: The sex of the user
 * Return      : N/A
 */
User::User(string name, string password, int age, int weight, int height, string sex)	{
	this->name = name;
	this->password = password;
	this->age = age;
	this->weight = weight;
	this->height = height;
	this->sex = sex;
	stepGoal = 0;
	activities = new vector<Activity *>();
}

/*
 * Name        : ~User
 * Description : Deletion of a user object
 * Parameter(s): N/A
 * Return      : N/A
 */
User::~User()	{
	delete activities;
}

/*
 * Name        : verify
 * Description : Method to verify if the parameter pass is the same as the users password
 * Parameter(s): pass: The entered value for the password to compare to
 * Return      : True if pass is the password of the user, false otherwise
 */
bool User::verify(string pass) const	{
	if(pass == password)	{
		return true;
	}
	return false;
}

/*
 * Name        : view
 * Description : Method to print out the user profile
 * Parameter(s): N/A
 * Return      : N/A
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

/*
 * Name        : showProgress
 * Description : Shows the progress over time of the user by showing activities and the users progress of step goals over time
 * Parameter(s): N/A
 * Return      : N/A
 */
 /*
void showProgress()	{
	//To be implemented
}
*/

/*
 * Name        : showActivities
 * Description : Shows all the activities of the user
 * Parameter(s): N/A
 * Return      : N/A
 */
void User::showActivities() const	{
	for(int index = 0; index < activities->size(); index++)	{
		cout << endl;
		(activities->at(index))->view();
	}
}

/*
 * Name        : addActivity
 * Description : Adds the new activity to the user if an activity already has the same name and date
 * Parameter(s): newActivity: The new activity to enter if not already same date and name of activity in user
 * Return      : N/A
 */
void User::addActivity(Activity * newActivity)	{
	//Try to find if activity is already in activities
	bool add = true;
	for(int index = 0; index < activities->size(); index++)	{
		Activity * activity = activities->at(index);
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
		activities->push_back(newActivity);
	}else	{
		cout << "\nActivity on that day with entered name already exists" << endl;
	}
}

/*
 * Name        : removeActivity
 * Description : Protected constructor that creates the one singleton object when it does not already exist
 * Parameter(s): name: The name of the activity to remove
 *				 day: The day of activity to remove
 *				 month: The month of activity to remove
 *				 year: The year of activity to remove
 * Return      : N/A
 */
void User::removeActivity(string name, int day, int month, int year)	{
	for(int index = 0; index < activities->size(); index++)	{
		Activity * activity = activities->at(index);
		if(name == activity->getName())	{
			struct tm date = activity->getDate();
			if(date.tm_mday == day && date.tm_mon == month && date.tm_year  == year)	{
				
				activities->erase(activities->begin() + index);
			}
		}
	}
}

/*
 * Name        : getName
 * Description : Getter method for the name of the user
 * Parameter(s): N/A
 * Return      : Name of the user
 */
string User::getName() const	{
	return name;
}

/*
 * Name        : getAge
 * Description : Getter method for the age of the user
 * Parameter(s): N/A
 * Return      : Age of the user
 */
int User::getAge() const	{
	return age;
}

/*
 * Name        : getWeight
 * Description : Getter method for the weight of the user
 * Parameter(s): N/A
 * Return      : Weight of the user
 */
int User::getWeight() const	{
	return height;
}

/*
 * Name        : getHeight
 * Description : Getter method for the height of the user
 * Parameter(s): N/A
 * Return      : Height of the user
 */
int User::getHeight() const	{
	return height;
}

/*
 * Name        : getSex
 * Description : Getter method for the sex of the user
 * Parameter(s): N/A
 * Return      : Sex of the user
 */
string User::getSex() const	{
	return sex;
}

/*
 * Name        : getStepGoal
 * Description : Getter method for the step goal of the user
 * Parameter(s): N/A
 * Return      : Step goal of the user
 */
int User::getStepGoal() const	{
	return stepGoal;
}

/*
 * Name        : setAge
 * Description : Setter method for the age of the user
 * Parameter(s): age: The age to set for the user
 * Return      : N/A
 */
void User::setAge(int newAge)	{
	age = newAge;
}

/*
 * Name        : setWeight
 * Description : Setter method for the weight of the user
 * Parameter(s): weight: The weight to set for the user
 * Return      : N/A
 */
void User::setWeight(int newWeight)	{
	weight = newWeight;
}

/*
 * Name        : setHeight
 * Description : Setter method for the height of the user
 * Parameter(s): height: The height to set for the user
 * Return      : N/A
 */
void User::setHeight(int newHeight)	{
	height = newHeight;
}

/*
 * Name        : setSex
 * Description : Setter method for the sex of the user
 * Parameter(s): sex: The sex to set for the user
 * Return      : N/A
 */
void User::setSex(string newSex)	{
	sex = newSex;
}

/*
 * Name        : setStepGoal
 * Description : Setter method for the step goal of the user
 * Parameter(s): steps: The step goal to set for the user
 * Return      : N/A
 */
void User::setStepGoal(int newSteps)	{
	stepGoal = newSteps;
}
		