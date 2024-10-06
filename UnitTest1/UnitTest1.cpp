#include "pch.h"
#include "CppUnitTest.h"
#include "../LR5.4/LR5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double result, expected;
			result = P1(10, 20, 10);
			expected = ((10 * 1.0 / 10) + (10 * 1.0 / 20)) * P1(10, 20, 10 + 1);	//expected = ((K * 1.0 / i) + (i * 1.0 / N)) * P1(K, N, i + 1);
			Assert::AreEqual(expected, result, 0.0001);
		}
		TEST_METHOD(TestMethod2)
		{
			double result, expected;
			result = P2(10, 20, 20);
			expected = ((10 * 1.0 / 20) + (20 * 1.0 / 20)) * P2(10, 20, 20 + 1);
		}
		TEST_METHOD(TestMethod3)
		{
			double result, expected;
			result = P3(10, 20, 10, 1);
			expected = ((10 * 1.0 / 10) + (10 * 1.0 / 20)) * P3(10, 20, 10 + 1, 1);
		}
		TEST_METHOD(TestMethod4)
		{
			double result, expected;
			result = P4(10, 20, 20, 1);
			expected = ((10 * 1.0 / 20) + (20 * 1.0 / 20)) * P4(10, 20, 20 + 1, 1);
		}
	};
}
