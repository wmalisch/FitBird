/**
 * @brief Header file describing a base Activity class
 * @details Header file to declare the activity class for use to track a users fitness activity
 * @author Matthew Temniuk
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
		virtual std::string saveString() const;
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
 