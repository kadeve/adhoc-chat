/*
 * Protocols.h
 *
 *  Created on: 7 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#ifndef PROTOCOLS_H_
#define PROTOCOLS_H_

#include <string>
#include "forward.h"
#include "CreatePacket.h"

class Protocols {
public:
	Protocols();
	virtual ~Protocols();

	std::string sendProtocols(int select, std::string ipclient, std::string finaldestination, std::string message);
	std::string receiveProtocols(std::string packet);

private:
	std::string packettosend;
	int seqnrsend = 0;
	int acknrsend = 0;
	int seqnrreceive = 0;
	int acknrreceive = 0;
	std::string ip;
};

#endif /* PROTOCOLS_H_ */
