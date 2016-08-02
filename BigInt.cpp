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

bool operator<(const BigInt& operand1, const BigInt& operand2)
{
    unsigned int i=0;

    while(i<operand1.currentValue.size() && operand1.currentValue[i]!=1)
    {
        i++;
    }

    unsigned int op1DigitRank = operand1.currentValue.size()-1-i;



    i=0;

    while(i<operand2.currentValue.size() && operand2.currentValue[i]!=1)
    {
        i++;
    }

    unsigned int op2DigitRank = operand2.currentValue.size()-1-i;


}

bool operator>(const BigInt& operand1, const BigInt& operand2)
{

}

BigInt operator+(const BigInt& term1, const BigInt& term2)
{
    BigInt result, termToAdd;

//    for(unsigned int i=term1.currentValue.size(); i<term2.currentValue.size(); i++)
//    {
//        term1.currentValue.insert(term1.currentValue.cbegin(),false);
//    }

    if(term1.currentValue.size() > term2.currentValue.size())
    {
        result = term1;
        termToAdd = term2;
    }
    else
    {
        result = term2;
        termToAdd = term1;
    }

    if(result.currentValue[0])
    {
        result.currentValue.insert(result.currentValue.begin(), 0);
    }

    bool carry = false;
    std::vector<bool>::reverse_iterator resultRit = result.currentValue.rbegin();
    for(std::vector<bool>::reverse_iterator termToAddRit = termToAdd.currentValue.rbegin(); termToAddRit != termToAdd.currentValue.rend(); ++termToAddRit)
    {
        carry = *resultRit && *termToAddRit;
        *resultRit = *resultRit != *termToAddRit;
        ++resultRit;
    }
    *resultRit = carry;

    return result;
}
