/**
 * @brief Header file describing the class for the user to store data and perform methods on the data
 * @details Header file describing the class for the user to store data for fitness data and keep track of activities
 * @author Matthew Temniuk
 *
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "activity.h"
class Activity;
class User	{
    public:
        User(std::string name, std::string password, int age, int weight, int height, std::string sex);
        ~User();
        bool verify(std::string) const ;
        void view() const ;
        std::string saveString() const ;
        void showProgress(std::string orderedBy);
        void showActivities() const ;
        void addActivity(Activity *) ;
        void removeActivity(std::string name, int day, int month, int year);
        std::string getName() const ;
        int getAge() const ;
        int getWeight() const ;
        int getHeight() const ;
        std::string getSex() const ;
        std::vector<Activity *> getActivities() const;
        int getStepGoal() const ;
        void setAge(int newAge);
        void setWeight(int newWeight);
        void setHeight(int newHeight);
        void setSex(std::string newSex);
        void setStepGoal(int newSteps);

    private:
        std::string name;
        std::string password;
        int age;
        int weight;
        int height;
        std::string sex;
        int stepGoal;
        std::vector<Activity *> activities;



};

#endif
