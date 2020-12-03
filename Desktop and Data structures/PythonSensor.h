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