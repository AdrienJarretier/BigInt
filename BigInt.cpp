#include "BigInt.hpp"

BigInt::BigInt(std::string val)
:currentValue(val.size())
{

}

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
    for(auto dig : bi.currentValue)
    {
        os << dig;
    }
    return os;
}

BigInt operator+(const BigInt& term1, const BigInt& term2)
{
    BigInt result;
//    // first test whi
//    if(term1.currentValue.size() > term2.currentValue.size())
//    {
//        result = term1;
//    }
//    else
//    {
//        result = term2;
//    }
//
//    if(result.currentValue.test(0))
//    {
//        result.currentValue = std::bitset<result.currentValue.size()*2> currentValue;
//    }

    return result;
}
