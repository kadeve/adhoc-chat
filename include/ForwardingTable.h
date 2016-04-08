/*
 * ForwardingTable.h
 *
 *  Created on: 6 apr. 2016
 *      Author: Yvo Deleare and Gerrit Kas
 * 		Group : 9
 */

#ifndef FORWARDINGTABLE_H_
#define FORWARDINGTABLE_H_

#include <vector>
#include <string>

namespace std {

class ForwardingTable {
public:
	ForwardingTable();
	virtual ~ForwardingTable();

	void fillForwardingTable(string ip, string data);
	bool checkForwardingTable();
	vector<string> getForwardingTable();

private:
	vector<string> forwardingtable;
};

} /* namespace std */

#endif /* FORWARDINGTABLE_H_ */
