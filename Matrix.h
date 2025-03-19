#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int rowsCount, int colsCount);
	void Resize(int rowsCount, int colsCount);
	int GetRowsCount();
	int GetColsCount();
};

