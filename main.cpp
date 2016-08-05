#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt A("110"); // 6
    BigInt B("010"); // 2

    BigInt C("010"); // 2
    BigInt D("10"); // 2

    BigInt E("01011011"); // 1 + 2 + 8 + 16 + 64 = 91
    BigInt F("11001110"); // 2 + 4 + 8 + 64 + 128 = 206

    const unsigned short int BASE = 10;

    cout << "base " << BASE << endl << endl;

    cout << "A :     " << A << " : " << A.toBase(BASE) << endl;
    cout << "B :     " << B << " : " << B.toBase(BASE) << endl << endl;
    cout << "A * B = " << A * B << " : " << (A*B).toBase(BASE) << endl << endl;

    cout << "C :     " << C << " : " << C.toBase(BASE) << endl;
    cout << "D :     " << D << " : " << D.toBase(BASE) << endl << endl;
    cout << "D<C : " << (D<C) << endl << endl;

    cout << "E :     " << E << " : " << E.toBase(BASE) << endl;
    cout << "F :     " << F << " : " << F.toBase(BASE) << endl << endl;
    cout << "E * F = " << E * F << " : " << (E*F).toBase(BASE) << endl << endl;

    cout << "A^B : " << (A.pow(B)).toBase(BASE) << endl << endl;


    return 0;
}
