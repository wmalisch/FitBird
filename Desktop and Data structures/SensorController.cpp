#include "./SensorController.h"

SensorController::SensorController(){
    receiver_instance = SensorReceiver::instance();
    python_instance = PythonSensor::instance();
}

void SensorController::record(){
    receiver_instance->setSwitch(receiver_instance->sensor_initialize());
    std::thread thread_server(&SensorReceiver::run_sensor, receiver_instance);
    std::thread thread_client(&PythonSensor::runScript, python_instance);
    thread_server.join();
    thread_client.join();
    std::cout << "DONE BOTH THREADS" << std::endl;
    
}



SensorController::~SensorController(){
    delete receiver_instance;
    delete python_instance;
}