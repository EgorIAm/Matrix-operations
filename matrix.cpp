#include <vector>
#include <string>
#include "matrix.h"

Matrix::Matrix(std::vector<std::vector<float>> data) {
	values = data;
	if (!isValid()) values.clear();
}

float	Matrix::getDet() {
	if (!isSquare()) return 0;
	Matrix temp(values);
	temp.triangulate();
	float det = 1;
	for (int i = 0; i < temp.values.size(); i++) {
		det *= temp.values[i][i];
	}
	return det;
}

int		Matrix::getRank() {
	if (!isValid()) return 0;
	Matrix temp(values);
	temp.triangulate();
	int rank = 0;
	for (int i = 0; i < temp.values.size(); i++) {
		for (int j = temp.values[0].size() - 1; j >= 0; j--) {
			if (temp.values[i][j] != 0) {
				rank++;
				break;
			}
		}
	}

	return rank;
}


void	Matrix::show(std::string tab) {
	for (int i = 0; i < values.size(); i++) {
		for (int j = 0; j < values[0].size(); j++) {
			std::cout << std::setw(5) << values[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << tab;
}

Matrix& Matrix::transpose() {
	if (isValid()) {
		Matrix transposed;
		transposed.values.resize(values[0].size());
		for (int i = 0; i < transposed.values.size(); i++)
			transposed.values[i].resize(values.size());

		for (int i = 0; i < transposed.values.size(); i++)
			for (int j = 0; j < transposed.values[0].size(); j++)
				transposed.values[i][j] = values[j][i];

		values = transposed.values;
	}
	return *this;
}


Matrix& Matrix::triangulate() {
	if (isValid()) {
		for (int y = 0; y < values.size() - 1; y++) {
			for (int x = y; x < values[0].size(); x++) {
				//show("\n");
				if (values[y][x] == 0) {
					//show("\n");
					// попытаться найти ненулевую строку в m-ном столбце
					int nonNullRow = y;
					for (int j = y; j < values.size(); j++)
						if (values[j][x] != 0) {
							nonNullRow = j;
							break;
						}
					//если нашлась, поменять первую строку матрицы ixi и ненулевую строки местами
					if (nonNullRow != y) { 
						show("\n");
						std::swap(values[y], values[nonNullRow]); }
				}
				// из каждой строки ниже i-ной вычитаем последнюю строку матрицы ixi умноженную на koef
				if (values[y][x] != 0) {
					//show("\n");
					float k;
					for (int subY = y + 1; subY < values.size(); subY++) {
						k = values[subY][x] / values[y][x];
						show("\n");
						for (int subX = 0; subX < values[0].size(); subX++)
							values[subY][subX] -= values[y][subX] * k;
					}
					y++;
				}
			}
		}
	}
	return *this;
}
bool	Matrix::isValid() {
	if (values.size() == 0) return 0;
	for (int i = 0; i < values.size(); i++) {
		if (values[i].size() != values[0].size() or values[i].size() == 0) {
			return 0;
		}
	}

	return 1;
}
bool	Matrix::isSquare() {
	return isValid() and values[0].size() == values.size();
}

bool	areEqual(Matrix m1, Matrix m2) {
	return m1.isValid() and m2.isValid() and m1.values == m2.values;
}
Matrix	add(Matrix M1, Matrix M2) {
	if (M1.isValid() and M2.isValid() and M1.values.size() == M2.values.size() and M1.values[0].size() == M2.values[0].size()) {
		for (int i = 0; i < M1.values.size(); i++) {
			for (int j = 0; j < M1.values[0].size(); j++) {
				M1.values[i][j] += M2.values[i][j];
			}
		}
	}
	else {
		M1.values.clear();
	}
	return M1;
}
Matrix	substract(Matrix M1, Matrix M2) {
	if (M1.isValid() and M2.isValid() and M1.values.size() == M2.values.size() and M1.values[0].size() == M2.values[0].size()) {
		for (int i = 0; i < M1.values.size(); i++) {
			for (int j = 0; j < M1.values[0].size(); j++) {
				M1.values[i][j] -= M2.values[i][j];
			}
		}
	}
	else {
		M1.values.clear();
	}
	return M1;
}
Matrix	multiply(Matrix matrix, float multiplier) {
	if (matrix.isValid() and multiplier != 0) {
		for (int y = 0; y < matrix.values.size(); y++) {
			for (int x = 0; x < matrix.values[0].size(); x++) {
				matrix.values[y][x] *= multiplier;
			}
		}
	}
	else {
		matrix.values.clear();
	}

	return matrix;
}
Matrix	multiply(Matrix m1, Matrix m2) {
	Matrix produced;
	if (m1.isValid() and m2.isValid()) {
		if (m1.values[0].size() == m2.values.size()) {
			produced.values.resize(m1.values.size());
			for (int i = 0; i < m1.values.size(); i++) {
				produced.values[i].resize(m2.values[0].size(), 0);
			}

			for (int i = 0; i < produced.values.size(); i++) {
				for (int j = 0; j < produced.values[0].size(); j++) {
					for (int k = 0; k < m1.values[0].size(); k++) {
						produced.values[i][j] += m1.values[i][k] * m2.values[k][j];
					}
				}
			}
		}
	}
	return produced;
}

