#pragma once
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

class BitString {
private:
	unsigned long field_1;
	unsigned long field_2;

public:
	BitString() : field_1(0), field_2(0) {}
	BitString(unsigned long f1, unsigned long f2) : field_1(f1), field_2(f2) {}

	unsigned long getField_1() const { return field_1; }
	unsigned long getField_2() const { return field_2; }

	void setField_1(unsigned long value) { field_1 = value; }
	void setField_2(unsigned long value) { field_2 = value; }

	void Init(unsigned long value1, unsigned long value2);
	void Read();
	void Display() const;
	string toString() const;

	void And_Operation(const BitString& other);
	void Or_Operation(const BitString& other);
	void Xor_Operation(const BitString& other);
	void Not_Operation(const BitString& other);
	void Shift_Right(int amount);
	void Shift_Left(int amount);
};