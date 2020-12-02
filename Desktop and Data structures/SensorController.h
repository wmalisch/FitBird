#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include <string.h>
#include <string>
#include <iostream>
#include <thread>
#include <signal.h>
#include "../Communication/Project Copy/SensorReceiver.h"
#include "PythonSensor.h"

class SensorController {
    public:
        SensorController();
        ~SensorController();
        void handler(int signum);
        static void static_signalHandler(int signum);
        void record();
        void stopRecord();
    protected:
    private:
        SensorReceiver * receiver_instance;
        PythonSensor * python_instance;
 
};

#endif