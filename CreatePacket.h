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
#include <vector>
#include <sstream>
#include <utility>
//#include <Windows.h> // included to use Sleep function

#ifndef CREATEPACKET_H_
#define CREATEPACKET_H_

namespace std{

class CreatePacket {
public:
	CreatePacket();
	virtual ~CreatePacket();

	std::string sendPacket(std::string originalsource, int flag, std::string finaldestination, /*timestamp*/ int seq, int ack, std::string message);
	void receivePacket(std::string packet);
	vector<string> explode(string const & s, char delim);

	std::string getreceiveDestination();
	std::string getreceiveSource();
	std::string getreceiveMessage();
	int getreceiveTimestamp();
	int getreceiveSequence();
	int getreceiveFlag();
	int getreceiveAck();
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
	int receiveAck;
	int receiveFlag;
	std::string receiveMessage;
	std::string receiveTimestamp;

	//timestamp usages
	time_t rawtime;
	struct tm * timeinfo;

	//extern const std::string ipclient;
	vector<string> receivepacket;
};
}//end of namespace std

#endif /* CREATEPACKET_H_ */
