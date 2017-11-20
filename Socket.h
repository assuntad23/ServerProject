/*
 * Socket.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "Server.h"

class Socket: public Server {

private:
	int sockfd;
	int address;
	int portnum;

public:
	Socket();
	virtual ~Socket();

	void setSocket();
	int getSocket();

	int getPortNum();
	void setPortNum(int newPortNum);

	int getAddress();
	void setAddress(int newAdress);

	int acceptConnectionLoop();

};

#endif /* SOCKET_H_ */

