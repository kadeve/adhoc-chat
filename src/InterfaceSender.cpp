/*
 * InterfaceSender.cpp
 *
 *  Created on: 8 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "CreatePacket.h"
#include "Protocols.h"
#include "BlockingQueue.h"
#include "InterfaceSender.h"

using namespace std;

int sendinterfacePacket(string ip, BlockingQueue<string> &sendingQueue){
	while(1)
	{
		//get the message
		std::string message = {};
		getline(cin,message);

		if(message.size()>0)
		{
		string destinationip;
		if(message[0]=='J')
		{
			destinationip ="192.168.5.5";
			cout << "Private to Jan Willem" <<endl;
			message.erase(message.begin());
			message.erase(message.begin());
		}
		else if(message[0]=='S')
		{
			destinationip ="192.168.5.1";
			cout << "Private to Sertac" <<endl;
			message.erase(message.begin());
			message.erase(message.begin());
		}
		else if(message[0]=='Y')
		{
			destinationip ="192.168.5.3";
			cout << "Private to Yvo" <<endl;
			message.erase(message.begin());
			message.erase(message.begin());
		}
		else if(message[0]=='G')
		{
			destinationip ="192.168.5.2";
			cout << "Private to Gerrit" <<endl;
			message.erase(message.begin());
			message.erase(message.begin());
		}
		else
		{
			destinationip = "228.0.0.0";
			cout << "Multicast, send to everyone" <<endl;
		}

		Protocols protocol;
		//2 as information packet!
		string bla = protocol.sendProtocols(2,ip,destinationip,message);

		//send bla to the queue!!!
		cout << bla << endl;
		if(bla.size()>0)
		{
		sendingQueue.push(bla);
		}
		}
	}
	return 0;
}
