/**
 * @brief Header file describing the facade of the program
 * @details Header file to describe the class of facade to hide the backend from user
 * @author Matthew Temniuk
 *
 */
 
#ifndef FACADE_H_
#define FACADE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "User.h"
#include "Activity.h"
#include "Walk.h"
class User;
class Facade	{
	public:
		static Facade * instance();
		void addUser(std::vector<std::string>* arguments);
		User * login(std::vector<std::string>* arguments);
		std::vector<std::string> *getArguments(std::string, const char separator); 
		void showPastActivities(User *user);
		void addActivity(User * user, std::vector<std::string>* arguments);
		void showProgress(User * user, std::vector<std::string>* arguments);
		void viewProfile(User * user);
		void removeActivity(User * user, std::vector<std::string>* arguments);
		void setStepGoal(User * user, std::vector<std::string>* arguments);
		void removeStepGoal(User * user);
		void updateWeight(User * user, std::vector<std::string>* arguments);
		void updateHeight(User * user, std::vector<std::string>* arguments);
		void updateAge(User * user, std::vector<std::string>* arguments);
		void load();
		void save();
		~Facade();
		
	protected:
		Facade();
		
	private:
		static Facade * _instance;
		std::vector<User *> users;
		
			
};
 
 #endif
 