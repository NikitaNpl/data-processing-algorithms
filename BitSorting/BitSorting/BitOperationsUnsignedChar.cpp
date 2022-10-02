#include "BitOperationsUnsignedChar.h"
#include <bitset>

BitOperationsUnsignedChar::BitOperationsUnsignedChar(unsigned char value) {
	this->value = value;
}

unsigned char BitOperationsUnsignedChar::getValue() {
	return this->value;
}

void BitOperationsUnsignedChar::setValue(unsigned char value) {
	this->value = value;
}

void BitOperationsUnsignedChar::operator<<=(size_t pos) {
	 setValue(this->value << pos);
}

void BitOperationsUnsignedChar::operator>>=(size_t pos) {
	setValue(this->value >> pos);
}

void BitOperationsUnsignedChar::operator&=(const BitOperationsUnsignedChar& right) {
	setValue(this->value & right.value);
}

void BitOperationsUnsignedChar::operator|=(const BitOperationsUnsignedChar& right) {
	setValue(this->value | right.value);
}

bool BitOperationsUnsignedChar::operator!=(const BitOperationsUnsignedChar& right)
{
	return this->value != right.value;
}

void BitOperationsUnsignedChar::operator~() {
	setValue(~this->value);
}

BitOperationsUnsignedChar BitOperationsUnsignedChar::operator<<(unsigned char value) {
	return this->value << value;
}

BitOperationsUnsignedChar BitOperationsUnsignedChar::operator&(const BitOperationsUnsignedChar& right) {
	return this->value & right.value;
}

BitOperationsUnsignedChar BitOperationsUnsignedChar::operator|(const BitOperationsUnsignedChar& right) {
	return this->value | right.value;
}

std::ostream& operator<<(std::ostream& out, BitOperationsUnsignedChar& value) {
	unsigned char const receivedValue = value.getValue();
	return out << "result: " << std::bitset<8>(receivedValue) << "(" << int(receivedValue) << ")";
}
