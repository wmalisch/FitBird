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
    
}

 /*
 * Name        : ~SensorReceiver
 * Description : Destroy the SensorReceiver
 * Parameter(s): N/A
 * Return      : Destroys SensorReceiver Object
*/
SensorReceiver::~SensorReceiver(){
    /* Destroy data and memory allocated for acceleromter for this instance of the sensor */
}

 /*
 * Name        : sensor_initialize
 * Description : Set up server side connection with sockets
 * Parameter(s): N/A
 * Return      : integer representing error/success code
 */
int SensorReceiver::sensor_initialize(){
    // Create a scoket
    cout << "[INITIALIZING] Sensor is being set up to receive messages ...\n" << endl;
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    if(server_socket == -1){
        cerr << "Error creating socket" << endl;
        return -1;
    }
    // Bind the socket to a IP/ port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = SERVER_PORT;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); 

    if(bind(server_socket, (struct sockaddr*) &server_addr, sizeof(struct sockaddr)) == -1){
        cerr << "[ERROR] port is currently in use" << endl;
        return -2;
    }
    // Mark the socket for listening in
    if(listen(server_socket, SOMAXCONN) == -1){
        cerr << "[ERROR] port is currently unable to listen to messages" << endl;
        return -3;
    }
    cout << "[WAITING] Sensor has been initialized. Run when ready by calling the run_sensor function.\n" << endl;
    return 1;
}

 /*
 * Name        : run_sensor
 * Description : Accept connection from client side of application
 * Parameter(s): N/A
 * Return      : integer representing client_socket
 */
int SensorReceiver::run_sensor(){
    // Use the variables below to convert messages into doubles, once you enter the receiving while loop
    std::stringstream curr;
    std::string xsd;
    std::string ysd;
    std::string zsd;
    std::string::size_type sz;

    // Accept the client
    client_size = sizeof(client);
    cout << "[WAITING] Run sensor function called. Waiting to for message from client ... \n" << endl;

    client_socket = accept(server_socket, (struct sockaddr*)&client, &client_size);
    if(client_socket == -1){
        cerr << "[ERROR] Was not able to connect to socket. Press Ctrl-C to return to menu." << endl;
        return -4;
    }
    cout << "[RUNNING] Server has accepted client and will not receive data ..." << endl;
    int i = 1;
    
    while(true){
        

        // Clear memory
        xsd = "";
        ysd = "";
        zsd = "";
        memset(buffer,0,4096);

        // Wait for a message
        int bytesRecv = recv(client_socket,buffer,4096,0);
        if (bytesRecv == -1){
            cerr << "Connection error";
            break;
        }
        if(bytesRecv==0){
            cout<<"Client disconnected" << endl;
            break;
        }
        curr << string(buffer,0,bytesRecv);
        char x=curr.get();
        while(x!=' '){
            xsd+=x;
            x=curr.get();
        }
        x=curr.get();
        while(x!=' '){
            ysd+=x;
            x=curr.get(); 
        }
        x=curr.get();
        while(x!='/'){
            zsd+=x;
            x=curr.get(); 
        }
        double xd = std::stod(xsd.c_str());
        double yd = std::stod(ysd.c_str());
        double zd = std::stod(zsd.c_str());
        xvector.push_back(xd);
        yvector.push_back(yd);
        zvector.push_back(zd);
    }
    return client_socket;
}

void SensorReceiver::calculateSteps(){
    steps = 0;
    for (int i = 0; i < yvector.size(); i++){
        if(yvector.at(i) <= -0.6){
            steps++;
        }
    }

}

int SensorReceiver::getSteps(){
    return steps;
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

void SensorReceiver::setSwitch(int n){
    onSwitch = n;
}





 // cout << ">> ";
// getline(std::cin, ch);
// if(ch.empty()) break;
// clear buffer

// If they click enter, end
// getline(cin, ch);
// if(ch.empty()) return -1;