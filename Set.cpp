#include "Set.h"
#include "BitString.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>
using namespace std;

void Set::Add_Element(int element) {
    if (element >= 0 && element < 64)
        data.Or_Operation(BitString(1UL << element, 0));
    else if (element >= 64 && element < 128)
        data.Or_Operation(BitString(0, 1UL << (element - 64)));
    else
        cout << "Element out of range" << endl;
}

void Set::Remove_Element(int element)
{
    if (element >= 0 && element < 64) {
        data.And_Operation(BitString(~(1UL << element), ~0UL));
    }
    else if (element >= 64 && element < 128) {
        data.And_Operation(BitString(~0UL, ~(1UL << (element - 64))));
    }
    else
        cout << "Element out of range: " << endl;
}


Set Set::Union_Set(const Set& other) const
{
    Set result;
    result.Init(data.getField_1() | other.data.getField_1(), data.getField_2() | other.data.getField_2());
    return result;
}

Set Set::Interest_Set(const Set& other) const
{
    Set result;
    BitString intersection_field(data.getField_1(), data.getField_2());
    intersection_field.And_Operation(other.data);
    result.Init(intersection_field.getField_1(), intersection_field.getField_2());
    return result;
}

Set Set::difference_Set(const Set& other) const
{
    Set result;
    result.data.Xor_Operation(other.data);
    return result;
}

int Set::Count_Elem() const
{
    BitString shiftedData = data; 
    int count = 0;

    
    shiftedData.Shift_Left(1);
    for (int i = 0; i < 64; ++i) {
        if (shiftedData.getField_1() & (1UL << i)) ++count;
    }
    for (int i = 0; i < 64; ++i) {
        if (shiftedData.getField_2() & (1UL << i)) ++count;
    }

    
    shiftedData.Shift_Right(1);

    return count;
}


string Set::toString() const
{
    return data.toString();
}

void Set::Init(unsigned long value1, unsigned long value2)
{

    data.Init(value1, value2);
}

void Set::Display() const
{
    data.Display();
}

void Set::Read()
{
    data.Read();
}

