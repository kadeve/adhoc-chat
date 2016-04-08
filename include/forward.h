#include <cstdint>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include "Route.h"
#ifndef FORWARD_H_
#define FORWARD_H_

class Forward {
public:
	Forward();
	~Forward();
	std::map<int32_t, Route> getForwardingTable();
	//int32_t getLastSeen();
	void setForwardingTable(std::string ip, int32_t nextHop, std::string nick,int32_t keyp,int32_t lastseen);
private:
	std::map<int32_t, Route> forwardingTable;
};


#endif /* FORWARD_H_ */
