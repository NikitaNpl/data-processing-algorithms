#include "HashTableLinearProbing.h"
#include <iostream>

HashTableLinearProbing::HashTableLinearProbing() {
	size = 0;
}

size_t HashTableLinearProbing::hash(const char* str) {
	unsigned int seed = 131; // 31 131 1313 13131 131313 
	unsigned int hash = 0;
	while (*str) {
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF) % tables.size();
}

void HashTableLinearProbing::checkCapacity() {
	if (tables.size() == 0 || size * 10 / tables.size() >= 7) {
		size_t newSize = tables.size() * 2;
		if (newSize == 0) {
			newSize = 10;
		}

		HashTableLinearProbing newHt;
		newHt.tables.resize(newSize);
		for (size_t i = 0; i < tables.size(); i += 1) {
			if (tables[i].state == EXIST) {
				newHt.insertNode(tables[i].key, tables[i].value);
			}
		}
		tables.swap(newHt.tables);
	}
}

bool HashTableLinearProbing::insertNode(std::string key, std::string value) {

	checkCapacity();
	
	if (findNode(key)) {
		return false;
	}

	size_t i = 1;
	size_t index = hash(key.c_str());
	size_t start = index;

	while (tables[index].state == EXIST) {
		index += 1;
		i += 1;
		if (index == tables.size()) {
			index = 0;
		}
	}
	tables[index].key = key;
	tables[index].value = value;
	tables[index].state = EXIST;
	size++;
	return true;
}

HashNode* HashTableLinearProbing::findNode(std::string key) {
	size_t index = hash(key.c_str());
	size_t start = index;
	int i = 1;
	while (tables[index].state != EMPTY) {
		if (tables[index].key == key) {
			if (tables[index].state == EXIST) {
				return &tables[index];
			} else {
				return NULL;
			}
		}
		index += 1;
		i += 1;
		if (index == tables.size())
		{
			index = 0;
		}
	}
	return NULL;
}

bool HashTableLinearProbing::deleteNode(std::string key) {

	HashNode* node = findNode(key);
	if (node) {
		node->state = DELETE;
		size -= 1;
		return true;
	} else {
		return false;
	}
}

size_t HashTableLinearProbing::sizeOf() {
	return size;
}

void HashTableLinearProbing::display() {
	for (int i = 0; i < tables.size(); i++) {
		std::cout << (tables[i].state == EXIST) << endl;
		if (tables[i].state == EXIST) {
			std::cout << "key = " << tables[i].key << " value = " << tables[i].value << std::endl;
		}
	}
}

