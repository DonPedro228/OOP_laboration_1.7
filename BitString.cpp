#include "BitString.h"
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void BitString::Init(unsigned long value1, unsigned long value2)
{
	setField_1(value1);
	setField_2(value2);
}

void BitString::Read()
{
	cout << "Enter value for field_1: "; cin >> field_1;
	cout << "Enter value for field_2: "; cin >> field_2;
	Init(field_1, field_2);
}

void BitString::Display() const
{
	cout << "Field_1: " << bitset<64>(field_1) << endl;
	cout << "Field_2: " << bitset<64>(field_2) << endl;
}

string BitString::toString() const
{
	return bitset<64>(field_1).to_string() + " " + bitset<64>(field_2).to_string();
}

void BitString::And_Operation(const BitString& other)
{
	field_1 &= other.field_1;
	field_2 &= other.field_2;
}

void BitString::Or_Operation(const BitString& other)
{
	field_1 |= other.field_1;
	field_2 |= other.field_2;
}

void BitString::Xor_Operation(const BitString& other)
{
	field_1 ^= other.field_1;
	field_2 ^= other.field_2;
}

void BitString::Not_Operation(const BitString& other)
{
	field_1 = ~field_1;
	field_2 = ~field_2;
}

void BitString::Shift_Left(int amount)
{
	field_1 <<= amount;
	field_2 <<= amount;
}

void BitString::Shift_Right(int amount)
{
	field_1 >>= amount;
	field_2 >>= amount;
}

