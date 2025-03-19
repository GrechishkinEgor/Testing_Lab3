#include "pch.h"
#include "CppUnitTest.h"
#include "../Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixCalculatorTests
{
	TEST_CLASS(MatrixCalculatorTests)
	{
	public:
		TEST_METHOD(CanInstantiate)
		{
			Matrix mat;
		}

		TEST_METHOD(ChangeSize)
		{
			Matrix mat;
			const int ROWS_COUNT = 3;
			const int COLS_COUNT = 2;
			mat.Resize(ROWS_COUNT, COLS_COUNT);

			Assert::AreEqual(ROWS_COUNT, mat.GetRowsCount(), L"Не совпадает количество строк");
			Assert::AreEqual(COLS_COUNT, mat.GetColsCount(), L"Не совпадает количество столбцов");
		}

		TEST_METHOD(SetSizeInConstructor)
		{
			const int ROWS_COUNT = 5;
			const int COLS_COUNT = 3;
			Matrix mat(ROWS_COUNT, COLS_COUNT);

			Assert::AreEqual(ROWS_COUNT, mat.GetRowsCount(), L"Не совпадает количество строк");
			Assert::AreEqual(COLS_COUNT, mat.GetColsCount(), L"Не совпадает количество столбцов");
		}
	};
}
