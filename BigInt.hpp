#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <sstream>
#include <string>
#include <vector>

class BigInt
{

private:

    std::vector<bool> currentValue;

public:

    /**
     * Construct a BigInt from string representing the integer in binary
     *
     * @param val integer in base 2
    **/
    BigInt(std::string val="0");

    BigInt(const BigInt& other);
    BigInt& operator=(const BigInt& other);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

    friend BigInt operator+(const BigInt& factor1, const BigInt& factor2);

};

#endif // BIGINT_HPP
