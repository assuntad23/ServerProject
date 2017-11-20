/*
 * Server.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "Server.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>
#include <cerrno> //errno
#include <string.h> //strerror / strcat

Server::Server() {
	ServerLog = fopen("ServerLog.txt", "w");

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::printingToFile(char StringForLog[]) {
	//declared a timer so that we can get the local time
	time_t rawtime;
	struct tm * timeEntrySt;
	char timeEntry[80];
	time(&rawtime);
	timeEntrySt = localtime(&rawtime);

	//using strftime so that I can format it on the same line.
	strftime(timeEntry, 80, "%c", timeEntrySt);

	//LogEntry will hold the time and the string being passed to the method
	char LogEntry[300];
	sprintf(LogEntry, "%s - ", timeEntry);
	strcat(LogEntry, StringForLog);

	if (errno != 0) {
		char errorEntry[300];
		sprintf(errorEntry, "The error number is %d - %s.\n", errno,
				strerror(errno));
	}

	//printing to file
	fprintf(ServerLog, LogEntry);

	//flushing so that it actually appears in file.
	fflush(ServerLog);
}

void Server::serverLog(int argc) {
	if (NULL == ServerLog) {
		throw std::runtime_error("ServerLog does not exist\n");

	}

	if (argc < 2) {
		throw std::runtime_error("Not enough arguments passed to the program");

	}
	if (argc > 2) {
		throw std::runtime_error("Too many arguments passed to the program");

	}
}

void Server::closeServer() {
	fclose(ServerLog);
}
