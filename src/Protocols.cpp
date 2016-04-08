/*
 * Protocols.cpp
 *
 *  Created on: 7 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#include "Protocols.h"
#include <iostream>

using namespace std;

Forward fietsbel;

Protocols::Protocols() {
	// TODO Auto-generated constructor stub

}

Protocols::~Protocols() {
	// TODO Auto-generated destructor stub
}
//(originalsource,flag,finaldestination,timestamp,seq,ack,message)
string Protocols::sendProtocols(int flag, string ipclient, string finaldestination ,string message)
{
	ip = ipclient;
	CreatePacket createpacket;
	switch(flag)
	{
		case 1://forwarding packet
			packettosend = createpacket.sendPacket(ipclient,flag,finaldestination,seqnrsend,acknrsend,message);
			break;
		case 2://forwarding packet?

			break;
		case 3://syn packet?

			break;
		case 4://ack packet?
			packettosend = createpacket.sendPacket(ipclient,flag,finaldestination,seqnrsend,acknrsend,message);
			break;
		case 5://message packet to a desired person

			break;
		case 6://packet??

			break;
	}
	return packettosend;
}

//(originalsource,flag,finaldestination,timestamp,seq,ack,message)
string Protocols::receiveProtocols(string packet)
{
	CreatePacket createpacket;
	createpacket.receivePacket(packet);

	std::map<int32_t, Route> forward;

	switch(createpacket.getreceiveFlag())
	{
		case 1://routing packet received, so store it inside the forwardingtable
			fietsbel.setForwardingTable(createpacket.getreceiveSource(),5,createpacket.getreceiveSource(),9,createpacket.getreceiveTimestamp());
			forward = fietsbel.getForwardingTable();
			cout << "im here" << endl;
			for(unsigned int i=0;i<forward.size();i++)
			{
			cout << forward[i].ip << endl;
			cout << forward[i].nick << endl;
			cout << forward[i].keyp << endl;
			cout << forward[i].lastseen << endl;
			cout << forward[i].nextHop << endl;
			}
			break;
		case 2://forwarding packet

			break;
		case 3://syn packet?

			break;
		case 4://ack packet?
			packettosend = createpacket.sendPacket(createpacket.getreceiveSource()
					,createpacket.getreceiveFlag(),createpacket.getreceiveDestination()
					,createpacket.getreceiveSequence(),1,"ACK");
			break;
		case 5://message packet to a desired person

			break;
		case 6://packet??

			break;
	}
	return packettosend;
}
