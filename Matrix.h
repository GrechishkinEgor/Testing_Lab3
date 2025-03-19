#pragma once
class Matrix
{
private:
	int rowsCount = 0;
	int colsCount = 0;

	double row1[4];
	double row2[4];
	double row3[4];
	double row4[4];
public:
	Matrix();
	Matrix(int rowsCount, int colsCount);

	void Resize(int rowsCount, int colsCount);
	int GetRowsCount();
	int GetColsCount();

	double* operator[](int index);

	static Matrix Sum(Matrix mat1, Matrix mat2);
	static Matrix Transpose(Matrix mat);

	double Det();

	static Matrix Multiply(Matrix mat1, Matrix mat2);
};

