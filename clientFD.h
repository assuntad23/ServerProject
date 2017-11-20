/*
 * clientFD.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef CLIENTFD_H_
#define CLIENTFD_H_

#include "Server.h"

class clientFD: public Server {
public:
	clientFD();
	virtual ~clientFD();
};

#endif /* CLIENTFD_H_ */
