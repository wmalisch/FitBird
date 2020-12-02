#include "./SensorController.h"

SensorController::SensorController(){
    receiver_instance = SensorReceiver::instance();
    python_instance = PythonSensor::instance();
}

void SensorController::record(){
    receiver_instance->setSwitch(receiver_instance->sensor_initialize());
    std::cout << receiver_instance->getSwitch() << std::endl;
    std::thread thread_server(&SensorReceiver::run_sensor, receiver_instance);
    std::thread thread_client(&PythonSensor::runScript, python_instance);
    thread_server.join();
    thread_client.join();
    receiver_instance->calculateSteps();
    std::cout << "DONE BOTH THREADS" << std::endl;
    std::cout << "Done running script and closing client" << std::endl;
}



SensorController::~SensorController(){
    delete receiver_instance;
    delete python_instance;
}