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

Forward forwardingfile;

Protocols::Protocols() {
	// TODO Auto-generated constructor stub

}

Protocols::~Protocols() {
	// TODO Auto-generated destructor stub
}
//(originalsource,flag,finaldestination,timestamp,seq,ack,message)
string Protocols::sendProtocols(int flag, string ipclient, string finaldestination ,string message)
{
	packettosend.clear();
	ip = ipclient;
	CreatePacket createpacket;
	switch(flag)
	{
		case 1://forwarding packet
			packettosend = createpacket.sendPacket(ipclient,flag,finaldestination,0,0,message);
			break;
		case 2://forwarding packet?
			packettosend = createpacket.sendPacket(ipclient,flag,finaldestination,seqnrsend,acknrsend,message);
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
	packettosend.clear();
	CreatePacket createpacket;
	createpacket.receivePacket(packet);

	std::map<int32_t, Route> forward;

	switch(createpacket.getreceiveFlag())
	{
		case 1://routing packet received, so store it inside the forwardingtable
			forwardingfile.setForwardingTable(createpacket.getreceiveSource(),5,createpacket.getreceiveSource(),9,createpacket.getreceiveTimestamp());
			forwardingfile.checkforwardingTable(createpacket.getreceiveTimestamp());
			/*cout << "fuck" << endl;
			cout << createpacket.getreceiveMessage() << endl;
			cout << "hello" << endl;*/
			//forwardingfile.nexthopEntries(createpacket.getreceiveMessage());
			forward = forwardingfile.getForwardingTable();
			for(unsigned int i=0;i<forward.size();i++)
			{
			//cout << forward[i].ip << endl;
			packettosend.append(forward[i].ip);
			packettosend.append("|");
			packettosend.append(forward[i].nick);
			packettosend.append("|");
			packettosend.append(to_string(forward[i].lastseen));
			packettosend.append("|");
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
