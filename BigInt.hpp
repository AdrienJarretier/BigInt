#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <bitset>
#include <sstream>

class BigInt
{

private:

    std::bitset<8> currentValue;

public:

    BigInt(long long val);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

    friend BigInt operator+(const BigInt& factor1, const BigInt& factor2);

};

#endif // BIGINT_HPP
