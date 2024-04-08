#pragma once
#include <vector>
#include <iomanip>
#include <iostream>

class Matrix {
public:
	std::vector<std::vector<float>> values;
	Matrix(std::vector<std::vector<float>> data = {});
	float	getDet();
	int		getRank();
	void	show(std::string tab = "");
	Matrix& transpose();
	Matrix& triangulate();
	bool	isValid();
	bool	isSquare();
};

bool	areEqual(Matrix m1, Matrix m2);
Matrix	add(Matrix m1, Matrix m2);
Matrix	substract(Matrix m1, Matrix m2);
Matrix	multiply(Matrix matrix, float multiplier);
Matrix	multiply(Matrix m1, Matrix m2);