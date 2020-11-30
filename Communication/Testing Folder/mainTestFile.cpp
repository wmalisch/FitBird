#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

#define SERVER_PORT htons(5050)

int main(){

    // Create a scoket
    int server_socket = socket(AF_INET,SOCK_STREAM,0);
    if(server_socket == -1){
        cerr << "Error creating socket" << endl;
        return -1;
    }
    // Bind the socket to a IP/ port
    sockaddr_in serverAddr; 
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
    // char host[NI_MAXHOST];
    // char svc[NI_MAXSERV];
    cout << "About to Accept" << endl;
    int clientSocket = accept(server_socket, (struct sockaddr*)&client, &clientSize);
    cout << "accepted" << endl;

    if(clientSocket == -1){
        cerr << "[ERROR] Was not able to connect to socket" << endl;
        return -4;
    }
    // // // Close the listening socket
    // // close(server_socket);
    // memset(host,0,NI_MAXHOST);
    // memset(svc,0,NI_MAXSERV);
    
    // int result = getnameinfo((struct sockaddr*)&client, 
    //     sizeof(client), 
    //     host, 
    //     NI_MAXHOST,
    //     svc,
    //     NI_MAXSERV,
    //     0);

    //     // if(result){
    //     cout << host << " connected on " << svc << endl;
    //     // }else{
    //     //     inet_ntop(AF_INET,&client.sin_addr, host, NI_MAXHOST);
    //     //     cout << host << " connected on " << ntohs(client.sin_port) << endl;
    //     // }

    // While receiving - display message, echo message
    
    char buffer[4096];
    while(true){
        // clear buffer
        memset(buffer,0,4096);
        // wait for a message
        int bytesRecv = recv(clientSocket,buffer,4096,0);
        if (bytesRecv == -1){
            cerr << "Connection error";
            break;
        }
        if(bytesRecv==0){
            cout<<"Client disconnected";
            break;
        }
        cout<< "Received: " << string(buffer,0,bytesRecv) << endl;
    }

    // Close socket
    close(clientSocket);
    return 0;
}