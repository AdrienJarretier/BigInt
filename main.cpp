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
    cout << "C + D = " << C + D << endl;

    return 0;
}
