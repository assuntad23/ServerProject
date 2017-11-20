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
private:
	int clientFD_;
public:
	clientFD();
	virtual ~clientFD();

	int getClientFD();
	void setClientFD();
};

#endif /* CLIENTFD_H_ */
