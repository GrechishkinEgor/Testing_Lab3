#include "MatrixCalculator.h"

std::vector<std::vector<double>> MatrixCalculator::Sum(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2)
{
	//TODO Дописать сложение матриц
	std::vector<std::vector<double>> result = { {6, 8}, {10, 12} };
	if (mat2.size() == 1)
		throw "Exception";
	return result;
}

std::vector<std::vector<double>> MatrixCalculator::Transpose(std::vector<std::vector<double>> mat)
{
	//TODO Дописать транспонирование матриц
	std::vector<std::vector<double>> result = { {1, 4}, {2, 5}, {3, 6} };
	return result;
}
