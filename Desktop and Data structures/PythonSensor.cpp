#include "./PythonSensor.h"

const std::string PythonSensor::path = std::string("/media/sf_3307CS/Project/proj/'Desktop and Data structures'/client.py");
const std::string PythonSensor::command = std::string("python3 ");

PythonSensor * PythonSensor::_instance = NULL;

PythonSensor * PythonSensor::instance(){
    if(_instance == NULL){
        _instance = new PythonSensor();
    }
    return _instance;
}

PythonSensor::PythonSensor(){

}

PythonSensor::~PythonSensor(){

}

int PythonSensor::runScript(){
    sleep(2);
    std::cout << "[STARTING] Press Ctrl-C to end recording session\n" << std::endl;
    std::cout << "[COUNT DOWN] Recording will begin in 5 seconds\n" << std::endl;
    sleep(2);
    std::string message = command + path;
    system(message.c_str());
    return 1;
}