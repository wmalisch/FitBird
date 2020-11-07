/*
 * Activity.h
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Header file describing a base Activity class
 *
 */
#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include <ctime>
#include <iostream>
#include <string>
#include "User.h"
class User;
class Activity {
	 public:
		Activity(std::string name, User * user, struct tm date, struct tm start, struct tm end, int duration, double distance, std::string type, double elevationGain);
		virtual ~Activity();
		virtual void view() const ;
		std::string getName() const ;
		User *getUser() const ;
		struct tm getDate() const ;
		struct tm getStart() const ;
		struct tm getEnd() const ;
		int getDuration() const ;
		double getDistance() const ;
		std::string getType() const ;
		double getElevationGain() const ;
		void setDate(struct tm date);
		void setStart(struct tm start);
		void setEnd(struct tm end);
		void setDuration(int duration);
		
		
	 protected:
		std::string name;
		User * user;
		struct tm date;
		struct tm start;
		struct tm end;
		int duration;
		double distance;
		std::string type;
		double elevationGain;
		int caloriesBurnt;
		virtual int calculateCaloriesBurnt(User * user, Activity * activity);
	 
};
 
 #endif
 