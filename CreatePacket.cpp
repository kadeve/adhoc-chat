/*
 * CreatePacket.cpp
 *
 *  Created on: 6 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#include "CreatePacket.h"
#include <iostream>

namespace std {

CreatePacket::CreatePacket() {
	// TODO Auto-generated constructor stub
}

CreatePacket::~CreatePacket() {
	// TODO Auto-generated destructor stub
}

string CreatePacket::sendPacket(int flag, int seq, std::string finaldestination, std::string originalsource, std::string message)
{
	//if they are needed for getters, they are set here!!
	sendDestination = finaldestination;
	sendSource = originalsource;
	sendSequence = seq;
	sendFlag = flag;
	sendMessage = message;

	int headerlength = 25;
	char data[headerlength+message.length()+1];
	int packetselect = 1;

	//Fill the header
	data[0] = packetselect;
	data[1] = flag;
	data[2] = seq;

	//finaldestination
	char destinationchar[finaldestination.size()];
	strcpy(destinationchar, finaldestination.c_str());
	destinationchar[finaldestination.size()] = 0;
	for(unsigned int i = 0;i<finaldestination.size();i++)
	{
		data[i+3] = destinationchar[i];
	}

	//originalsource
	char sourcechar[originalsource.size()];
	strcpy(sourcechar, originalsource.c_str());
	sourcechar[originalsource.size()] = 0;
	for(unsigned int i = 0;i<originalsource.size();i++)
	{
		data[i+14] = sourcechar[i];
	}

/*	//message put inside the packet
	char messagechar[message.size()];
	strcpy(messagechar, message.c_str());
	messagechar[message.size()] = 0;
	for(unsigned int i = 0;i<message.size();i++)
	{
		data[i+25] = messagechar[i];
	}*/

	data[headerlength]=(char)NULL;

	string messagestring(data);

	time (&rawtime);
	timeinfo = localtime(&rawtime);
	string timestamp = asctime(timeinfo);
	sendTimestamp = timestamp;

	//timestamp has a size of 25!!
	messagestring.append(timestamp);
	messagestring.append(message);
//	cout << messagestring << endl;
	return messagestring;
}

void CreatePacket::receivePacket(std::string packet)
{
	//packet to char array
	char data[packet.size()];
	strcpy(data, packet.c_str());
	data[packet.size()] = 0;

	//Fill the information fields
	receiveSelect = data[0];
	receiveFlag = data[1];
	receiveSequence = data[2];

	//finaldestination
	char tmp[12];
	//add nullpointer such that the strings at the end have an end
	tmp[11] = (char)NULL;
	for(unsigned int i = 0;i<11;i++)
	{
		tmp[i] = data[i+3];
	}
	string receivedestination(tmp);
	receiveDestination = receivedestination;

	//originalsource
	//use same tmp as for the destination
	for(unsigned int i = 0;i<11;i++)
	{
		tmp[i] = data[i+14];
	}
	string receivesource(tmp);
	receiveSource = receivesource;

	//timestamp put inside the packet!
	char tmp2[25];
	for(unsigned int i = 25;i<50;i++)
	{
		tmp2[i-25] = data[i];
	}
	tmp2[packet.size()-25] = (char)NULL;
	string receivetimestamp(tmp2);
	receiveTimestamp = receivetimestamp;

	//message put inside the packet
	//use new temporary storage
	char tmp3[packet.size()-49];
	for(unsigned int i = 50;i<packet.size();i++)
	{
		tmp3[i-50] = data[i];
	}
	tmp3[packet.size()-50] = (char)NULL;
	string receivemessage(tmp3);
	receiveMessage = receivemessage;
}

string CreatePacket::getreceiveDestination()
{
	return receiveDestination;
}

string CreatePacket::getreceiveSource()
{
	return receiveSource;
}

int CreatePacket::getreceiveSequence()
{
	return receiveSequence;
}

int CreatePacket::getreceiveSelect()
{
	return receiveSelect;
}

int CreatePacket::getreceiveFlag()
{
	return receiveFlag;
}

string CreatePacket::getreceiveMessage()
{
	return receiveMessage;
}

string CreatePacket::getreceiveTimestamp()
{
	return receiveTimestamp;
}

} /* namespace std */
