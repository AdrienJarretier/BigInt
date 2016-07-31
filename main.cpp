#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt test(18);
    BigInt testAssignment(4);

    BigInt testCopyConstructor(test);

    BigInt testAssignementOperator(6);

    testAssignementOperator = testAssignment;

    cout << "test :                    " << test << endl;
    cout << "testCopyConstructor :     " << testCopyConstructor << endl << endl;

    cout << "testAssignment :          " << testAssignment << endl;
    cout << "testAssignementOperator : " << testAssignementOperator << endl;

    return 0;
}
