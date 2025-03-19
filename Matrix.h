#pragma once
class Matrix
{
private:
	int rowsCount = 0;
	int colsCount = 0;

	double row1[2];
	double row2[2];
	double row3[2];
	double row4[2];
public:
	Matrix();
	Matrix(int rowsCount, int colsCount);

	void Resize(int rowsCount, int colsCount);
	int GetRowsCount();
	int GetColsCount();

	double* operator[](int index);

	static Matrix Sum(Matrix mat1, Matrix mat2);
};

