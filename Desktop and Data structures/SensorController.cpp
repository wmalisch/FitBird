/**
 * @brief SensorController class is used to controll all sensor related objects. 
 * @details SensorController acts as a facade but just for the sensor related objects. It runs threads for each process, as a way to implement multiprocessing, therefore running both the server and client from one program.
 * @author Will Malisch
 *
 */

#include "./SensorController.h"

/**
 * @brief Constructor
 * @details Creates instances of SensorReceiver and PythonSensor
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
SensorController::SensorController(){
    receiver_instance = SensorReceiver::instance();
    python_instance = PythonSensor::instance();
}
/**
 * @brief Record is the main function responsible for recording activity
 * @details Record tracks the duration, runs the threads for sending and receiving sensor data, and finishes off by creating an activity vector to be passed to the facade
 * @author Will Malisch
 * @param N/A
 * @return A vector of strings, that will be inpputed for making an activity 
 *
 */
std::vector<string>* SensorController::record(){
    
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

    // Calculate steps
    receiver_instance->calculateSteps();
    int steps = receiver_instance->getSteps();

    // Get the rest of the info required to make an activity
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
    string name = "walk";
    string type = "Walk";
    double gain = 0.00;
    double distance = AVG_DISTANCE_PER_STEP * steps;

    // Convert all variables to strings, add them to the activity vector, and return the vector
    std::vector<string> * activity = new vector<string>;
    activity->push_back("head");
    activity->push_back(name);
    activity->push_back(std::to_string(startHour));
    activity->push_back(std::to_string(startMin));
    activity->push_back(std::to_string(endHour));
    activity->push_back(std::to_string(endMin));
    activity->push_back(std::to_string(duration));
    activity->push_back(std::to_string(distance));
    activity->push_back(type);
    activity->push_back(std::to_string(gain));
    std::cout << "[DONE] Closing client and server." << std::endl;
    return activity;
}


/**
 * @brief Destructor
 * @details Destructor
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
SensorController::~SensorController(){
    delete receiver_instance;
    delete python_instance;
}