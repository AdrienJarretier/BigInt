#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt defaultTest;

    BigInt test("10010");
    BigInt testAssignment("100");

    BigInt testCopyConstructor(test);

    BigInt testAssignementOperator("110");

    testAssignementOperator = testAssignment;


    cout << "defaultTest :             " << defaultTest << endl << endl;

    cout << "test :                    " << test << endl;
    cout << "testCopyConstructor :     " << testCopyConstructor << endl << endl;

    cout << "testAssignment :          " << testAssignment << endl;
    cout << "testAssignementOperator : " << testAssignementOperator << endl;

    return 0;
}
