/*
 * ServerProject.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */
#include "Server.h"
#include "Socket.h"
#include "clientFD.h"

#include <stdlib.h>     /* atoi */

int main(int argc, char **argv) {
	Server serverOne; //creates an instance of server
	serverOne.serverLog(argc); //creates the server/serverfile based on argc

	Socket socketOne; //creates an instance of socket
	socketOne.setSocket(); //sets the socket
	socketOne.setPortNum(atoi(argv[1])); //sets portnum to first argument
	socketOne.setAddress(socketOne.getAddress()); //sets current adress to the adress you get

	clientFD clientOne;
	clientOne.setClientFD(); //suppose to set client information, but doesn't have access to client, so returns -1 for now

	//accepting connection Loop

	serverOne.closeServer(); //closes the server before exiting
	return 0;
}

