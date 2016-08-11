#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <bitset>
#include <sstream>
#include <string>
#include <vector>

class BigInt
{

private:

    std::vector<bool> currentValue;
    BigInt twosComplement() const;

public:

    /** \brief Constructs a BigInt from string representing the integer in binary
     *
     * \param val Integer in base 2, negative if starts with '1', positive if starts with '0'
     *
     */
    BigInt(std::string val="0");

    /** \brief Constructs a BigInt from a long long integer
     *
     */
    BigInt(long long val);

    /** \brief Copy constructor
     *
     * \param other The BigInt to copy
     *
     */
    BigInt(const BigInt& other);

    /** \brief Returns a representation of the current held number in the requested base
     *
     * \param base The requested base
     * \return The representation of the current value
     *
     */
    std::string toBase(unsigned short int base);

    /** \brief Returns the current integer raised to the power of exponent
     *
     * \param exponent Exponent value
     *
     * \return The result of raising this to the power of exponent
     *
     */
    BigInt pow(const BigInt& exponent) const;

    /** \brief Returns the absolute value of our number
     *
     * \return Absolute value of our number
     *
     */
    BigInt abs() const;

    BigInt& operator=(const BigInt& other);
    BigInt& operator+=(const BigInt& term);
    BigInt& operator ++();
    BigInt  operator ++(int);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

    friend bool operator<(const BigInt& operand1, const BigInt& operand2);
    friend bool operator>(const BigInt& operand1, const BigInt& operand2);
    friend bool operator==(const BigInt& operand1, const BigInt& operand2);

    friend BigInt operator+(const BigInt& term1, const BigInt& term2);
    friend BigInt operator-(const BigInt& term1, const BigInt& term2);

    friend BigInt operator*(const BigInt& factor1, const BigInt& factor2);

};

#endif // BIGINT_HPP
