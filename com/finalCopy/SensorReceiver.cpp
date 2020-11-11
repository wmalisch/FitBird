/*
 * Facade.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 11, 2020
 *	Description    : 
 *
 */
#include "./SensorReceiver.h"

using namespace std;

 /*
 * Name        : SensorReceiver
 * Description : Get the singleton instance of the facade, if one does not exist already create it
 * Parameter(s): N/A
 * Return      : pointer to the instance of the facade
 */
SensorReceiver::SensorReceiver(){
    /* ############################################# */
    /* 
    THIS CLASS WILL IMPLEMENT MULTILE/PARALLEL PROCESSING
    1. First process will run c++ server code, until the user tells the fitbird to stop recording data
    2. Second process will initialize python interpreter and run python client code, which accesses accelerometer data and sends it to this class

    We have already configured the python code to access accelerometer data, send it to SensorReceiver, and have SensorReceiver print it out on the screen.
    This can be seen in the roughCopy directory. So we are now just converting it to a class that our facade can create and access an object for
    Once this class is done, the facade/main program will be able to create a sensor receiver object, which will automatically record data, and convert it
    into an Activity object when done. 
    */
    /* ############################################# */
    onSwitch = sensor_initialize();
    client_socket = run_sensor();
}

// Destructor
SensorReceiver::~SensorReceiver(){
    /*
    CODE HERE TO DESTROY ALL VALUES OF THE SENSOR, SO THAT THE NEXT SENSOR STARTS FROM SCRATCH
    */
}

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

int SensorReceiver::run_sensor(){

    // Accept the client
    clientSize = sizeof(client);
    client_socket = accept(server_socket, (struct sockaddr*)&client, &clientSize);
    /*
    
    */
    return client_socket;
}

void SensorReceiver::end_sensor(){
    close(client_socket);
}

int SensorReceiver::getSwitch() const{
    return onSwitch;
}