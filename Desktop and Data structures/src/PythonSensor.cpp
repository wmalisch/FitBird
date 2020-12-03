/**
 * @brief PythonSensor class, for running the python code 
 * @details PythonSensor holds the path and file that is ran using system calls, and is used as a way to safely delete data pertaining to itself
 * @author Will Malisch
 *
 */

#include "../headers/PythonSensor.h"

/**
 * @brief 
 * @details 
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
const std::string PythonSensor::path = std::string("/media/sf_3307CS/Project/proj/'Desktop and Data structures'/py/client.py");
const std::string PythonSensor::command = std::string("python3 ");

PythonSensor * PythonSensor::_instance = NULL;

/**
 * @brief instance creates an instance of the singleton class PythonSensor
 * @details Creates and instance
 * @author Will Malisch
 * @param N/A
 * @return instance of PythonSensor
 *
 */
PythonSensor * PythonSensor::instance(){
    if(_instance == NULL){
        _instance = new PythonSensor();
    }
    return _instance;
}

/**
 * @brief Constructor
 * @details Constructor
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
PythonSensor::PythonSensor(){

}

/**
 * @brief Destructor
 * @details Destructor
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
PythonSensor::~PythonSensor(){

}

/**
 * @brief RunScript uses system calls to run the python script
 * @details Uses system calls to run, and sleep to make sure the server is executed before the client. (The code called being the client)
 * @author Will Malisch
 * @param N/A
 * @return Integer representing success
 *
 */
int PythonSensor::runScript(){
    sleep(2);
    std::cout << "[STARTING] Press Ctrl-C to end recording session\n" << std::endl;
    std::cout << "[COUNT DOWN] Recording will begin in 5 seconds\n" << std::endl;
    sleep(2);
    std::string message = command + path;
    system(message.c_str());
    return 1;
}