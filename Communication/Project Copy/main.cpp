/*
 * main.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 11, 2020
 *	Description    : This is just a file used to test the parallel processing and data transmission between SensorReceiver and Python
 * 
 */
#include "./SensorReceiver.h"
#include <iostream>
#include <stdlib.h>
// #include <python3.7m/Python.h>

int main(){
    cout << "[MAIN TESTING PROGRAM]" << endl;
    SensorReceiver * instance = SensorReceiver::instance();
    string file = "/media/sf_3307CS/Project/proj/Communication/'Project Copy'/client.py";
    string command = "python3 ";
    command += file;
    system(command.c_str());
    
    // Py_Initialize();
    // PyRun_SimpleString("import sys");


    return 0;
}