/*
 * main.cpp
 *
 *	Author		   : Group 56
 *	Date		   : November 11, 2020
 *	Description    : This is the header file outlining the functions and methods of the SensorReceiver class
 *
 */

using namespace std;

#ifndef SENSORRECEIVER_H
#define SENSORRECEIVER_H
#define SERVER_PORT htons(5050)

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include "Activity.h"

class SensorReceiver
{
    public:
        static SensorReceiver * instance();
        
        // Destructor
        ~SensorReceiver();
        
        // Sensor connection
        int sensor_initialize();
        int run_sensor();
        void end_sensor();

        // Getters and setters required so far
        int getSwitch() const;
        void setSwitch(int n);
        void calculateSteps();

    protected:
        SensorReceiver();
    private:
        vector<double> xvector;
        vector<double> yvector;
        vector<double> zvector;
        static SensorReceiver * _instance;
        int server_socket;
        int client_socket;
        sockaddr_in server_addr;
        sockaddr_in client;
        socklen_t client_size;
        char buffer[4096];
        int onSwitch;
        //Activity activity;

};

#endif