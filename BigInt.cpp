#include "BigInt.hpp"

BigInt::BigInt(long long val)
:currentValue(val)
{}

std::ostream& operator<<(std::ostream& os, const BigInt& bi)
{
    os << bi.currentValue;
    return os;
}
