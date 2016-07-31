#include "BigInt.hpp"

BigInt::BigInt(long long val)
:currentValue(val)
{}

BigInt::BigInt(const BigInt& other)
:currentValue(other.currentValue)
{}

BigInt& BigInt::operator=(const BigInt& other)
{
    currentValue = other.currentValue;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bi)
{
    os << bi.currentValue;
    return os;
}

BigInt operator+(const BigInt& factor1, const BigInt& factor2)
{
    BigInt result;
//    if(factor2.currentValue.size() > factor1.currentValue.size)
//    {
//
//    }
}
