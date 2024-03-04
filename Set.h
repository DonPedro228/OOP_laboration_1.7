#pragma once
#include "BitString.h"
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;

class Set {
private:
	BitString data;

public:
	Set() {};

	void Add_Element(int element);
	void Remove_Element(int element);

	Set Union_Set(const Set& other) const;
	Set Interest_Set(const Set& other) const;

	Set difference_Set(const Set& other) const;
	int Count_Elem() const;


	void Init(unsigned long value1, unsigned long value2);
	void Read();
	void Display() const;
	string toString() const;
};