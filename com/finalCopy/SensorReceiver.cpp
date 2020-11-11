#include "./SensorReceiver.h"

using namespace std;

// Constructor
SensorReceiver::SensorReceiver(){
    onSwitch = sensor_initialize();
}

// Destructor
SensorReceiver::~SensorReceiver(){}

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

    // Accept a call
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);


    // int clientSocket = accept(server_socket, (struct sockaddr*)&client, &clientSize);
    // cout << clientSocket << endl;
    // close(clientSocket);
    return 1;
}

int SensorReceiver::getSwitch() const{
    return onSwitch;
}