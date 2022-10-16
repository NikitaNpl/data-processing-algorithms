#pragma once
#ifndef HashNode_H
#define HashNode_H
#include <string>

using namespace std;

enum State {
	EMPTY,
	EXIST,
	DELETE,
};

class HashNode {
	public:
		string key;
		string value;
		State state;
		HashNode();
};

#endif // !HashNode_H
