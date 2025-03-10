#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrixCalculator
{
	TEST_CLASS(UnitTestMatrixCalculator)
	{
	public:
		void AreMatrixEqual(std::vector<std::vector<double>> expected, std::vector<std::vector<double>> actual)
		{
			Assert::AreEqual(expected.size(), actual.size());
			for (int i = 0; i < expected.size(); i++)
			{
				Assert::AreEqual(expected[i].size(), actual[i].size());
				for (int j = 0; j < expected[i].size(); j++)
					Assert::AreEqual(expected[i][j], actual[i][j]);
			}
		}

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
			AreMatrixEqual(expected, actual);
		}

		TEST_METHOD(Sum2)
		{
			MatrixCalculator calc;
			std::vector<std::vector<double>> matrix1 = { {1, 2}, {3, 4} };
			std::vector<std::vector<double>> matrix2 = { {5, 6} };

			bool exceptionFlag = false;
			try
			{
				calc.Sum(matrix1, matrix2);
			}
			catch (...)
			{
				exceptionFlag = true;
			}

			if (!exceptionFlag)
				Assert::Fail();
		}

		TEST_METHOD(Transpose)
		{
			MatrixCalculator calc;
			std::vector<std::vector<double>> matrix = { {1, 2, 3}, {4, 5, 6} };
			std::vector<std::vector<double>> actual = calc.Transpose(matrix);

			std::vector<std::vector<double>> expected = { {1, 4}, {2, 5}, {3, 6} };
			AreMatrixEqual(expected, actual);
		}

		TEST_METHOD(MultiplyByNum1)
		{
			MatrixCalculator calc;
			std::vector<std::vector<double>> matrix = { {1, 2, 3}, {4, 5, 6} };
			int multiplier = 10;
			std::vector<std::vector<double>> actual = calc.MultiplyByNum(matrix, multiplier);

			std::vector<std::vector<double>> expected = { {10, 20, 30}, {40, 50, 60} };
			AreMatrixEqual(expected, actual);
		}
	};
}
