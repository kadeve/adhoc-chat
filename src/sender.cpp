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

using namespace std;

int sendPacket(string ip, uint port, string group){

	int sock = -1;

	try
	{
		/**
		 * Create a new datagram socket 
		 */
		if( (sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
			throw std::runtime_error("Socket creation failed");

		/**
		 * Enable/Disable loopback. (loop = 0 is disabled, loop =1 is enabled)
		 * This allows you to receive multicast packets you yourself have send.
		 * Obviously enabling this is not really useful for anything but testing
		 */
		char loop = 1;
		if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&loop, sizeof(loop)) < 0)
			throw std::runtime_error("Failed to disable loopback");

		/**
		 * Set the interface to send multicast packets on.
		 * This should be our own IP address
		 */
		struct in_addr local = {0};
		local.s_addr = inet_addr(ip.c_str());
		if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, (char *)&local, sizeof(local)) < 0)
			throw std::runtime_error("Local interface failed");

		/**
		 * Fill in the sockaddr_in to specify the destination of datagrams
		 * In this case this is simply a port and multicast group address
		 */
		struct sockaddr_in multicastSender = {0};
		multicastSender.sin_family = AF_INET;
		multicastSender.sin_port = htons(port);

		//send a packet every 5 seconds
		while(1){

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

			multicastSender.sin_addr.s_addr = inet_addr(destinationip.c_str());

			Protocols protocol;
			std::string bla = protocol.sendProtocols(1,ip,destinationip,message);

			if (sendto(sock, bla.c_str(), bla.size(), 0, (struct sockaddr*)&multicastSender,sizeof(struct sockaddr_in)) < 0) //sent a UDP packet containing our example data
				    perror("Sendto failed");
			cout << "Packet of size " << (int)bla.size() << " sent!" << endl;
			//fflush(stdout);
			//printf("Packet of size %d sent!\n", (int)bla.size());
			//sleep(5);
			}
		}
	} catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	if(sock != -1)
		close(sock);

	return 0;
}