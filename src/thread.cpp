#include <thread>
#include <cstring>
#include <unistd.h>

#include "receiver.h"
#include "sender.h"
#include "BlockingQueue.h"
#include "CreatePacket.h"
#include "Protocols.h"
#include "InterfaceSender.h"
#include "ForwardingSender.h"

#define PORT 14000 //The port you want to use
#define IP "192.168.5.2" //The IP address of this computer
#define GROUP "228.0.0.0" //The multicast group you want to use

using namespace std;

extern const string IPCLIENT = IP;

BlockingQueue<std::string> receiveQueue;
BlockingQueue<std::string> sendingQueue;

int main() {
	thread InterfaceSender(sendinterfacePacket, IP, std::ref(sendingQueue));
	thread ForwardingSender(sendforwardingPacket, IP, std::ref(sendingQueue));
	thread sender(sendPacket, IP, PORT, GROUP, std::ref(sendingQueue)); //start networking sending thread
	thread receiver(receivePacket, IP, PORT, GROUP, std::ref(receiveQueue)); //start network receiving thread

	CreatePacket createpacket;
	Protocols protocols;
	while(1)
	{
		string message = receiveQueue.pop();
		cout << "print it, with size: " << (int)message.size() << " message: " << message.c_str() << endl;

		createpacket.receivePacket(message);

		//if the flag is 1 the protocols will update the forwardingtable
		//this forwarding will then received in forwardingsender.cpp
		string forwarding = protocols.receiveProtocols(message);
		cout << forwarding << endl;

	}
}
