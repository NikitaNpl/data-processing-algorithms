#include "HashTableLinearProbing.h"
#include <iostream>

HashTableLinearProbing::HashTableLinearProbing() {
	size = 0;
}

size_t HashTableLinearProbing::hash(std::string str) {
	const int HASH_MUL = 31;
	unsigned int hash = 0;
	for (char const& c : str) {
		hash += hash * HASH_MUL + unsigned int(c);
	}
	
	return (hash) % tables.size();
}

// ������������� ���-�������
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

// ������� ���� � ���-�������
bool HashTableLinearProbing::insertNode(std::string key, std::string value) {

	/**
	  * �������� �� ���������� �������� � ���������� 
	  * �������������� ��� �������������
	  */
	checkCapacity(); 

	/* �������� �� ���������� */
	if (findNode(key, value)) {
		return false;
	}

	size_t i = 1;
	size_t index = hash(key);
	size_t start = index;
	
	// ���� ��������� ������
	while (tables[index].state == EXIST) {
		index += 1;
		i += 1;
	}

	// ���������� ����������� ������
	tables[index].key = key;
	tables[index].value = value;
	tables[index].state = EXIST;
	size++;
	return true;
}

// ����� ���� �� ���-�������
HashNode* HashTableLinearProbing::findNode(std::string key, std::string value) {
	size_t index = hash(key);
	size_t start = index;
	int i = 1;
	/**
      * ��������, ���� �� ��� ��� ���� ������� ��� �������� ��������
	  * ���� ��, �� ���������� ��� ���� � ��������, �
	  * �������� �� ������������� � ������ ������
	*/
	while (tables[index].state != EMPTY) {
		if (tables[index].key == key && tables[index].value == value) {
			if (tables[index].state == EXIST) {
				return &tables[index];
			} else {
				return NULL;
			}
		}
		index += 1;
		i += 1;
	}
	return NULL;
}

// �������� ���� �� ���-�������
bool HashTableLinearProbing::deleteNode(std::string key, std::string value) {

	HashNode* node = findNode(key, value);
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
		if (tables[i].state == EXIST) {
			std::cout << "key = " << tables[i].key << " value = " << tables[i].value << std::endl;
		}
	}
}

void HashTableLinearProbing::autoFill() {
	this->insertNode("01.03.02", "��� �����");
	this->insertNode("19.03.01", "��� �����");
	this->insertNode("12.03.04", "����");
	this->insertNode("10.05.05", "����");
	this->insertNode("09.03.02", "��� �����");
	this->insertNode("09.03.04", "��� ���");
	return;
}

