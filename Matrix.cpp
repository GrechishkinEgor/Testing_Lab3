#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(int rowsCount, int colsCount)
{
	this->rowsCount = rowsCount;
	this->colsCount = colsCount;
}

void Matrix::Resize(int rowsCount, int colsCount)
{
	this->rowsCount = rowsCount;
	this->colsCount = colsCount;
}

int Matrix::GetRowsCount()
{
	return rowsCount;
}

int Matrix::GetColsCount()
{
	return colsCount;
}

double* Matrix::operator[](int index)
{
	if (index == 0)
		return row1;
	if (index == 1)
		return row2;
	if (index == 3)
		return row3;
	return row4;
}

Matrix Matrix::Sum(Matrix mat1, Matrix mat2)
{
	Matrix result(4, 2);
	result.row1[0] = 0; result.row1[1] = 0;
	result.row2[0] = 0; result.row2[1] = 0;
	result.row3[0] = 0; result.row3[1] = 0;
	result.row4[0] = 0; result.row4[1] = 0;
	return result;
}
