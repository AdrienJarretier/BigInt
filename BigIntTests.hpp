#ifndef BIGINTTESTS_HPP
#define BIGINTTESTS_HPP

#include "BigInt.hpp"

#include <iostream>

/** \brief Static tests methods for the BigInt class
 *
 * \details These methods provide some quick and simple *basics* tests.
 * Each one of them instanciates some BigInt objects and **cout** some infos so you can see if results are wrong.
 *
 * **Those tests are far from perfect,
 * it's just basic stupid testing so I can compare results with what I would expect, nothing more**
 *
 * **Do not expect a method tested here to have no bugs just because the test seems ok.**
 *
 */
class BigIntTests
{

public :

    /** \brief Pre and post increment operators */
    static void increment();

    /** \brief Display some BigInt to base 10 */
    static void toBase();

    /** \brief Relationals and equality operators */
    static void comparisons();

    /** \brief Addition between BigInt, may they be positive or negative */
    static void addition();

};

#endif // BIGINTTESTS_HPP
