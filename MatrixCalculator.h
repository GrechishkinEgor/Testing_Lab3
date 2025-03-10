#pragma once
#include <vector>



class MatrixCalculator
{
public:
	std::vector<std::vector<double>> Sum(std::vector<std::vector<double>> mat1,
		std::vector<std::vector<double>> mat2);
	std::vector<std::vector<double>> Transpose(std::vector<std::vector<double>> mat);
};

