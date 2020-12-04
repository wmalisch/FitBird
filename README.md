GROUP 56 - PROJECT PROGRESSION UPDATE

This README is a quick description of the status of our project, to whom ever is marking this assignment. Please read before moving forward.

Our program can be run in a terminal and in QT (GUI). The GUI functions exactly like the main program in the terminal. However, the live recording of an activity is a feature which is done only through the terminal and when connected to raspberry.

All files listed above are working and cover all of our user stories for our required features in terms of points. 

*To compile the main program on the terminal, do the following commands:
    	
	cd 'Desktop and Data structures'
	
	Go to the raspberry pi button at the top left of your RP, click it. Go into programming. Go down to Sense Hat Enumerator, click it. Leave this open while running.

	g++ -o main DesktopMain.cpp src/User.cpp src/Activity.cpp src/Walk.cpp src/Facade.cpp src/SensorReceiver.cpp src/SensorController.cpp src/PythonSensor.cpp -pthread
	
	To run:
    	./main

	Follow the instructions, enter "quit" to exit the program.


	

*To compile the program with the GUI interface, do the following:

	Run the two following commands in the command line

	sudo apt-get install qt5-default
	sudo apt install qtcreator

	Then open qtcreator, open the project by clicking File->Open File or Project
	Navigate to the source file, and open FitBird3307.pro

	Build and run.


*Note
	1. Be sure to update your path in the PythonSensor.cpp file, so that it matches your path to where you are marking this assignment.
	
	2. If you are running the command recordActivity, you can move the dial for pitch or roll between 0 and -90 degrees to simulate a person walking.
