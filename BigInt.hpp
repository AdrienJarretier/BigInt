#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <bitset>
#include <sstream>

class BigInt
{

private:

    std::bitset<1> currentValue;

public:

    BigInt(long long val);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

};

#endif // BIGINT_HPP
