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

		TEST_METHOD(WriteAndReadElements)
		{
			const int ROWS_COUNT = 4;
			const int COLS_COUNT = 2;
			Matrix mat(ROWS_COUNT, COLS_COUNT);

			double counter = 1;
			for (int i = 0; i < ROWS_COUNT; i++)
				for (int j = 0; j < COLS_COUNT; j++)
				{
					mat[i][j] = counter;
					counter++;
				}

			counter = 1;
			for (int i = 0; i < mat.GetRowsCount(); i++)
				for (int j = 0; j < mat.GetColsCount(); j++)
				{
					Assert::AreEqual(counter, mat[i][j], L"Не совпадают элементы матрицы");
					counter++;
				}
		}

		TEST_METHOD(Sum)
		{
			const int ROWS_COUNT = 4;
			const int COLS_COUNT = 2;
			Matrix mat1(ROWS_COUNT, COLS_COUNT);
			Matrix mat2(ROWS_COUNT, COLS_COUNT);

			double counter = 1;
			for (int i = 0; i < ROWS_COUNT; i++)
				for (int j = 0; j < COLS_COUNT; j++)
				{
					mat1[i][j] = counter;
					mat2[i][j] = -counter;
					counter++;
				}

			Matrix actual = Matrix::Sum(mat1, mat2);

			Assert::AreEqual(ROWS_COUNT, actual.GetRowsCount(), L"Не совпадает количество строк");
			Assert::AreEqual(COLS_COUNT, actual.GetColsCount(), L"Не совпадает количество столбцов");
			for (int i = 0; i < ROWS_COUNT; i++)
				for (int j = 0; j < COLS_COUNT; j++)
					Assert::AreEqual(0.0, actual[i][j], L"Не совпадают элементы матрицы");
		}
	};
}
