#include <thread>
#include <cstring>
#include <unistd.h>

#include "receiver.h"
#include "sender.h"
#include "BlockingQueue.h"
#include "CreatePacket.h"
#include "Protocols.h"

#define PORT 14000 //The port you want to use
#define IP "192.168.5.2" //The IP address of this computer
#define GROUP "228.0.0.0" //The multicast group you want to use

using namespace std;

extern const string IPCLIENT = IP;

BlockingQueue<std::string> q;

int main() {
	thread sender(sendPacket, IP, PORT, GROUP); //start networking sending thread
	thread receiver(receivePacket, IP, PORT, GROUP, std::ref(q)); //start network receiving thread

	while(1)
	{
		std::string message = q.pop();
		cout<<"GOT A PACKET"<<endl;
		CreatePacket createpacket;
		createpacket.receivePacket(message);

		Protocols protocol;
		if(createpacket.getreceiveFlag()==1)
		{
			protocol.receiveProtocols(message);
			cout << "forwardingpacket!!" << endl;
		}

		if(IP==createpacket.getreceiveDestination())
		{
			cout << createpacket.getreceiveDestination() << " This is a packet for you!!" << endl;
		}
		cout << "print it, with size: " << (int)message.size() << " message: " << message.c_str() << endl;

		if(createpacket.getreceiveAck()==0 and createpacket.getreceiveFlag()==4)
		{
			q.push(protocol.receiveProtocols(message));
		}
		if(createpacket.getreceiveAck()==1 and createpacket.getreceiveFlag()==4)
		{
			cout << "ack is received" << endl;
		}
	}
}
