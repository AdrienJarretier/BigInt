#include "BigInt.hpp"

BigInt::BigInt(long long val)
:currentValue(val)
{}

std::ostream& operator<<(std::ostream& os, const BigInt& bi)
{
    os << bi.currentValue;
    return os;
}

BigInt operator+(const BigInt& factor1, const BigInt& factor2)
{
//    if(factor2.currentValue.size() > factor1.currentValue.size)
//    {
//
//    }
}
