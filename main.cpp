#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{

//      std::bitset<40> foo (2512);
//
//  std::cout << foo << endl;

    BigInt test(18);

    BigInt testCopy(test);

    BigInt testCopy2 = test;

    cout << "test :      " << test << endl;
    cout << "testCopy :  " << testCopy << endl;
    cout << "testCopy2 : " << testCopy2 << endl;

    return 0;
}
