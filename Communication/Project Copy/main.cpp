/*
 * main.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 11, 2020
 *	Description    : This is just a file used to test the parallel processing and data transmission between SensorReceiver and Python
 * 
 */

#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <chrono>
#include <ctime>

// #include <stdlib.h>
// #include <python3.7m/Python.h>


int main(){
    std::cout << "[MAIN TESTING PROGRAM]" << std::endl;
    // SensorReceiver * instance = SensorReceiver::instance();
    // instance->sensor_initialize();
    // instance->run_sensor();
    // string file = "/media/sf_3307CS/Project/proj/Communication/'Project Copy'/client.py";
    // string command = "python3 ";
    // command += file;
    // system(command.c_str());
    auto start = std::chrono::system_clock::now();
    // Some computation here
    std::string test1 = "-0.001 -0.003 -1.005/";
    std::string test2 = "0.002 0.002 1.011/";
    std::string test3 = "0.000 -0.001 1.011/";

    std::string xsd;
    std::string ysd;
    std::string zsd;

    std::stringstream curr;
    curr << test1;
    char x=curr.get();
    while(x!=' '){
        xsd+=x;
        x=curr.get();
    }
    x=curr.get();
    while(x!=' '){
        ysd+=x;
        x=curr.get(); 
    }
    x=curr.get();
    while(x!='/'){
        zsd+=x;
        x=curr.get(); 
    }
    std::cout << xsd << std::endl;
    std::cout << "[TESTING FLOAT CONVERSION]" << std::endl;
    double xd = std::stod(xsd.c_str());
    std::cout << xd << std::endl;
    std::vector<double> xvec;
    xvec.push_back(xd);
    std::cout << xvec.at(0) << std::endl;
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_hour) << '-' 
         << (now->tm_min + 1) << '-'
         << "\n";

    return 0;
}