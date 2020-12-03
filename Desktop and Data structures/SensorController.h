#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H
#define AVG_DISTANCE_PER_STEP 2.5

#include <string.h>
#include <string>
#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <signal.h>
#include <vector>
#include "SensorReceiver.h"
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