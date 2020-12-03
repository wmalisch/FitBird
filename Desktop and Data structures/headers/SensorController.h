/**
 * @brief Header file for the SensorController class 
 * @details This goes over all the functions and declartations for Sensor Controller
 * @author Will Malisch
 *
 */

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
        std::vector<string>* record();
        void stopRecord();
    protected:
    private:
        SensorReceiver * receiver_instance;
        PythonSensor * python_instance;

 
};

#endif