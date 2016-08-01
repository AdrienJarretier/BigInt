#include "BigInt.hpp"

BigInt::BigInt(std::string val)
{
    for(auto c : val)
    {
        currentValue.push_back(c=='1');
    }
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

//    for(unsigned int i=term1.currentValue.size(); i<term2.currentValue.size(); i++)
//    {
//        term1.currentValue.insert(term1.currentValue.cbegin(),false);
//    }

    bool term1Biggest;

    if(term1.currentValue.size() > term2.currentValue.size())
    {
        result = term1;
        term1Biggest = true;
    }
    else
    {
        result = term2;
        term1Biggest = false;
    }

    if(result.currentValue[0])
    {
        result.currentValue.insert(result.currentValue.cbegin(), 0);
    }

    return result;
}
