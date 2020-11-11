#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "./SensorReceiver.h"

using namespace std;

#define SERVER_PORT htons(5050)

int main() {

        char buffer[1000];
        int n;

        int serverSock=socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = SERVER_PORT;
        serverAddr.sin_addr.s_addr = INADDR_ANY;

        /* bind (this socket, local address, address length)
           bind server socket (serverSock) to server address (serverAddr).  
           Necessary so that server can use a specific port */ 
        bind(serverSock, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));

        // wait for a client
        /* listen (this socket, request queue length) */
        listen(serverSock,1);

        sockaddr_in clientAddr;
        socklen_t sin_size=sizeof(struct sockaddr_in);

        int clientSock=accept(serverSock,(struct sockaddr*)&clientAddr, &sin_size);
        cout << "[STARTING SERVER]" << (struct sockaddr*)&serverAddr << endl;
        

        while (1 == 1) {
                bzero(buffer, 1000);        

                //receive a message from a client
                n = read(clientSock, buffer, 500);
                string var = buffer;
                cout << "Confirmation code  " << n << endl;
                cout << "Server received as string from buffer:  " << var << endl;
                n = write(clientSock, buffer, strlen(buffer));
                cout << "Confirmation code  " << n << endl;
        }
        return 0;
}