/*
 * ForwardingSender.h
 *
 *  Created on: 8 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

int sendforwardingPacket(std::string ip, BlockingQueue<std::string> &sendingQueue);
