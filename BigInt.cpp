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

std::string BigInt::toBase(unsigned short int base)
{
    std::vector<unsigned short int> power2 = {1};

    std::vector<unsigned short int> result = {0};

    if(*currentValue.rbegin())
    {
        result[0]=1;
    }

    // we handle the least significant bit before the loop so we start the loop at rbegin + 1
    for(std::vector<bool>::reverse_iterator rit=std::next(currentValue.rbegin()); rit!=currentValue.rend(); ++rit)
    {
        // multiply each element of power2 by 2 (using modulus to stay in the given base)
        for(std::vector<bool>::reverse_iterator p2rit=power2.rbegin(); p2rit!=power2.rend(); ++p2rit)
        {
            *p2rit = *p2rit * 2;
        }
        unsigned short int quotient = 0;
        for(std::vector<bool>::reverse_iterator p2rit=power2.rbegin(); p2rit!=std::prev(power2.rend()); ++p2rit)
        {
            *p2rit = *p2rit + ;
            quotient =
        }
    }
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

    while(i<operand1.currentValue.size() && !operand1.currentValue[i])
    {
        i++;
    }

    // if all digits are set to 0 then at this point rank = 0;
    unsigned int op1DigitRank = operand1.currentValue.size()-i;



    i=0;

    while(i<operand2.currentValue.size() && operand2.currentValue[i]!=1)
    {
        i++;
    }

    // same as before here
    unsigned int op2DigitRank = operand2.currentValue.size()-i;


    // if ranks are different, it means the lowest of the 2 operands is the one that have a '1' at the lowest rank
    if(op1DigitRank != op2DigitRank)
    {
        return op1DigitRank < op2DigitRank;
    }
    else // if ranks are the same, we have to compare each digits one to one
    {
        i = op1DigitRank;

        while(i>0)
        {
            // if at one rank digits are different, then we have a strict lesser than.
            if(operand1.currentValue[i-1] != operand2.currentValue[i-1])
            {
                return !operand1.currentValue[i-1];
            }

            i--;
        }
    }

    // at this point we have equality so we can return a false
    return false;
}

bool operator>(const BigInt& operand1, const BigInt& operand2)
{
    unsigned int i=0;

    while(i<operand1.currentValue.size() && !operand1.currentValue[i])
    {
        i++;
    }

    // if all digits are set to 0 then at this point rank = 0;
    unsigned int op1DigitRank = operand1.currentValue.size()-i;



    i=0;

    while(i<operand2.currentValue.size() && operand2.currentValue[i]!=1)
    {
        i++;
    }

    // same as before here
    unsigned int op2DigitRank = operand2.currentValue.size()-i;


    // if ranks are different, it means the greatest of the 2 operands is the one that have a '1' at the highest rank
    if(op1DigitRank != op2DigitRank)
    {
        return op1DigitRank > op2DigitRank;
    }
    else // if ranks are the same, we have to compare each digits one to one
    {
        i = op1DigitRank;

        while(i>0)
        {
            // if at one rank digits are different, then we have a strict greater than.
            if(operand1.currentValue[i-1] != operand2.currentValue[i-1])
            {
                return operand1.currentValue[i-1];
            }

            i--;
        }
    }

    // at this point we have equality so we can return a false
    return false;
}

BigInt operator+(const BigInt& term1, const BigInt& term2)
{
    BigInt result, termToAdd;

    if(term1 > term2)
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

    bool carry = false, nextCarry=false;
    std::vector<bool>::reverse_iterator resultRit = result.currentValue.rbegin();
    for(std::vector<bool>::reverse_iterator termToAddRit = termToAdd.currentValue.rbegin(); termToAddRit != termToAdd.currentValue.rend(); ++termToAddRit)
    {
        carry = nextCarry;
        nextCarry = (*resultRit && *termToAddRit) || (carry && (*resultRit || *termToAddRit));
        *resultRit = (!carry && (*resultRit != *termToAddRit)) || (carry && (*resultRit == *termToAddRit));
        ++resultRit;
    }
    while(nextCarry)
    {
        nextCarry = *resultRit;
        *resultRit = !*resultRit;
        ++resultRit;
    }

    return result;
}
