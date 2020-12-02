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
    
    std::string test1 = "-0.001 -0.003 -1.005/";
    std::string test2 = "0.002 0.002 1.011/";
    std::string test3 = "0.000 -0.001 1.011/";

    std::string xsd;
    std::string ysd;
    std::string zsd;

    std::stringstream curr;
    curr << test3;
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
    std::cout << ysd << std::endl;
    std::cout << zsd << std::endl;

    std::cout << "[TESTING FLOAT CONVERSION]" << std::endl;
    std::string::size_type sz; //alias of size_t
    double xd = std::stod(xsd.c_str());
    double yd = std::stod(ysd.c_str());
    double zd = std::stod(zsd.c_str());
    std::cout << xd << std::endl;
    std::cout << yd << std::endl;
    std::cout << zd << std::endl;
    std::cout << typeid(xd).name() << std::endl;
    std::cout << typeid(yd).name() << std::endl;
    std::cout << typeid(zd).name() << std::endl;
    std::cout << typeid(xsd).name() << std::endl;
    std::cout << typeid(ysd).name() << std::endl;
    std::cout << typeid(zsd).name() << std::endl;
    int p = 1;
    std::cout << typeid(p).name() << std::endl;
    


    return 0;
}