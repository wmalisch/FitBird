/**
 * @brief Header file describing the Python Sensor
 * @details Header file to describe the object that runs the python code, to receive messages from 
 * @author Will Malisch
 *
 */
#ifndef PYTHONSENSOR_H
#define PYTHONSENSOR_H

#include <string.h>
#include <string>
#include <iostream>
#include <thread>
#include <unistd.h>

class PythonSensor{
    public:
        static const std::string path;
        static const std::string command;
        static PythonSensor * instance();
        ~PythonSensor();
        int runScript();
    protected:
        PythonSensor();
    private:
        static PythonSensor * _instance;
};

#endif