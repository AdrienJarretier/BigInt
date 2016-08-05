#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

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
    BigInt& operator+=(const BigInt& term);

    /**
     * Return a representation of the current held number in the requested base
     *
     * @param base The requested base
     *
     * @return the representation of the current value
    **/
    std::string toBase(unsigned short int base);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

    friend bool operator<(const BigInt& operand1, const BigInt& operand2);
    friend bool operator>(const BigInt& operand1, const BigInt& operand2);
    friend bool operator==(const BigInt& operand1, const BigInt& operand2);
    friend BigInt operator+(const BigInt& term1, const BigInt& term2);
    friend BigInt operator*(const BigInt& factor1, const BigInt& factor2);

    BigInt pow(const BigInt& exponent) const;

};

#endif // BIGINT_HPP
