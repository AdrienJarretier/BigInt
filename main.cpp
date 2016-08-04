#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt A("01100100"); // 4 + 32 + 64 = 100
    BigInt B("01010111"); // 1 + 2 + 4 + 16 + 64 = 87

    BigInt C("11111100"); // 252
    BigInt D("01010011"); // 1 + 2 + 16 + 64 = 83

    BigInt E("01011011"); // 1 + 2 + 8 + 16 + 64 = 91
    BigInt F("11001110"); // 2 + 4 + 8 + 64 + 128 = 206

    const unsigned short int BASE = 10;

    cout << "base " << BASE << endl << endl;

    cout << "A :     " << A << " : " << A.toBase(BASE) << endl;
    cout << "B :     " << B << " : " << B.toBase(BASE) << endl << endl;
    cout << "A * B = " << A * B << " : " << (A*B).toBase(BASE) << endl << endl;

    cout << "C :     " << C << " : " << C.toBase(BASE) << endl;
    cout << "D :     " << D << " : " << D.toBase(BASE) << endl << endl;
    cout << "C * D = " << C * D << " : " << (C*D).toBase(BASE) << endl << endl;

    cout << "E :     " << E << " : " << E.toBase(BASE) << endl;
    cout << "F :     " << F << " : " << F.toBase(BASE) << endl << endl;
    cout << "E * F = " << E * F << " : " << (E*F).toBase(BASE) << endl << endl;


    return 0;
}
