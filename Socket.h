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
public:
	Socket();
	virtual ~Socket();
};

#endif /* SOCKET_H_ */
