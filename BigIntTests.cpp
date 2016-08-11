#include "BigIntTests.hpp"

void BigIntTests::increment()
{
    BigInt A("110"); // 6
    BigInt B("010"); // 2

    BigInt C("011"); // 2
    BigInt D("11"); // 2

    std::cout << "A : " << A << std::endl;
    std::cout << "B : " << B << std::endl;
    std::cout << "C : " << C << std::endl;
    std::cout << "D : " << D << std::endl << std::endl;

    std::cout << "++A -> " << ++A << std::endl;
    std::cout << "++B -> " << ++B << std::endl;
    std::cout << "++C -> " << ++C << std::endl;
    std::cout << "++D -> " << ++D << std::endl << std::endl;

    std::cout << "A++ -> " << A++ << std::endl;
    std::cout << "B++ -> " << B++ << std::endl;
    std::cout << "C++ -> " << C++ << std::endl;
    std::cout << "D++ -> " << D++ << std::endl << std::endl;

    std::cout << "A : " << A << std::endl;
    std::cout << "B : " << B << std::endl;
    std::cout << "C : " << C << std::endl;
    std::cout << "D : " << D << std::endl << std::endl;
}

void BigIntTests::toBase()
{
    const unsigned int BASE = 10;

    BigInt A("11111000"); // - 8
    BigInt B("00001000"); // 8
    BigInt C("011"); // 3
    BigInt D("01"); // 1
    BigInt E("11"); // - 1
    BigInt F("1011"); // - 5

    std::cout << "BASE " << BASE << std::endl << std::endl;

    std::cout << "A : " << A << " : " << A.toBase(BASE) << std::endl;
    std::cout << "B : " << B << " : " << B.toBase(BASE) << std::endl;
    std::cout << "C : " << C << " : " << C.toBase(BASE) << std::endl;
    std::cout << "D : " << D << " : " << D.toBase(BASE) << std::endl;
    std::cout << "E : " << E << " : " << E.toBase(BASE) << std::endl;
    std::cout << "F : " << F << " : " << F.toBase(BASE) << std::endl;
}

void BigIntTests::comparisons()
{
    const unsigned int BASE = 10;

    BigInt A("00001000"); // 8
    BigInt B("11"); // - 1
    BigInt C("1011"); // - 5
    BigInt D("0101"); // 5
    BigInt E("01000"); // 8

    std::cout << "BASE " << BASE << std::endl << std::endl;

    std::cout << "A : " << A << " : " << A.toBase(BASE) << std::endl;
    std::cout << "B : " << B << " : " << B.toBase(BASE) << std::endl;
    std::cout << "C : " << C << " : " << C.toBase(BASE) << std::endl;
    std::cout << "D : " << D << " : " << D.toBase(BASE) << std::endl;
    std::cout << "E : " << E << " : " << E.toBase(BASE) << std::endl << std::endl;

    std::cout << "A > B : " << (A>B) << " : " << (B<A) << std::endl;
    std::cout << "A > C : " << (A>C) << " : " << (C<A) << std::endl;
    std::cout << "B > C : " << (B>C) << " : " << (C<B) << std::endl << std::endl;

    std::cout << "A < B : " << (A<B) << " : " << (B>A) << std::endl;
    std::cout << "A < C : " << (A<C) << " : " << (C>A) << std::endl;
    std::cout << "B < C : " << (B<C) << " : " << (C>B) << std::endl << std::endl;

    std::cout << "D == C : " << (D == C) << " : " << (C == D) << std::endl;
    std::cout << "A == E : " << (A == E) << " : " << (E == A) << std::endl << std::endl;
}

void BigIntTests::addition()
{
    const unsigned int BASE = 10;

    BigInt A("00001000"); // 8
    BigInt B("10110"); // - 10
    BigInt C("10011"); // - 13
    BigInt D("01110"); // 14
    BigInt E("01000"); // 8

    std::cout << "BASE " << BASE << std::endl << std::endl;

    std::cout << "A : " << A << " : " << A.toBase(BASE) << std::endl;
    std::cout << "B : " << B << " : " << B.toBase(BASE) << std::endl;
    std::cout << "C : " << C << " : " << C.toBase(BASE) << std::endl;
    std::cout << "D : " << D << " : " << D.toBase(BASE) << std::endl;
    std::cout << "E : " << E << " : " << E.toBase(BASE) << std::endl << std::endl;

    std::cout << "A + B : " << (A+B) << " : " << (B+A) << " : " << (B + A).toBase(BASE) << std::endl;
    std::cout << "A + C : " << (A+C) << " : " << (C+A) << " : " << (C + A).toBase(BASE) << std::endl;
    std::cout << "B + C : " << (B+C) << " : " << (C+B) << " : " << (C + B).toBase(BASE) << std::endl << std::endl;

    std::cout << "D + C : " << (D + C) << " : " << (C + D) << " : " << (C + D).toBase(BASE) << std::endl;
    std::cout << "A + E : " << (A + E) << " : " << (E + A) << " : " << (E + A).toBase(BASE) << std::endl << std::endl;
}

