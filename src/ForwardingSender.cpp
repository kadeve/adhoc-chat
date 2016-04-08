/*
 * ForwardingSender.cpp
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
#include "ForwardingSender.h"
#include "forward.h"

using namespace std;

Forward forwarding;
std::map<int32_t, Route> table;

int sendforwardingPacket(string ip, BlockingQueue<string> &sendingQueue){
	while(1)
	{
		Protocols protocol;
		//used to get the update table
		string forwardtableupdate = ip;
		forwardtableupdate.append(":1:1:1:1:1");
		cout << forwardtableupdate << endl;
		string message = protocol.receiveProtocols(forwardtableupdate);
		//send a breadcast signal
		string bla = protocol.sendProtocols(1,ip,"228.0.0.0",message);
		//push it on the sending queue
		sendingQueue.push(bla);
		sleep(10);
	}
	return 0;
}
