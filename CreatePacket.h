/*
 * CreatePacket.h
 *
 *  Created on: 6 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#include <string>
#include <string.h> //used for the strcpy function!
#include <time.h>

#ifndef CREATEPACKET_H_
#define CREATEPACKET_H_

namespace std{

class CreatePacket {
public:
	CreatePacket();
	virtual ~CreatePacket();

	std::string sendPacket(int flag, int seq, std::string finaldestination, std::string originalsource, std::string message);
	void receivePacket(std::string packet);

	std::string getreceiveDestination();
	std::string getreceiveSource();
	std::string getreceiveMessage();
	std::string getreceiveTimestamp();
	int getreceiveSequence();
	int getreceiveFlag();
	int getreceiveSelect();

private:
	//if they are needed for getters, they are set in the function sendPacket (can be private)
	std::string sendDestination;
	std::string sendSource;
	int sendSequence;
	int sendFlag;
	std::string sendMessage;
	std::string sendTimestamp;

	//if they are needed for getters, they are set in the function receivedPacket (can be private)
	std::string receiveDestination;
	std::string receiveSource;
	int receiveSequence;
	int receiveSelect;
	int receiveFlag;
	std::string receiveMessage;
	std::string receiveTimestamp;

	//timestamp usages
	time_t rawtime;
	 struct tm * timeinfo;
};
}//end of namespace std

#endif /* CREATEPACKET_H_ */
