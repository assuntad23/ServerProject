/*
 * ErrorPage.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef ERRORPAGE_H_
#define ERRORPAGE_H_

#include "Pages.h"
#include <string>

class ErrorPage: public Pages {
public:
	ErrorPage();
	virtual ~ErrorPage();
	std::string writeInfo();
};

#endif /* ERRORPAGE_H_ */
