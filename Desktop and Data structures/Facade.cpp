/*
 * Facade.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : 
 *
 */
 #include "Facade.h"
 #define USER_SAVE_FILE "saved_users.csv"
 #define ACTIVITY_SAVE_FILE "saved_activities.csv"
 
 using namespace std;
	
 Facade* Facade::_instance = NULL;
 
 /*
 * Name        : instance
 * Description : Get the singleton instance of the facade, if one does not exist already create it
 * Parameter(s): N/A
 * Return      : pointer to the instance of the facade
 */
Facade * Facade::instance()	{
	 if(_instance == NULL)	{
		_instance = new Facade();
	 }
	 return _instance;
 }
 
 /*
 * Name        : addUser
 * Description : Takes arguments and creates a user if the username is not already taken
 * Parameter(s): arguments: A vector of strings with the arguments to create a user
 * Return      : N/A
 */
void Facade::addUser(std::vector<std::string>* arguments)	{
	// command username password age weight(kg) height(cm) sex(M/F)
	string message;
	if(arguments->size() != 7)	{
		string message = "\nIncorrect number of arguments\n";
		throw message;
	}
	string username = arguments->at(1);
	string password = arguments->at(2);
	int age = stoi(arguments->at(3));
	int weight = stoi(arguments->at(4));
	int height = stoi(arguments->at(5));
	string sex = arguments->at(6);
	
	//Check if the user with username already exists
	for(int index = 0; index < users.size(); index++)	{
		if(username == (users.at(index))->getName())	{
			message = "\nUsername taken\n";
			throw message;
		}
	}
	
	User * newUser = new User(username, password, age, weight, height, sex);
	users.push_back(newUser);
}

/*
 * Name        : login
 * Description : Takes arguments and tries to login as the user
 * Parameter(s): arguments: A vector of strings with the arguments to login as a user
 * Return      : The user with the username and password if login succesful, else a string exception
 */
User * Facade::login(std::vector<std::string>* arguments)	{
	string message;
	//username password
	if(arguments->size() != 3)	{
		message = "\nIncorrect number of arguments\n";
		throw message;
		
	}
	
	string username = arguments->at(1);
	string password = arguments->at(2);
	
	for(int index = 0; index < users.size(); index++)	{
		if(username == (users.at(index))->getName())	{
			if((users.at(index))->verify(password))	{
				return users.at(index);
				
			}else	{
				message = "\nIncorrect Password!\n";
				throw message;
			}
		}
	
	
	}
	message = "\nIncorrect username!\n";
	throw message;
}

/*
 * Name        : getArguments
 * Description : Take the arguments from the line and put in a vector
 * Parameter(s): command: string that has the command line text
 * Return      : Pointer to a vector of strings that are split into seperate arguments
 */
std::vector<std::string> * Facade::getArguments(string command, const char separator)	{
	//Constants to tell what state the char running through the line is in
	const int NON_QUOTED = 0;
	const int QUOTED = 1;
	
	vector<string> * container = new vector<string>;
	string currentArgument = "";
	int state = NON_QUOTED;
	
	//Loop through every char in line
	for(char character : command)	{
		//Check the state currently in
		if(state == NON_QUOTED)	{
			if(character == '\n')	{
				//End of line do not want to take in this character and break command
				container->push_back(currentArgument);
				//Reset argument to take in the string of the next argument
				currentArgument.clear();
				break;
			}else if(character == separator)	{ 
				//End of field, push on the arguments the string
				if(currentArgument == "")	{
					//The argument is empty
					continue;
				}
				container->push_back(currentArgument);
				//Reset argument to take in the string of the next argument
				currentArgument.clear();

			}else if(character == '\47')	{//47 is '
				//Is a quoted field change state to QUOTED
				state = QUOTED;

			}else	{
				//Is a character to add to the string for the argument
				currentArgument += character;
			}

		}else if(state == QUOTED)	{
			if(character == '\47')	{//47 is '
				//Quote found end change to NON_QUOTED state
				state = NON_QUOTED;
				//End of field, push on the arguments the string
				container->push_back(currentArgument);
				//Reset currentArgument to take in the string of the next argument
				currentArgument.clear();

			}else	{
				//Is a character in the string that needs to be added to the argument
				currentArgument += character;

			}
		}
	}
	container->push_back(currentArgument);
	return container;
}

/*
 * Name        : showPastActivities
 * Description : Prints out all the activities of the user
 * Parameter(s): user: The user to show all activities
 * Return      : N/A
 */
