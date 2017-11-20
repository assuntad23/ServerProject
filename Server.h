/*
 * Server.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>


class Server {
private:
	FILE *ServerLog;

public:
	Server();
	virtual ~Server();

	void serverLog(int argc);
	void printingToFile(char StringForLog[]);
	void closeServer();

};

#endif /* SERVER_H_ */
