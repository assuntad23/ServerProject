/*
 * PermDenied.h
 *
 *  Created on: Nov 14, 2017
 *      Author: adesanto
 */

#ifndef PERMDENIED_H_
#define PERMDENIED_H_

#include "Pages.h"
#include <string>

class PermDenied: public Pages {
public:
	PermDenied();
	virtual ~PermDenied();
	std::string writeInfo();
};

#endif /* PERMDENIED_H_ */
