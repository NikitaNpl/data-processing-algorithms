#include <iostream>
#include "BitOperationsUnsignedChar.h"

using namespace std;

int main() {
	BitOperationsUnsignedChar firstValue = BitOperationsUnsignedChar(255); // 11111111
	BitOperationsUnsignedChar secondValue = BitOperationsUnsignedChar(1); // 00000001

	secondValue <<= 4; // 00010000
	~secondValue; // 11101111
	firstValue &= secondValue; // 11111111 & 11101111 = 11101111

	cout << firstValue << endl;

	return 0;
}