#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2 rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMaxInColumn)
        {
            int k = 3, n = 4;
            int** a = new int* [k] {
                new int[n] {10, 20, 15, 25},
                    new int[n] {30, 5, 35, 40},
                    new int[n] {50, 45, 55, 60}
                };

            Assert::AreEqual(50, MaxInColumn(a, k, 0));
            Assert::AreEqual(45, MaxInColumn(a, k, 1));

            for (int i = 0; i < k; i++) delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestSumMaxOddColumns)
        {
            int k = 3, n = 4;
            int** a = new int* [k] {
                new int[n] {10, 20, 15, 25},
                    new int[n] {30, 5, 35, 40},
                    new int[n] {50, 45, 55, 60}
                };

            Assert::AreEqual(105, SumMaxOddColumns(a, k, n));

            for (int i = 0; i < k; i++) delete[] a[i];
            delete[] a;
        }
    };
}
