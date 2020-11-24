/*
 * Walk.h
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Header file describing a Walk activity class
 *
 */
#ifndef WALK_H_
#define WALK_H_

#include <ctime>
#include <iostream>
#include <string>
#include "User.h"
#include "Activity.h"
class User;
class Walk : public Activity	{
	public:
		Walk(std::string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, int steps, std::string type, double elevationGain);
		~Walk();
		void view() const ;
		std::string saveString() const;
		int getSteps() const ;
		void setSteps(int newSteps);
		
	private:
		int steps;
		static int calculateCaloriesBurnt(User * user, Walk * activity);
};
		
#endif
