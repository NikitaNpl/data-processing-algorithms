#pragma once
#ifndef HashTableLinearProbingP_H
#define HashTableLinearProbing_H
#include <string>
#include <vector>

#include "HashNode.h"

class HashTableLinearProbing {
	private:
		std::vector<HashNode> tables;
		size_t size;
		
	public:
		HashTableLinearProbing();
		size_t hash(std::string str);
		void checkCapacity();
		bool insertNode(std::string key, std::string value);
		HashNode* findNode(std::string key, std::string value);
		bool deleteNode(std::string key, std::string value);
		size_t sizeOf();
		void display();
		void autoFill();
};

#endif // !HashTableLinearProbing_H
