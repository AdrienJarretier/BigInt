#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt sinque(5);
    BigInt moinsQuatre(4);

    unsigned int BASE = 10;
//
//    cout << sinque << endl;
//    cout << moinsQuatre << endl;

    cout << sinque.toBase(BASE) << " * " << moinsQuatre.toBase(BASE) << " = " << (sinque*moinsQuatre).toBase(BASE) << endl;
    cout << sinque.toBase(BASE) << "^" << moinsQuatre.toBase(BASE) << " = " << (sinque.pow(moinsQuatre)).toBase(BASE) << endl;

    return 0;
}
