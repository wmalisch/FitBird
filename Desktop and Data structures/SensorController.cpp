#include "./SensorController.h"

SensorController::SensorController(){
    receiver_instance = SensorReceiver::instance();
    python_instance = PythonSensor::instance();
}

void SensorController::record(){
    
    // Get time at start of recording
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int startHour = now->tm_hour;
    int startMin = now->tm_min;

    // Record, using a thread to receive messages and a thread to send accelerometer data
    receiver_instance->setSwitch(receiver_instance->sensor_initialize());
    std::thread thread_server(&SensorReceiver::run_sensor, receiver_instance);
    std::thread thread_client(&PythonSensor::runScript, python_instance);
    thread_server.join();
    thread_client.join();

    // Get time at end of recording
    std::time_t e = std::time(0);
    std::tm* later = std::localtime(&e);
    int endHour = now->tm_hour;
    int endMin = now->tm_min;
    receiver_instance->calculateSteps();
    int steps = receiver_instance->getSteps();
    int duration;
    if(startHour == endHour){
        duration = endMin - startMin;    
    }else if(startHour < endHour){
        if(startMin == endMin){
            duration = (endHour - startHour) * 60;
        }else if(startMin > endMin){
            duration = 60 - startMin + endMin;
        }else if(startMin < endMin){
            duration = (endHour - startHour) * 60 + endMin - startMin;
        }
    }else if(startHour > endHour){
        if(endHour == 0){
            endHour = 24;
        }
        if(startMin == endMin){
            duration = (startHour - endHour) * 60;
        }else if(startMin > endMin){
            duration = 60 - startMin + endMin;
        }else if(startMin < endMin){
            duration = (startHour - endHour) * 60 + endMin - startMin;
        }
    }
    string type = "Walk";
    double gain = 0.00;
    double distance = AVG_DISTANCE_PER_STEP * steps;
    std::cout << distance << std::endl;
    std::cout << "[DONE] Closing client and server." << std::endl;
}



SensorController::~SensorController(){
    delete receiver_instance;
    delete python_instance;
}