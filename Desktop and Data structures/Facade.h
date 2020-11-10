/*
 * Facade.h
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Header file describing the facade of the program
 *
 */
 
#ifndef FACADE_H_
#define FACADE_H_

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
		std::vector<std::string> *getArguments(std::string); 
		void showPastActivities(User *user);
		void addActivity(User * user, std::vector<std::string>* arguments);
		void showProgress(User * user);
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
		std::vector<User> * users = NULL;
		
			
};
 
 #endif
 