#include "pch.h"

#include "BigInt.hpp"

BigInt::BigInt(std::string val)
{
    unsigned int i=0;
    // count extra leading zeros or ones for negative
    while(i+1<val.size() && ((val[i]=='0' && val[i+1]=='0') || (val[i]=='1' && val[i+1]=='1')))
    {
        ++i;
    }

    // start the copy ignoring the extra leading zeros or ones
    // e.g :0001110 => 01110
    while(i<val.size())
    {
        currentValue.push_back(val[i]=='1');
        ++i;
    }
}

BigInt::BigInt(long long val)
{
    std::bitset<sizeof(long long)*8> binaryVal(val);

    for(unsigned int i=1; i<binaryVal.size()+1; ++i)
    {
        currentValue.push_back(binaryVal[binaryVal.size()-i]);
    }
}

BigInt::BigInt(const BigInt& other)
:currentValue(other.currentValue)
{}

std::string BigInt::toBase(unsigned short int base) const
{
    BigInt valueCopy(*this);

    bool negative = false;
    if(valueCopy.currentValue[0]) // if it's negative we're gonna save it's negative and get the two's complement
    {
        negative = true;
        valueCopy.currentValue.flip();
        ++valueCopy;
    }

    std::vector<unsigned short int> power2 = {1};

    std::vector<unsigned short int> result = {0};

    if( *(valueCopy.currentValue.rbegin()) )
    {
        result[0]=1;
    }

    // we handle the least significant bit before the loop so we start the loop at rbegin + 1
    for(std::vector<bool>::reverse_iterator rit=std::next(valueCopy.currentValue.rbegin()); rit!=valueCopy.currentValue.rend(); ++rit)
    {
        // multiply each element of power2 by 2 (using modulus to stay in the given base)
        for(std::vector<unsigned short int>::reverse_iterator p2rit=power2.rbegin(); p2rit!=power2.rend(); ++p2rit)
        {
            *p2rit = *p2rit * 2;
        }
        unsigned short int quotient = 0;
        for(std::vector<unsigned short int>::reverse_iterator p2rit=power2.rbegin(); p2rit!=power2.rend(); ++p2rit)
        {
            *p2rit = *p2rit + quotient;
            quotient = *p2rit / base;
            *p2rit = *p2rit % base;
        }
        // add elements to the left in power2 while quotient != 0
        while(quotient != 0)
        {
            power2.insert(power2.begin(), quotient%base);
            quotient = quotient / base;
        }

        // now we have the correct power of 2 corresponding to the rank we're at
        // if we have a 1 here we're gonna add that power of 2 to our result

        if(*rit)
        {
            if(result.size()<power2.size())
            {
                result.insert(result.begin(), power2.size()-result.size(), 0);
            }

            std::vector<unsigned short int>::reverse_iterator resultRit = result.rbegin();
            for(std::vector<unsigned short int>::reverse_iterator p2rit = power2.rbegin(); p2rit != power2.rend(); ++p2rit)
            {
                *resultRit = *resultRit + *p2rit;
                ++resultRit;
            }

            unsigned short int quotient = 0;
            for(std::vector<unsigned short int>::reverse_iterator resultRit=result.rbegin(); resultRit!=result.rend(); ++resultRit)
            {
                *resultRit = *resultRit + quotient;
                quotient = *resultRit / base;
                *resultRit = *resultRit % base;
            }
            // add elements to the left in result while quotient != 0
            while(quotient != 0)
            {
                result.insert(result.begin(), quotient%base);
                quotient = quotient / base;
            }
        }
    }

    // ok, now last thing we need to do is convert our result to a string

    std::string numberRepresentation((negative ? "-" : ""));
    if(base < 95)
    {
        for(auto value : result)
        {
            numberRepresentation += (value < 10 ? '0'+value : 'A'+value-10);
        }
    }
    else if (base == 95) // need all printable ASCII characters
    {
        for(auto value : result)
        {
            numberRepresentation += 32+value;
        }
    }

    return numberRepresentation;
}

std::string BigInt::toASCII() const
{
    const unsigned short int BASE = 95; // printable ASCII characters from 32 to 126

    return toBase(BASE);
}

BigInt BigInt::pow(const BigInt& exponent) const
{
    if(exponent == 0)
    {
        return 1;
    }
    else if(exponent == 1)
    {
        return *this;
    }
    else if(*exponent.currentValue.rbegin()) // if exponent is odd
    {
        BigInt expCopy = exponent-1;
        expCopy.currentValue.erase(std::prev(expCopy.currentValue.end()));
        return (*this)*((*this)*(*this)).pow(expCopy);
    }
    else
    {
        BigInt expCopy = exponent;
        expCopy.currentValue.erase(std::prev(expCopy.currentValue.end()));
        return ((*this)*(*this)).pow(expCopy);
    }
}

BigInt BigInt::abs() const
{
    if(this->currentValue[0])
    {
        return twosComplement();
    }
    else
    {
        return *this;
    }
}

BigInt& BigInt::operator=(const BigInt& other)
{
    currentValue = other.currentValue;
    return *this;
}

BigInt& BigInt::operator+=(const BigInt& term)
{
    (*this) = (*this)+term;
    return *this;
}