void Facade::showPastActivities(User * user)	{
	if(user != NULL)	{
		user->showActivities();
		
	}else	{
		string message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : addActivity
 * Description : Takes arguments and tries to add an activity to the user
 * Parameter(s): user: The user to add the activity to
				 arguments: A vector of strings with the arguments to add an activity
 * Return      : N/A
 */
void Facade::addActivity(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 13)	{
			//Use given day
			
			string name = arguments->at(1);
			int day = stoi(arguments->at(2));
			int month = stoi(arguments->at(3)) - 1;
			int year = stoi(arguments->at(4)) - 1900;
			int startHour = stoi(arguments->at(5));
			int startMin = stoi(arguments->at(6));
			int endHour = stoi(arguments->at(7));
			int endMin = stoi(arguments->at(8));
			int duration = stoi(arguments->at(9));
			double distance = stod(arguments->at(10));
			string type = arguments->at(11);
			double elevationGain = stod(arguments->at(12));
			
			tm  date;
			date.tm_mday = day;
			date.tm_mon = month;
			date.tm_year = year;
			
			tm start;
			start.tm_hour = startHour;
			start.tm_min = startMin;
			
			tm end;
			end.tm_hour = endHour;
			end.tm_min = endMin;
			
			//Get correct type of activity created
			if(type == "Walk")	{
				int steps;
				cout << "Enter steps: ";
				cin >> steps;
				//remove the newline
				cin.get();
				
				Walk * walk = new Walk(name, user, date, start, end, duration, distance, steps, type, elevationGain);
				
				user->addActivity(walk);
				
			}else	{
				message = "\nInvalid type\n";
				throw message;
			}
			
			
		}else if(arguments->size() == 10)	{
			//get current day
			//name startHour startMin endHour endMin duration(min) distance steps type elevationGain
			string name = arguments->at(1);
			int startHour = stoi(arguments->at(2));
			int startMin = stoi(arguments->at(3));
			int endHour = stoi(arguments->at(4));
			int endMin = stoi(arguments->at(5));
			int duration = stoi(arguments->at(6));
			double distance = stod(arguments->at(7));
			string type = arguments->at(8);
			double elevationGain = stod(arguments->at(9));
			
			tm  * date;
			time_t currTime;
			
			time(&currTime);
			date = localtime(&currTime);
			
			tm start;
			start.tm_hour = startHour;
			start.tm_min = startMin;
			
			tm end;
			end.tm_hour = endHour;
			end.tm_min = endMin;
			
			//Get correct type of activity created
			if(type == "Walk")	{
				int steps;
				cout << "Enter steps: ";
				cin >> steps;
				//remove the newline
				cin.get();
				Walk * walk = new Walk(name, user, *date, start, end, duration, distance, steps, type, elevationGain);
				
				user->addActivity(walk);
				
			}else	{
				message = "\nInvalid type\n";
				throw message;
			}
			
		}else	{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
		
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
	
	
}

/*
 * Name        : showProgress
 * Description : Takes the user and shows their progress 
 * Parameter(s): user: The user to view their progress of
 * Return      : N/A
 */
void Facade::showProgress(User * user, vector<string>* arguments)	{
	//Get sortBy string
	//user->showProgress();
}

/*
 * Name        : viewProfile
 * Description : Takes arguments and displays profile information
 * Parameter(s): user: The user to view information on
 * Return      : N/A
 */
void Facade::viewProfile(User * user)	{
	if(user != NULL)	{
		user->view();
	}else	{
		string message =  "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : removeActivity
 * Description : Takes arguments and tries to delete the activity from the user
 * Parameter(s): user: The user to remove the activity from
				 arguments: A vector of strings with the arguments to remove an activity
 * Return      : N/A
 */
void Facade::removeActivity(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 5)	{
			string name = arguments->at(1);
			int day = stoi(arguments->at(2));
			int month = stoi(arguments->at(3)) - 1;
			int year = stoi(arguments->at(4)) - 1900;
			
			user->removeActivity(name, day, month, year);
		}else	{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
		
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : setStepGoal
 * Description : Takes arguments and changes the step goal of the user
 * Parameter(s): user: user to update data on
				 arguments: A vector of strings with the arguments to change weight to
 * Return      : N/A
 */
void Facade::setStepGoal(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 2)	{
			int stepGoal = stoi(arguments->at(1));
			user->setStepGoal(stepGoal);
		}else{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : removeStepGoal
 * Description : Takes the user and removes their step goal
 * Parameter(s): user: user to remove step goal from
 * Return      : N/A
 */
void Facade::removeStepGoal(User * user)	{
	if(user != NULL)	{
		user->setStepGoal(0);
	}else	{
		string message = "\nNot logged in\n"; 
		throw message;
	}
	
}

/*
 * Name        : updateWeight
 * Description : Takes arguments and changes the weight of the user
 * Parameter(s): user: user to update data on
				 arguments: A vector of strings with the arguments to change weight to
 * Return      : N/A
 */
void Facade::updateWeight(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 2)	{
			int weight = stoi(arguments->at(1));
			user->setWeight(weight);
		}else{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : updateHeight
 * Description : Takes arguments and changes the height of the user
 * Parameter(s): user: user to update data on
				 arguments: A vector of strings with the arguments to change height to
 * Return      : N/A
 */
void Facade::updateHeight(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 2)	{
			int height = stoi(arguments->at(1));
			user->setHeight(height);
		}else{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : updateAge
 * Description : Takes arguments and changes the age of the user
 * Parameter(s): user: user to update data on
				 arguments: A vector of strings with the arguments to change age to
 * Return      : N/A
 */
void Facade::updateAge(User * user, vector<string>* arguments)	{
	string message;
	if(user != NULL)	{
		if(arguments->size() == 2)	{
			int age = stoi(arguments->at(1));
			user->setAge(age);
		}else{
			message = "\nIncorrect number of arguments\n";
			throw message;
		}
	}else	{
		message = "\nNot logged in\n";
		throw message;
	}
}

/*
 * Name        : load
 * Description : Loads the saved data into users and their activities
 * Parameter(s): N/A
 * Return      : N/A
 */
void Facade::load()	{
	const char separator = ',';
	//Files to read saved data from
	ifstream userSaveFile(USER_SAVE_FILE);
	ifstream activitySaveFile(ACTIVITY_SAVE_FILE);
	//Line from file
	string line;
	
	if(userSaveFile.is_open() && activitySaveFile.is_open())	{
		//Load in the users
		while(getline(userSaveFile, line))	{
			//Values from the line in file
			vector<string> * values = getArguments(line, separator);
			string name = values->at(0);
			string pass = values->at(1);
			string sex = values->at(2);
			int age = stoi(values->at(3));
			int weight = stoi(values->at(4));
			int height = stoi(values->at(5));
			int stepGoal = stoi(values->at(6));
			
			//Create User with data
			User * newUser = new User(name, pass, age, weight, height, sex);
			newUser->setStepGoal(stepGoal);
			//Put user in list of users
			users.push_back(newUser);
			//delete current values vector
			delete values;
		}
		
		//Each users activities are grouped together in order saved in user save file so can loop through activities and put them in correct user
		int userIndex = 0;
		while(getline(activitySaveFile, line))	{
			//Values from the line in file
			vector<string> * values = getArguments(line, separator);
			string userName = values->at(0);
			string type = values->at(1);
			string activityName = values->at(2);
			int day = stoi(values->at(3));
			int month = stoi(values->at(4));
			int year = stoi(values->at(5));
			int startHour = stoi(values->at(6));
			int startMin = stoi(values->at(7));
			int endHour = stoi(values->at(8));
			int endMin = stoi(values->at(9));
			int duration = stoi(values->at(10));
			double distance = stod(values->at(11));
			double elevationGain = stod(values->at(12));
			
			tm  date;
			date.tm_mday = day;
			date.tm_mon = month;
			date.tm_year = year;
			
			tm start;
			start.tm_hour = startHour;
			start.tm_min = startMin;
			
			tm end;
			end.tm_hour = endHour;
			end.tm_min = endMin;
			
			User * currentUser = users.at(userIndex);
			//Check if it is the next user and loop until it is the correct User
			while(userName != currentUser->getName())	{
				//Not the current user so get the next user as this is the first activity for the next user
				currentUser = users.at(++userIndex);
			}
			
			//Check what type it is
			if(type == "Walk")	{
				int steps = stoi(values->at(13));
				
				Walk * walk = new Walk(activityName, currentUser, date, start, end, duration, distance, steps, type, elevationGain);
				currentUser->addActivity(walk);
				
			}
			//Delete vector for current line
			delete values;
		}
	}
}

/*
 * Name        : save
 * Description : Saves teh data in users and their activities
 * Parameter(s): N/A
 * Return      : N/A
 */
void Facade::save()	{
	ofstream userSaveFile(USER_SAVE_FILE);
	ofstream activitySaveFile(ACTIVITY_SAVE_FILE);
	
	
	if(userSaveFile.is_open() && activitySaveFile.is_open())	{
		//Go through each user
		for(int index = 0; index < users.size(); index++)	{
			User * currentUser = users.at(index);
			
			vector<Activity *> usersAct = currentUser->getActivities();
			//Go through the user's activities
			for(int index = 0; index < usersAct.size(); index++)	{
				//Write activity to file
				activitySaveFile << (usersAct.at(index))->saveString();
			}
			
			//Write user to file
			userSaveFile <<	currentUser->saveString();
			
		}
		
		activitySaveFile.close();
		userSaveFile.close();
		
	}else{
		cout << endl << "Unable to open files to save to" << endl;
	}
}

/*
 * Name        : ~Facade
 * Description : Deletion of Facade that deletes the Facade object
 * Parameter(s): N/A
 * Return      : N/A
 */
Facade::~Facade()	{
	//Delete users created
	for(int index = 0; index < users.size(); index++)	{
		User * user = users.at(index);
		delete user;
	}
	
}

/*
 * Name        : Facade
 * Description : Protected constructor that creates the one singleton object when it does not already exist
 * Parameter(s): N/A
 * Return      : N/A
 */
Facade::Facade()	{
	 
}
 