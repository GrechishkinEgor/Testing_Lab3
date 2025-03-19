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