BigInt& BigInt::operator ++()
{
    std::vector<bool>::reverse_iterator rit=currentValue.rbegin();

    while(rit!=currentValue.rend() && *rit)
    {
        *rit = !*rit;
        rit++;
    }

    if(rit!=currentValue.rend())
    {
        *rit = !*rit;
    }

    // if we're just on the first digit aka (rend-1),
    // it means the msb was 0 so we need to insert a 0
    if(rit == std::prev(currentValue.rend()))
    {
        currentValue.insert(currentValue.begin(), 0);
    }

    return *this;
}

BigInt  BigInt::operator ++(int)
{
    BigInt this_copy(*this);

    ++(*this);

    return this_copy;
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
    std::vector<bool> cv1=operand1.currentValue; //cv stands for currentValue
    std::vector<bool> cv2=operand2.currentValue;

    //first, test for msb
    if(cv1[0] != cv2[0])
    {
        return cv1[0];
    }

    if(cv1.size() < cv2.size())
    {
        cv1.insert(cv1.begin(),cv2.size()-cv1.size(),cv2[0]);
    }
    else if(cv1.size() > cv2.size())
    {
        cv2.insert(cv2.begin(),cv1.size()-cv2.size(),cv1[0]);
    }

    for(unsigned int i=1; i<cv1.size(); i++)
    {
        if(cv1[i] != cv2[i])
        {
            return !cv1[i];
        }
    }

//     at this point we have equality so we can return a false
    return false;
}

bool operator>(const BigInt& operand1, const BigInt& operand2)
{
    std::vector<bool> cv1=operand1.currentValue; //cv stands for currentValue
    std::vector<bool> cv2=operand2.currentValue;

    //first, test for msb
    if(cv1[0] != cv2[0])
    {
        return !cv1[0];
    }

    if(cv1.size() < cv2.size())
    {
        cv1.insert(cv1.begin(),cv2.size()-cv1.size(),cv2[0]);
    }
    else if(cv1.size() > cv2.size())
    {
        cv2.insert(cv2.begin(),cv1.size()-cv2.size(),cv1[0]);
    }

    for(unsigned int i=1; i<cv1.size(); i++)
    {
        if(cv1[i] != cv2[i])
        {
            return cv1[i];
        }
    }

//     at this point we have equality so we can return a false
    return false;
}

bool operator==(const BigInt& operand1, const BigInt& operand2)
{
    BigInt op1 = operand1;
    BigInt op2 = operand2;

    std::vector<bool>& cv1=op1.currentValue; //cv stands for currentValue
    std::vector<bool>& cv2=op2.currentValue;

    if(cv1.size() < cv2.size())
    {
        cv1.insert(cv1.begin(),cv2.size()-cv1.size(),cv1[0]);
    }
    else if(cv1.size() > cv2.size())
    {
        cv2.insert(cv2.begin(),cv1.size()-cv2.size(),cv2[0]);
    }

    return !(op1 < op2 || op1 > op2);
}

BigInt operator+(const BigInt& term1, const BigInt& term2)
{
    BigInt t1 = term1;
    BigInt t2 = term2;

    std::vector<bool>& cv1=t1.currentValue; //cv stands for currentValue
    std::vector<bool>& cv2=t2.currentValue;

    if(cv1.size() < cv2.size())
    {
        cv1.insert(cv1.begin(),cv2.size()-cv1.size(),cv1[0]);
    }
    else if(cv1.size() > cv2.size())
    {
        cv2.insert(cv2.begin(),cv1.size()-cv2.size(),cv2[0]);
    }

    bool carry = false, nextCarry=false;
    for(unsigned int j=1; j<cv1.size()+1; ++j)
    {
        unsigned int i = cv1.size()-j;
        carry = nextCarry;
        nextCarry = (cv1[i] && cv2[i]) || (carry && (cv1[i] || cv2[i]));
        cv1[i] = (!carry && (cv1[i] != cv2[i])) || (carry && (cv1[i] == cv2[i]));
    }

    // if numbers are both positives or negatives, there is no overflow, we should insert
    if(term1.currentValue[0] == term2.currentValue[0])
    {
        if(nextCarry)
        {
            cv1.insert(cv1.begin(),1);
        }
        if( !term1.currentValue[0] )
        {
            cv1.insert(cv1.begin(),0);
        }
    }

    return t1;
}

BigInt operator-(const BigInt& term1, const BigInt& term2)
{
    return  term1 + term2.twosComplement();
}

BigInt operator*(const BigInt& factor1, const BigInt& factor2)
{
    BigInt f1 = factor1.abs(), f2 = factor2.abs(), result;

    for(std::vector<bool>::const_reverse_iterator rit = f2.currentValue.rbegin(); rit != f2.currentValue.rend(); ++rit)
    {
        if(*rit)
        {
            result += f1;
        }
        f1.currentValue.push_back(0);
    }

    if(factor1.currentValue[0] != factor2.currentValue[0])
    {
        result.currentValue.flip();
        ++result;
    }

    return result;
}

BigInt BigInt::twosComplement() const
{
    BigInt result = *this;

    result.currentValue.flip();
    ++result;

    return result;
}

