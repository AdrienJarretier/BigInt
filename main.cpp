#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt A("10010");
    BigInt B("00101");

    const unsigned short int BASE = 16;

    cout << "base " << BASE << endl << endl;

    cout << "A :     " << A << " : " << A.toBase(BASE) << endl;
    cout << "B :     " << B << " : " << B.toBase(BASE) << endl;
    cout << "A + B = " << A + B << " : " << (A+B).toBase(BASE) << endl << endl;

    BigInt C("1010");
    BigInt D("0101");

    cout << "C :     " << C << " : " << C.toBase(BASE) << endl;
    cout << "D :     " << D << " : " << D.toBase(BASE) << endl;
    cout << "C + D = " << C + D << " : " << (C+D).toBase(BASE) << endl << endl;

    return 0;
}
