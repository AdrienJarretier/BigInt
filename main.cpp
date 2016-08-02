#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt A("10010");
    BigInt B("00101");

    cout << "A :     " << A << endl;
    cout << "B :     " << B << endl;
    cout << "A + B = " << A + B << endl << endl;

    BigInt C("001");
    BigInt D("111");

    cout << "C :     " << C << endl;
    cout << "D :     " << D << endl;
    cout << "C + D = " << C + D << endl << endl;

    cout << "A < B : (should be false) " << (A < B) << endl;
    cout << "C < D : (should be true) " << (C < D) << endl;
    cout << "A < D : (should be false) " << (A < D) << endl;
    cout << "C < A : (should be true) " << (C < A) << endl << endl;

    return 0;
}
