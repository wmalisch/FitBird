/*
 * DesktopMain.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 3, 2020
 *	Description    : Currently console based used for desktop usage to make changes and perform algorithms on the data.
 *
 */
#include <iostream>
#include <string>
#include "Facade.h"

using namespace std;

/*
 * Name        : main
 * Description : Main program to run the desktop for fitness wearable
 * Parameter(s): argc: The number (int) of command line parameters used to call the program.
				 argv: Does not use any arguments
 * Return      : int for exit status of the main program
 */
int main(int argc, char *argv[]){
	//Print out a menu
	cout << "*******************************************************************************************************************************" << endl;
	cout << "Types of activities allowed: Walk" << endl;
	cout << "OrderBy fields allowed: Not yet implemented" << endl;	//Once showProgress has been implemented update this
	cout << "Command usages:" << endl;
	cout << "  addUser username password age weight(kg) height(cm) sex(M/F)" << endl;
	cout << "  login username password" << endl;
	cout << "  logout" << endl;
	cout << "  quit" << endl;
	cout << "Commands upon login:" << endl;
	cout << "  showPastActivities" << endl;
	cout << "  addActivity 'name' day(int) month(int) year(int) startHour startMin endHour endMin duration(min) distance type elevationGain" << endl; 
	cout << "  addActivity 'name' startHour startMin endHour endMin duration(min) distance type elevationGain" << endl; 
	cout << "  showProgress OrderBy (once logged in)" << endl;
	cout << "  viewProfile (once logged in)" << endl;
	cout << "  removeActivity 'name' day month year" << endl;
	cout << "  setStepGoal step_goal" << endl;
	cout << "  removeStepGoal" << endl;
	cout << "  updateWeight weight(kg)" << endl;
	cout << "  updateHeight height(cm)" << endl;
	cout << "  updateAge age" << endl;
	//Add any needed extra functions
	cout << "*******************************************************************************************************************************" << endl;
	//Separator for the commands
	const char separator = ' ';
	
	Facade * instance = Facade::instance();
	//Load data stored 
	instance->load();
	
	//Keep the current user stored
	User *currentUser = NULL;
	
	bool quit = false;
	//Loop through until quit and listen for commands
	while(!quit)	{
		cout << ">> ";
		
		string line;
		getline(cin, line);
		
		//Create record of strings and use getArguments to get the seperated arguments in command 
		vector<string> *arguments = instance->getArguments(line, separator);
		
		//Get the command by breaking the command into vector of strings
		try	{
			if(arguments->size() == 0)	{
				//No command put in
				//delete arguments
				delete arguments;
				continue;
			}
			
			string command = arguments->at(0);
		
		
			//Commands to take in and make call to facade
			if(command == "addUser")	{
				instance->addUser(arguments);
				
			}else if(command == "login")	{
				currentUser = instance->login(arguments);
			
			}else if(command == "logout")	{
				currentUser = NULL;
				
			}else if(command == "showPastActivities")	{
				instance->showPastActivities(currentUser);
				
			}else if(command == "addActivity"){
				instance->addActivity(currentUser, arguments);
				
			}else if(command == "showProgress")	{
				//instance->showProgress(currentUser);
				
			}else if(command == "viewProfile")	{
				instance->viewProfile(currentUser);
				
			}else if(command == "removeActivity")		{
				instance->removeActivity(currentUser, arguments);
				
			}else if(command == "setStepGoal")		{
				instance->setStepGoal(currentUser, arguments);
				
			}else if(command == "removeStepGoal")	{
				instance->removeStepGoal(currentUser);
				
			}else if(command == "updateWeight")	{
				instance->updateWeight(currentUser, arguments);
				
			}else if(command == "updateHeight")	{
				instance->updateHeight(currentUser, arguments);
				
			}else if(command == "updateAge")	{
				instance->updateAge(currentUser, arguments);
				
			}else if(command == "quit")	{
				quit = true;
			}else	{
				cout << "Invalid Command" << endl;
			}
			
		}catch (string &msg)	{
			cout << msg.c_str() << endl;
			
		}
		//delete arguments 
		delete arguments;
	}

	//Save data to load back on next startup
	instance->save();
	
	delete instance;
	
	return 0;
}