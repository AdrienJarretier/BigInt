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

BigInt::BigInt(const BigInt& other)
:currentValue(other.currentValue)
{}

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

std::string BigInt::toBase(unsigned short int base)
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
    for(auto value : result)
    {
        numberRepresentation += (value < 10 ? '0'+value : 'A'+value-10);
    }

    return numberRepresentation;
}

void BigInt::test_toBase()
{
    const unsigned int BASE = 10;

    BigInt A("11111000"); // - 8
    BigInt B("00001000"); // 8
    BigInt C("011"); // 3
    BigInt D("01"); // 1
    BigInt E("11"); // - 1
    BigInt F("1011"); // - 5

    std::cout << "BASE " << BASE << std::endl << std::endl;

    std::cout << "A : " << A << " : " << A.toBase(BASE) << std::endl;
    std::cout << "B : " << B << " : " << B.toBase(BASE) << std::endl;
    std::cout << "C : " << C << " : " << C.toBase(BASE) << std::endl;
    std::cout << "D : " << D << " : " << D.toBase(BASE) << std::endl;
    std::cout << "E : " << E << " : " << E.toBase(BASE) << std::endl;
    std::cout << "F : " << F << " : " << F.toBase(BASE) << std::endl;
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

void BigInt::test_comparisons()
{
    const unsigned int BASE = 10;

    BigInt A("00001000"); // 8
    BigInt B("11"); // - 1
    BigInt C("1011"); // - 5

    std::cout << "BASE " << BASE << std::endl << std::endl;

    std::cout << "A : " << A << " : " << A.toBase(BASE) << std::endl;
    std::cout << "B : " << B << " : " << B.toBase(BASE) << std::endl;
    std::cout << "C : " << C << " : " << C.toBase(BASE) << std::endl << std::endl;

    std::cout << "A > B : " << (A>B) << " : " << (B<A) << std::endl;
    std::cout << "A > C : " << (A>C) << " : " << (C<A) << std::endl;
    std::cout << "B > C : " << (B>C) << " : " << (C<B) << std::endl << std::endl;

    std::cout << "A < B : " << (A<B) << " : " << (B>A) << std::endl;
    std::cout << "A < C : " << (A<C) << " : " << (C>A) << std::endl;
    std::cout << "B < C : " << (B<C) << " : " << (C>B) << std::endl;
}

bool operator==(const BigInt& operand1, const BigInt& operand2)
{
    // we virtually eliminate non significant leading zeros
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

    if(op1DigitRank==op2DigitRank)
    {
        while(i>0)
        {
            --i;
            if(operand1.currentValue[i]!=operand2.currentValue[i])
            {
                return false;
            }
        }
    }

    return true;
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

void BigInt::test_increment()
{
    BigInt A("110"); // 6
    BigInt B("010"); // 2

    BigInt C("011"); // 2
    BigInt D("11"); // 2

    std::cout << "A : " << A << std::endl;
    std::cout << "B : " << B << std::endl;
    std::cout << "C : " << C << std::endl;
    std::cout << "D : " << D << std::endl << std::endl;

    std::cout << "++A -> " << ++A << std::endl;
    std::cout << "++B -> " << ++B << std::endl;
    std::cout << "++C -> " << ++C << std::endl;
    std::cout << "++D -> " << ++D << std::endl << std::endl;

    std::cout << "A++ -> " << A++ << std::endl;
    std::cout << "B++ -> " << B++ << std::endl;
    std::cout << "C++ -> " << C++ << std::endl;
    std::cout << "D++ -> " << D++ << std::endl << std::endl;

    std::cout << "A : " << A << std::endl;
    std::cout << "B : " << B << std::endl;
    std::cout << "C : " << C << std::endl;
    std::cout << "D : " << D << std::endl << std::endl;
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

BigInt operator*(const BigInt& factor1, const BigInt& factor2)
{
    BigInt f1(factor1), result;

    for(std::vector<bool>::const_reverse_iterator rit = factor2.currentValue.rbegin(); rit != factor2.currentValue.rend(); ++rit)
    {
        if(*rit)
        {
            result += f1;
        }
        f1.currentValue.push_back(0);
    }

    return result;
}

BigInt BigInt::pow(const BigInt& exponent) const
{
    BigInt result("1");

//    std::cout << "exp : " << exponent << std::endl;

    for(BigInt e("0"); e<exponent; e+=BigInt("1"))
    {
//        std::cout << "e : " << e << std::endl;
        result = result * (*this);
    }

    return result;
}

