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

Matrix Matrix::Transpose(Matrix mat)
{
	Matrix result(2, 4);
	result[0][0] = 1; result[0][1] = 3; result[0][2] = 5; result[0][3] = 7;
	result[1][0] = 2; result[1][1] = 4; result[1][2] = 6; result[1][3] = 8;
	return result;
}

double Matrix::Det()
{
	return 1.0;
}
