#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrixCalculator
{
	TEST_CLASS(UnitTestMatrixCalculator)
	{
	public:
		
		TEST_METHOD(ClassExisting)
		{
			MatrixCalculator* calc = new MatrixCalculator();
			Assert::IsNotNull(calc);
			delete calc;
		}

		TEST_METHOD(Sum1)
		{
			MatrixCalculator calc;
			std::vector<std::vector<double>> matrix1 = { {1, 2}, {3, 4} };
			std::vector<std::vector<double>> matrix2 = { {5, 6}, {7, 8} };
			std::vector<std::vector<double>> actual = calc.Sum(matrix1, matrix2);
			
			std::vector<std::vector<double>> expected = { {6, 8}, {10, 12} };
			Assert::AreEqual(expected.size(), actual.size());
			for (int i = 0; i < expected.size(); i++)
			{
				Assert::AreEqual(expected[i].size(), actual[i].size());
				for (int j = 0; j < expected[i].size(); j++)
					Assert::AreEqual(expected[i][j], actual[i][j]);
			}	
		}
	};
}
