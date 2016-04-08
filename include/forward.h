#include <cstdint>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include "Route.h"
#include <string.h> //used for the strcpy function!
#include <time.h>
#include <vector>
#include <sstream>
#include <utility>

#ifndef FORWARD_H_
#define FORWARD_H_

class Forward {
public:
	Forward();
	~Forward();
	std::map<int32_t, Route> getForwardingTable();
	//int32_t getLastSeen();
	void checkforwardingTable(int timestamp);
	void nexthopEntries(std::string entries);
	void setForwardingTable(std::string ip, int32_t nextHop, std::string nick,int32_t keyp,int32_t lastseen);
private:
	std::map<int32_t, Route> forwardingTable;
};


#endif /* FORWARD_H_ */
