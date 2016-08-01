#include "BigInt.hpp"

#include <iostream>

using namespace std;

int main()
{
    BigInt defaultTest;
    cout << "defaultTest :             " << defaultTest << endl << endl;

    BigInt test("10010");
    BigInt testAssignment("1111111111");

    BigInt testCopyConstructor(test);

    BigInt testAssignementOperator("110");
    cout << "testAssignementOperator : " << testAssignementOperator << endl << endl;

    testAssignementOperator = testAssignment;



    cout << "test :                    " << test << endl;
    cout << "testCopyConstructor :     " << testCopyConstructor << endl << endl;

    cout << "testAssignment :          " << testAssignment << endl;
    cout << "testAssignementOperator : " << testAssignementOperator << endl;

    return 0;
}
