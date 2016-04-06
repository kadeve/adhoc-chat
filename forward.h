#include <cstdint>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "Route.h"
#ifndef FORWARD_H_
#define FORWARD_H_

class forward {
public:
	forward();
	~forward();
	std::map<int32_t, Route> getForwardingTable();
	//int32_t getLastSeen();
	void setForwardingTable(int32_t ip, int32_t nextHop, char* nick,int32_t keyp,int32_t lastseen);
private:
	std::map<int32_t, Route> forwardingTable;
};


#endif /* FORWARD_H_ */
