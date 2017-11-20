/*
 * PermDenied.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "PermDenied.h"

PermDenied::PermDenied() {
	// TODO Auto-generated constructor stub

}

PermDenied::~PermDenied() {
	// TODO Auto-generated destructor stub
}


std::string PermDenied::writeInfo(){
	//creating HTTP string
	std::string HTTPInfo = "HTTP/1.1 403 Forbidden\r\n Server: ADJSDWeb v1.0\r\n Content-Type: text/html\r\n\r\n";
	//creating HTML string
	std::string HTMLInfo = "<html><head><title>Error Page</title></head><body><h1>FORBIDDEN</h1><h3>403 Forbidden<h3></body></html>";

	//returning both
	return HTTPInfo + HTMLInfo;
}
