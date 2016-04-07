#include <thread>
#include <cstring>
#include <unistd.h>

#include "receiver.h"
#include "sender.h"
#include "BlockingQueue.h"
#include "CreatePacket.h"

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

		CreatePacket createpacket;
		createpacket.receivePacket(message);

		std::string ipdestination;
		for(int i=3;i<14;i++)
		{
			ipdestination.push_back(message[i]);
		}

		if (IP==ipdestination)
		{
			cout << ipdestination << " This is a packet for you!!" << endl;
		}
		cout << "print it, with size: " << (int)message.size() << " message: " << message.c_str() << endl;
	}
}
