/*
 * BasicRoute.h
 *
 *  Created on: 10 mrt. 2015
 *      Author: Jaco
 */
#include <cstdint>

#ifndef BASICROUTE_H_
#define BASICROUTE_H_

class Route {
public:
	Route();
	~Route();
	int32_t nextHop = 0;
	int32_t ip;
	char* nick;
	int32_t keyp = 0;
	int32_t lastseen = 0;
};

#endif /* BASICROUTE_H_ */
