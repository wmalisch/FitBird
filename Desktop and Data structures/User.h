/*
 * Facade.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Header file describing the class for the user to store data and perform methods on the data
 *
 */
 
#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#incldue "Activity.h"

class User	{
	public:
		User(std::string name, std::string password, int age, int weight, int height, std::string sex);
		~User();
		bool verify(std::string) const;
		void view() const;
		void showProgress() const;
		void showActivities() const;
		void addActivity(Activity);
		void removeActivity(std::string name, int day, int month, int year);
		std::string getName() const;
		int getAge() const;
		int getWeight() const;
		int getHeight() const;
		std::string getSex() const;
		int getStepGoal() const;
		void setAge(int age);
		void setWeight(int weight);
		void setHeight(int height);
		void setSex(std::string sex):
		void setStepGoal(int steps);
		
	private:
		std::string name;
		std::string password;
		int age;
		int weight;
		int height;
		std::string sex;
		int stepGoal;
		std::vector<Activity> *activities;
		
		
	
};

#endef
