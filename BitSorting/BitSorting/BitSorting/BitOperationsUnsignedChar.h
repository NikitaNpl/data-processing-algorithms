#pragma once
#include <ostream>
#ifndef BitOperationsUnsignedChar_H
#define BitOperationsUnsignedChar_H

class BitOperationsUnsignedChar {
	public:
		BitOperationsUnsignedChar(unsigned char value);
		unsigned char getValue();
		void setValue(unsigned char value);
		void operator<<=(size_t pos);
		void operator>>=(size_t pos);
		void operator&=(const BitOperationsUnsignedChar& right);
		void operator|=(const BitOperationsUnsignedChar& right);
		bool operator!=(const BitOperationsUnsignedChar& right);
		void operator~();
		BitOperationsUnsignedChar operator<<(unsigned char value);
		BitOperationsUnsignedChar operator&(const BitOperationsUnsignedChar& right);
		BitOperationsUnsignedChar operator|(const BitOperationsUnsignedChar& right);

	private:
		unsigned char value;
		friend std::ostream& operator<<(std::ostream& out, BitOperationsUnsignedChar& value);
};

#endif // !BitOperations_H

