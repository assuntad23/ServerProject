/*
 * Socket.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "Socket.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <functional>   // std::bind

Socket::Socket() {
	sockfd = 0;
	address = 0;
	portnum = 0;
}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

int Socket::getSocket() {
	return sockfd;
}

void Socket::setPortNum(int newPort) {

	if (newPort < 0 || newPort > 65355) {
		throw("portNumError");

	}
}

int Socket::getPortNum() {
	return portnum;
}

int Socket::getAddress() {
	//Binding address to the socket
	// declare address variable
	struct sockaddr_in address;

	// set the address to the computer's IP Address
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(portnum);

	//binding the address to the socket
	int newAdress = bind(sockfd, (struct sockaddr *) &address, sizeof(address));

	return newAdress;
}

void Socket::setAddress(int newAddress) {
	address = newAddress;
}

void Socket::setSocket() {
	try {
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
	} catch (const std::exception &e) {

		if (sockfd == -1) {
			printingToFile("The socket was not created.");
			throw std::runtime_error("Error creating the socket\n");

		} else {
			printingToFile("Socket created successfully.\n");
		}
	}
}

int Socket::acceptConnectionLoop() {

	//TODO
	//this method declares clientfd in it in c version. The easiest way I can think to fix this is  tochange clientfd to extend off of socket
	//and put this method there, unless you see a logic problem later in the project I don't

	//Also, it makes direct calls to the pages prints, which I can not think of a way to properly implement right now

	/*
	 * int AcceptingConnectionsLoop(int result, int sockfd, int portnum) {
	 //Setting the socket to listen for incoming messages
	 result = listen(sockfd, 5);

	 //socket is set up now

	 //setting exit to 0, so that loop keeps on looking for connections
	 //if exit != 0, loop will exit and server will close (see sigHandler)
	 Exit = 0;
	 while (Exit == 0) {
	 //Accepting Connections
	 // declare a variables for the client address
	 struct sockaddr_in client_addr;
	 // need to initialize the length or
	 // accept may not return all the information
	 // in client_addr. use socklen_t as the datatype
	 // socklen_t is defined to the size needed in the
	 // sys/socket.h header file
	 socklen_t client_addr_len = sizeof(client_addr);

	 // initialize the client address
	 memset(&client_addr, 0, client_addr_len);

	 // call accept to get a connection
	 int clientfd = accept(sockfd, (struct sockaddr *) &client_addr,
	 (unsigned int *) &client_addr_len);

	 //connect to the socket from another computer with the IPaddress and socket #
	 //connect to the socket from this computer with just the socket #

	 if (clientfd == -1) {
	 printingToFile(
	 "The call to accept a connection was not successful.");
	 perror("Error");
	 return (1);
	 } else {
	 printingToFile(
	 "The call to accept a connection was successful. Waiting for a connection.\n");
	 }

	 //Reading a message from the socket
	 // declare variables to use
	 char buffer[65535];

	 // initialize the buffer
	 memset(buffer, 0, sizeof(buffer));

	 // read the message
	 read(clientfd, buffer, 65534);

	 //This is the status message we will be searching the buffer for
	 char status_message[20] = "GET /status ";
	 char dir_message[20] = "GET /dir";

	 //strstr compares two strings. if "GET /" appears in buffer, this will return a pointer
	 //if it does not it will return null. As long as it is not NULL, the user should go to either status page or directory
	 if (strcasestr(buffer, status_message) != NULL) {
	 printingToFile("Connection made for Status page.\n");
	 statusHTTP(clientfd, portnum);
	 } else if (strcasestr(buffer, dir_message) != NULL) {
	 printingToFile("Connection made for Directory.\n");
	 scanDirect(clientfd, buffer, portnum);
	 } else {
	 printingToFile(
	 "Connection not for Status or Directory. Page not found. Sending user to Error Page\n");
	 errorNotFoundHTTP(clientfd);
	 }

	 result = close(clientfd);
	 }

	 return (result);
	 }
	 */
	return 1;
}

