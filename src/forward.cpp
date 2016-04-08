/*
 * forward.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: sertac
 */


#include "forward.h"

Forward::Forward(){
}
Forward::~Forward(){
}
void Forward::setForwardingTable(std::string ip, int32_t nextHop, std::string nick,int32_t keyp,int32_t lastseen){
	bool notinTable = true;
	for(unsigned int j = 0;j<forwardingTable.size();j++)
	{
		if(ip == forwardingTable[j].ip)
		{
			notinTable = false;
			forwardingTable[j].lastseen = lastseen;
		}
	}
	if(notinTable == true)
	{
		int i = forwardingTable.size();
		std::cout << forwardingTable.size() << "this is the forwardingtable size" << std::endl;
		Route m;
		m.ip = ip;
		if(nextHop != 0){
		m.nextHop = nextHop;
		}
		m.nick = nick;
		if(keyp != 0){
		m.keyp = keyp;
		}
		m.lastseen = lastseen;
		forwardingTable[i]=m;
		//std::cout << forwardingTable.size() << "size of the table" << std::endl;
	}
}

std::map<int32_t, Route> Forward::getForwardingTable()
{
	return forwardingTable;
}

void Forward::checkforwardingTable(int timestamp)
{
	for(unsigned int i =0; i<forwardingTable.size();i++)
	{
		if(((timestamp - forwardingTable[i].lastseen) > 20))
		{
			forwardingTable.erase(i);
		}
	}
}

void Forward::nexthopEntries(std::string entries)
{/*
	std::vector<std::string> result;
	std::istringstream iss(entries);

	for(std::string token; std::getline(iss,token,'|');)
	{
		result.push_back(move(token));
	}

	std::cout << "the entries cout" << result.size() << std::endl;
*/}
