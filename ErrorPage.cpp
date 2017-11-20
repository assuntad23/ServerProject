/*
 * ErrorPage.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#include "ErrorPage.h"
#include <string>

ErrorPage::ErrorPage() {
	// TODO Auto-generated constructor stub

}

ErrorPage::~ErrorPage() {
	// TODO Auto-generated destructor stub
}

std::string ErrorPage::writeInfo(){

	std::string HTTPInfo = "HTTP/1.1 404 Not Found\r\n Server: ADJSDWeb v1.0\r\n Content-Type: text/html\r\n \r\n ";
	std::string HTMLInfo = "<html><head><title>Error Page</title></head><body><h1>ERROR</h1><h3>404 Error Not Found<h3></body></html>";

	return HTTPInfo + HTMLInfo;
}
