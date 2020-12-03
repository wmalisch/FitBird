/**
 * @brief SensorReceiver is a class that receives messages from the client/sensor 
 * @details SensorReceiver operates as a server, using sockets to receive messages from the python client. This way users are unable to access the data or corrupt the data in the process
 * @author Will Malisch
 *
 */
#include "../headers/SensorReceiver.h"

using namespace std;

SensorReceiver * SensorReceiver::_instance = NULL;

 /**
 * @name instance
 * @brief Method for creating singleton
 * @details Get the singleton instance of the SensorReceiver, if one does not exist already create it
 * @param N/A
 * @author Will Malisch
 * @return Pointer to the instance of the SensorReceiver
 */
SensorReceiver * SensorReceiver::instance(){
    if(_instance == NULL){
        _instance = new SensorReceiver();
    }
    return _instance;   
}

 /**
 * @name        : SensorReceiver
 * @brief Constructor
 * @details : Get the singleton instance of the SensorReceiver, if one does not exist already create it
 * @param N/A
 * @return      : pointer to the instance of the SensorReceiver
 * @details : Constructor 
*/
SensorReceiver::SensorReceiver(){
    
}

/**
 * @brief Destructor
 * @details Destructor
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
SensorReceiver::~SensorReceiver(){
    /* Destroy data and memory allocated for acceleromter for this instance of the sensor */
}


/**
 * @brief Initialize sockets for sensor communication
 * @details Set up server sidde connection with sockets
 * @author Will Malisch
 * @param N/A
 * @return integer representing success or failure
 *
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

/**
 * @brief Activate connection with client
 * @details Wait for connection from python sensor client. When received, retrieve data until the user prompts to stop. Close socket when done.
 * @author Will Malisch
 * @param N/A
 * @return Integer representing success or failure
 *
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

/**
 * @brief Calculate steps
 * @details Iterate through vector of y coordinates and calculate steps
 * @author Will Malisch
 * @param N/A
 * @return Step count
 *
 */
void SensorReceiver::calculateSteps(){
    steps = 0;
    for (int i = 0; i < yvector.size(); i++){
        if(yvector.at(i) <= -0.6){
            steps++;
        }
    }

}

/**
 * @brief Accessor method for steps
 * @details Gets steps
 * @author Will Malisch
 * @param N/A
 * @return Step count
 *
 */
int SensorReceiver::getSteps(){
    return steps;
}

/**
 * @brief End the sensor
 * @details End sensor by closing socket 
 * @author Will Malisch
 * @param N/A
 * @return N/A
 *
 */
void SensorReceiver::end_sensor(){
    close(client_socket);
}

/**
 * @brief Accessor method for switch
 * @details Gets switch
 * @author Will Malisch
 * @param N/A
 * @return Integer representing if sensor is on or off
 *
 */
int SensorReceiver::getSwitch() const{
    return onSwitch;
}

/**
 * @brief Setter method for switch
 * @details Used to indicate the sensor is on
 * @author Will Malisch
 * @param Integer n to set switch
 * @return N/A
 *
 */
void SensorReceiver::setSwitch(int n){
    onSwitch = n;
}