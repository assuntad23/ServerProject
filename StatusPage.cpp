/*
 * StatusPage.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "StatusPage.h"
#include <string>
#include <time.h>
#include <sstream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/types.h>

StatusPage::StatusPage() {
	// constructor

}

StatusPage::~StatusPage() {
	// destructor
}

std::string StatusPage::writeInfo(){

	std::string HTTPInfo = "HTTP/1.1 200 OK\r\n Server: ADJSWeb v1.0\r\n Content-Type: text/html\r\n \r\n";
	std::string HTMLStart ="<html><head><title>Status Page</title></head><body><h1>Status:</h1>";
	std::string HTMLEnd = "</body></html>";

	writeDateToSocket();
	writeKernelInfoToSocket();
	writeSystemInfoToSocket();
//TODO	writeNetworkInfoToSocket(Socket.portnum());



	std::string StatusInfo = HTTPInfo + HTMLStart + HTMLEnd;
	return StatusInfo;
}

std::string StatusPage::writeDateToSocket(){

	//declared a timer so that we can get the local time
	time_t timer;
	timer = time(NULL);

	//converting time to a stringstream, so that I can then turn it into a string
	std::stringstream str;
	str << asctime(localtime(&timer));

	//declaring string for method to return
	std::string timeAndDate;

	//putting time info into timeAndDate string
	timeAndDate = str.str();

	return timeAndDate;
}

std::string StatusPage::writeKernelInfoToSocket(){
	//defining and calling a structure for the kernel information
	struct utsname unameData;
	uname(&unameData);

	// create kernel info string and add kernel info banner
	std::string kernelInfo = "<h2>***** KERNEL INFO *****</h2>";


	// Create formatted kernel info messages and concatenate them to kernel info string
	kernelInfo += "System Name: %s<br/>";
	kernelInfo += unameData.sysname;
	kernelInfo += "Release: %s<br/>";
	kernelInfo += unameData.release;
	kernelInfo += "Version: %s<br/>";
	kernelInfo += unameData.version;
	kernelInfo += "Machine: %s<br/>";
	kernelInfo += unameData.machine;
	kernelInfo += "Node Name: %s<br/><br/>";
	kernelInfo += unameData.nodename;

	//return kernelInfo
	return kernelInfo;
}

std::string StatusPage::writeSystemInfoToSocket(){

	//defining and calling a structure for the system information
	struct sysinfo systemInfo;
	sysinfo(&systemInfo);

	//create stystem info string and add system info banner
	std::string systemInformation = "<h2>***** SYSTEM INFO *****</h2>";


	// create formatted system information messages and concatenate them to system info string
	systemInformation += "Uptime: %ld</br>";
	systemInformation += systemInfo.uptime;
	systemInformation += "5 Minute Load Average: %ld</br>";
	systemInformation += systemInfo.loads[0];
	systemInformation += "10 Minute Load Average: %ld</br>";
	systemInformation += systemInfo.loads[1];
	systemInformation += "15 Minute Load Average: %ld</br>";
	systemInformation += systemInfo.loads[2];
	systemInformation += "Total RAM: %ld</br>";
	systemInformation += systemInfo.totalram;
	systemInformation += "Free RAM: %ld</br>";
	systemInformation += systemInfo.freeram;
	systemInformation += "Shared RAM: %ld</br>";
	systemInformation += systemInfo.sharedram;
	systemInformation += "Buffered RAM: %ld</br>";
	systemInformation += systemInfo.bufferram;
	systemInformation += "Total Swap: %ld</br>";
	systemInformation += systemInfo.totalswap;
	systemInformation += "Free Swap: %ld</br>";
	systemInformation += systemInfo.freeswap;
	systemInformation += "Processes: %hd</br>";
	systemInformation += systemInfo.procs;
	systemInformation +=  "Total High Memory: %ld</br>";
	systemInformation += systemInfo.totalhigh;
	systemInformation += "Free High Memory: %ld</br>";
	systemInformation += systemInfo.freehigh;
	systemInformation += "Memory Units (in bytes): %d</br>";
	systemInformation += systemInfo.mem_unit;

	return systemInformation;
}

std::string StatusPage::writeNetworkInfoToSocket(int portnum, std::string ipAddress){

	//declaring Strings
	std::string clientInfo = "<h2>***** CLIENT INFO *****</h2>";

	clientInfo += "Client IP Address: %s</br>";
	clientInfo += ipAddress;
	clientInfo += "Port Number: %d";
	clientInfo += portnum;

	return clientInfo;

}
