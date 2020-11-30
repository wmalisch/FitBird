/*
 * SensorReceiver.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 11, 2020
 *	Description    : 
 *
 */
#include "./SensorReceiver.h"

using namespace std;

SensorReceiver * SensorReceiver::_instance = NULL;

 /*
 * Name        : instance
 * Description : Get the singleton instance of the SensorReceiver, if one does not exist already create it
 * Parameter(s): N/A
 * Return      : pointer to the instance of the SensorReceiver
 */
SensorReceiver * SensorReceiver::instance(){
    if(_instance == NULL){
        _instance = new SensorReceiver();
    }
    return _instance;
    
}

 /*
 * Name        : SensorReceiver
 * Description : Get the singleton instance of the SensorReceiver, if one does not exist already create it
 * Parameter(s): N/A
 * Return      : pointer to the instance of the SensorReceiver
 * Description : THIS CLASS WILL IMPLEMENT MULTILE/PARALLEL PROCESSING
 *               1. First process will run c++ server code, until the user tells the fitbird to stop recording data
 *               2. Second process will initialize python interpreter and run python client code, which accesses accelerometer data and sends it to this class
 *
 *              We have already configured the python code to access accelerometer data, send it to SensorReceiver, and have SensorReceiver print it out on the screen.
 *              This can be seen in the roughCopy directory. So we are now just converting it to a class that our facade can create and access an object for
 *              Once this class is done, the facade/main program will be able to create a sensor receiver object, which will automatically record data, and convert it
 *              into an Activity object when done. 
*/
SensorReceiver::SensorReceiver(){
    onSwitch = sensor_initialize();
    client_socket = run_sensor();
}

 /*
 * Name        : ~SensorReceiver
 * Description : Destroy the SensorReceiver
 * Parameter(s): N/A
 * Return      : Destroys SensorReceiver Object
*/
SensorReceiver::~SensorReceiver(){
    /*
    CODE HERE TO DESTROY ALL VALUES OF THE SENSOR, SO THAT THE NEXT SENSOR STARTS FROM SCRATCH
    */
}

 /*
 * Name        : sensor_initialize
 * Description : Set up server side connection with sockets
 * Parameter(s): N/A
 * Return      : integer representing error/success code
 */
int SensorReceiver::sensor_initialize(){
    // Create a scoket
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    if(server_socket == -1){
        cerr << "Error creating socket" << endl;
        return -1;
    }
    // Bind the socket to a IP/ port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = SERVER_PORT;
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); 

    if(bind(server_socket, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr)) == -1){
        cerr << "[ERROR] port is currently in use" << endl;
        return -2;
    }
    // Mark the socket for listening in
    if(listen(server_socket, SOMAXCONN) == -1){
        return -3;
    }

    return 1;
}

 /*
 * Name        : run_sensor
 * Description : Accept connection from client side of application
 * Parameter(s): N/A
 * Return      : integer representing client_socket
 */
int SensorReceiver::run_sensor(){

    // Accept the client
    clientSize = sizeof(client);
    client_socket = accept(server_socket, (struct sockaddr*)&client, &clientSize);
    /*
    
    */
    return client_socket;
}

 /*
 * Name        : end_sensor
 * Description : Sclose connection between client and server
 * Parameter(s): N/A
 * Return      : N/A
 */
void SensorReceiver::end_sensor(){
    close(client_socket);
}

 /*
 * Name        : getSwitch
 * Description : Gets value to determine if sensor is running
 * Parameter(s): N/A
 * Return      : integer representing on or off
 */
int SensorReceiver::getSwitch() const{
    return onSwitch;
}