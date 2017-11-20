/*
 * clientFD.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "clientFD.h"

#include <string.h> //memset
#include <arpa/inet.h> //struct

clientFD::clientFD() {
	clientFD_ = -1;

}

clientFD::~clientFD() {
	// TODO Auto-generated destructor stub
}

int clientFD::getClientFD() {
	return clientFD_;
}

void clientFD::setClientFD() {
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

	//TODO i think client should extend the socket for acess to sockFD
	//TODO
	//TODO

	clientFD_ = accept(-1/*sockfd should be here*/, (struct sockaddr *) &client_addr,
			(unsigned int *) &client_addr_len);
}

