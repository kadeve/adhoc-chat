/*
 * CreatePacket.cpp
 *
 *  Created on: 6 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#include "CreatePacket.h"
#include <iostream>
#include <sstream>

namespace std {

CreatePacket::CreatePacket() {
	// TODO Auto-generated constructor stub
}

CreatePacket::~CreatePacket() {
	// TODO Auto-generated destructor stub
}

string CreatePacket::sendPacket(std::string originalsource, int flag, std::string finaldestination, /*timestamp*/ int seq, int ack, std::string message)
{
	//if they are needed for getters, they are set here!!
	sendDestination = finaldestination;
	sendSource = originalsource;
	sendSequence = seq;
	sendFlag = flag;
	sendMessage = message;
	string data;

	data.append(originalsource);
	data.push_back(':');

	std::ostringstream fla;
	fla << flag;
	data.append(fla.str());
	data.push_back(':');

	data.append(finaldestination);
	data.push_back(':');

	time_t timer;
	time(&timer);
	std::ostringstream times;
	times << timer;
	data.append(times.str());
	data.push_back(':');

	std::ostringstream se;
	se << seq;
	data.append(se.str());
	data.push_back(':');

	std::ostringstream select;
	select << ack;
	data.append(select.str());
	data.push_back(':');

	data.append(message);

	return data;
}

void CreatePacket::receivePacket(std::string packet)
{
	receivepacket = explode(packet, ':');
	cout << receivepacket[0] << endl;//source
	cout << receivepacket[1] << endl;//flag
	cout << receivepacket[2] << endl;//destination
	cout << receivepacket[3] << endl;//timestamp
	cout << receivepacket[4] << endl;//sequence
	cout << receivepacket[5] << endl;//ack
	cout << receivepacket[6] << endl;//message
}

string CreatePacket::getreceiveDestination()
{
	return receivepacket[2];
}

string CreatePacket::getreceiveSource()
{
	return receivepacket[0];
}

int CreatePacket::getreceiveSequence()
{
	return stoi(receivepacket[4],nullptr,0);
}

int CreatePacket::getreceiveAck()
{
	return stoi(receivepacket[5],nullptr,0);
}

int CreatePacket::getreceiveFlag()
{
	return stoi(receivepacket[1],nullptr,0);
}

string CreatePacket::getreceiveMessage()
{
	return receivepacket[6];
}

int CreatePacket::getreceiveTimestamp()
{
	return stoi(receivepacket[3],nullptr,0);
}

vector<string> CreatePacket::explode(string const & s, char delim)
{
	vector<string> result;
	istringstream iss(s);

	for(std::string token; std::getline(iss,token,delim);)
	{
		result.push_back(move(token));
	}
	return result;
}

} /* namespace std */
