/*
 * StatusPage.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef STATUSPAGE_H_
#define STATUSPAGE_H_

#include "Pages.h"
#include <string>

class StatusPage: public Pages {
public:
	StatusPage();
	virtual ~StatusPage();
	std::string writeInfo();
	std::string writeDateToSocket();
	std::string writeKernelInfoToSocket();
	std::string writeSystemInfoToSocket();
	std::string writeNetworkInfoToSocket(int portnum, std::string ipAddress);
};

#endif /* STATUSPAGE_H_ */
