#include <cstdint>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#ifndef FORWARD_H_
#define FORWARD_H_

namespace protocol {

class forward {
public:
	forward();
	~forward();
	std::map<int32_t, int32_t, char*,char*,int32_t> getForwardingTable();
	//int32_t getLastSeen();
	std::map<int32_t, int32_t, char*,char*,int32_t> forwardingTable;
};

} /* namespace protocol */

#endif /* FORWARD_H_ */
