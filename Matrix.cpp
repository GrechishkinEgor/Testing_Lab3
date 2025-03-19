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
