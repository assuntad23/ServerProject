/*
 * DirectoryPage.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef DIRECTORYPAGE_H_
#define DIRECTORYPAGE_H_

#include "Pages.h"
#include <string>

class DirectoryPage: public Pages {
public:
	DirectoryPage();
	virtual ~DirectoryPage();
	std::string writeInfo();
};

#endif /* DIRECTORYPAGE_H_ */
