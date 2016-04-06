/*
 * forward.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: sertac
 */


#include "forward.h"


forward::forward(){
}
forward::~forward(){
}
void setForwardingTable(int32_t ip, int32_t nextHop, char*  nick,int32_t keyp,int32_t lastseen){
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


}
