#include<iostream>

class Matrix
{
private:
	const static int INIT_SIZE{ 5 };

	int size{ 0 };
	int** arr{ nullptr };

public:
	Matrix() :
		size{ Matrix::INIT_SIZE },
		arr{ new int* [Matrix::INIT_SIZE] }
	{
		for (int i{}; i < Matrix::INIT_SIZE; ++i)
			arr[i] = new int[Matrix::INIT_SIZE]{};
	}

	Matrix(const Matrix& obj) :
		size{ obj.size },
		arr{ new int* [obj.size] }
	{
		for (int i{}; i < this->size; ++i) {
			arr[i] = new int[this->size];

			for (int j{}; j < this->size; ++j) {
				arr[i][j] = obj.arr[i][j];
			}
		}
	}

	int getMatrixSize(const Matrix& a) const {
		int sizeMatrix{ 0 };
		for (int i{}; i < a.getSize(); ++i) {
			for (int j{}; j < a.getSize(); ++j) {
				sizeMatrix += a.getEllement(i, j);
			}
		}
		return sizeMatrix;
	}

	int getSize() const { return size; }

	int getEllement(int i, int j) const { return arr[i][j]; }

	void set(int i, int j, int val) { arr[i][j] = val; }

	void show() {
		for (int i{}; i < Matrix::INIT_SIZE; ++i) {
			for (int j{}; j < Matrix::INIT_SIZE; ++j) {
				std::cout << arr[i][j] << ' ';
			}
			std::cout << '\n';
		}

		std::cout << "\n\n";
	}

	operator int() const {
		int result{};
		for (int i{}; i < Matrix::INIT_SIZE; ++i) {
			for (int j{}; j < Matrix::INIT_SIZE; ++j) {
				result += arr[i][j];
			}
		}

		return result;
	}

	Matrix& operator += (Matrix a) {
		for (int i{}; i < Matrix::INIT_SIZE; ++i) {
			for (int j{}; j < Matrix::INIT_SIZE; ++j) {
				arr[i][j] += a.arr[i][j];
			}
		}

		return *this;
	}

	Matrix& operator -= (Matrix a) {
		for (int i{}; i < Matrix::INIT_SIZE; ++i) {
			for (int j{}; j < Matrix::INIT_SIZE; ++j) {
				arr[i][j] -= a.arr[i][j];
			}
		}

		return *this;
	}

	Matrix& operator = (const Matrix& a) {
		for (int i{}; i < Matrix::INIT_SIZE; ++i) {
			for (int j{}; j < Matrix::INIT_SIZE; ++j) {
				arr[i][j] = a.arr[i][j];
			}
		}

		return *this;

	}

	Matrix& operator ++ () {
		if (arr != nullptr) {
			for (int i{}; i < this->size; ++i) {
				for (int j{}; j < this->size; ++j) {
					++(this->arr[i][j]);
				}
			}
		}

		return *this;
	}

	Matrix operator++(int) {
		Matrix tmpNew{ *this };
		++(*this);
		return tmpNew;
	}

	Matrix& operator -- () {
		if (arr != nullptr) {
			for (int i{}; i < this->size; ++i) {
				for (int j{}; j < this->size; ++j) {
					--(this->arr[i][j]);
				}
			}
		}

		return *this;
	}

	Matrix operator--(int) {
		Matrix tmpNew{ *this };
		--(*this);
		return tmpNew;
	}

	void operator[](const Matrix& a) {
		int* oneArr = new int[a.getSize() * a.getSize()];
		for (int i{}; i < a.getSize(); ++i) {
			for (int j{}; j < a.getSize(); ++j) {
				oneArr[i] = a.getEllement(i, j);
			}
		}
		for (int i{}; i < a.getSize() + a.getSize(); ++i)
			std::cout << *oneArr << ' ';
		delete[] oneArr;
	}

	int operator() (const Matrix& a, int i, int j) {
		return a.getEllement(i, j);
	}

	~Matrix() {
		if (arr != nullptr) {
			for (int i{}; i < Matrix::INIT_SIZE; ++i) {
				if (arr[i] != nullptr)
					delete[] arr[i];
			}

			delete[] arr;
		}
	}
};

bool operator >= (const Matrix& a, const Matrix& b) {
	return a.getMatrixSize(a) >= b.getMatrixSize(b);
}

bool operator <= (const Matrix& a, const Matrix& b) {
	return a.getMatrixSize(a) <= b.getMatrixSize(b);
}

bool operator > (const Matrix& a, const Matrix& b) {
	return a.getMatrixSize(a) > b.getMatrixSize(b);
}

bool operator < (const Matrix& a, const Matrix& b) {
	return a.getMatrixSize(a) < b.getMatrixSize(b);
}

bool operator==(const Matrix& a, const Matrix& b) {
	for (int i{}; i < a.getSize(); ++i) {
		for (int j{}; j < a.getSize(); ++j) {
			if (a.getEllement(i, j) != b.getEllement(i, j))
				return false;
			else return true;
		}
	}
}

bool operator!=(const Matrix& a, const Matrix& b) {
	for (int i{}; i < a.getSize(); ++i) {
		for (int j{}; j < a.getSize(); ++j) {
			if (a.getEllement(i, j) != b.getEllement(i, j))
				return true;
			else return false;
		}
	}
}

Matrix operator+(const Matrix& a, const Matrix& b) {
	Matrix c;
	for (int i{}; i < a.getSize(); ++i) {
		for (int j{}; j < a.getSize(); ++j) {
			c.set(i, j, (a.getEllement(i, j) + b.getEllement(i, j)));
		}
	}
	return c;
}

Matrix operator-(const Matrix& a, const Matrix& b) {
	Matrix c;
	for (int i{}; i < a.getSize(); ++i) {
		for (int j{}; j < a.getSize(); ++j) {
			c.set(i, j, (a.getEllement(i, j) - b.getEllement(i, j)));
		}
	}
	return c;
}

int main() {
	Matrix a;
	Matrix b;
	a.set(3, 4, 2);
	b.set(3, 4, 1);
	/*if (a < b) {
		std::cout << "ok";
	}*/
	//a.show();
	//a++;
	//a.show();
	//(a - b).show();
	//a[a];

	/*a = b;
	b.show();*/
	//a = b;
	//a.show();

	int num = a;
	std::cout << num;

	return 0;
}