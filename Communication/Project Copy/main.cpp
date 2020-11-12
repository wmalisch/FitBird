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

int main(){
    cout << "[MAIN TESTING PROGRAM]" << endl;
    SensorReceiver * instance = SensorReceiver::instance();
    cout << instance->getSwitch() << endl;
    return 0;
}