#pragma once
class Matrix
{
private:
	int rowsCount = 0;
	int colsCount = 0;
public:
	Matrix();
	Matrix(int rowsCount, int colsCount);
	void Resize(int rowsCount, int colsCount);
	int GetRowsCount();
	int GetColsCount();
};

