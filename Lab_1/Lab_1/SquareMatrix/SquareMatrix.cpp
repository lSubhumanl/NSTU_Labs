#include "SquareMatrix.h"
#include <exception>
#include <cmath>

//конструктор по умолчанию
SquareMatrix::SquareMatrix() : Matrix()
{}

//конструктор с параметрами
SquareMatrix::SquareMatrix(int rank, double** matrix) : Matrix(rank,rank,matrix)
{}

//конструктор копирования
SquareMatrix::SquareMatrix(const SquareMatrix& matrix) : Matrix(matrix)
{}

//оператор присваивания для квадратной матрицы
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& matrix)
{
	setMatrix(matrix._rows, matrix._cols, matrix._matrix);

	return *this;
}

//оператор присваивания для прямоугольной матрицы
SquareMatrix& SquareMatrix::operator=(const Matrix& matrix)
{
	Matrix& obj = const_cast<Matrix&>(matrix);
	setMatrix(obj.getRows(), obj.getCols(), obj.getMatrix());

	return *this;
}

void SquareMatrix::print()
{
	cout << "CLASS: SquareMatrix" << endl;
	cout << (*this) << endl;
}


//изменение матрицы
void SquareMatrix::setMatrix(int rows, int cols, double** matrix)
{
    if (rows != cols)
        throw exception("Bad size of matrix!");

    if (rows <= 0)
        throw exception("Bad count of rows!");

    if (cols <= 0)
        throw exception("Bad count of cols!");

    if (!matrix)
        throw exception("Nullptr!");

    for (int i = 0; i < rows; i++)
        if (!matrix[i])
            throw exception("Nullptr!");

    if (_matrix)
    {
        for (int i = 0; i < _rows; i++)
            delete[] _matrix[i];
        delete[] _matrix;
    }

    _rows = rows;
    _cols = cols;
    _matrix = copyMatrix(rows, cols, matrix);
}

//изменение матрицы
void SquareMatrix::setMatrix(int rank, double** matrix)
{
    setMatrix(rank, rank, matrix);
}


//вычисление определителя матрицы
double SquareMatrix::determinant()
{
    //определитель матрицы, состоящей из одного элемента равен этому элементу
    if (_rows * _cols == 1)
        return _matrix[0][0];

    double det = 0;
    //раскладываем определитель по первой строке
    for (int i = 0; i < _rows; i++)
        //определить равен сумме произведений элементов строки на их миноры и на (-1)^(i+j), в нашем случае j = 0
        det += _matrix[0][i] * minor(0, i, _rows, _matrix) * pow(-1, i);

    return det;
}

//получение минора матрицы
double SquareMatrix::minor(int row, int col, int rank, double** matrix)
{
	//минор - определить матрицы, составленной при вычеркивании строки row и столбца col из матрицы matrix

	//создаем такую же по размеру матрицу
	double** newMatrix = new double* [rank - 1];

	//перебираем все строки матрицы
	for (int i = 0, j = 0; i < rank; i++)
		//если встретилась строка под номером row, то пропускаем ее
		if (i == row)
			continue;
		else
		{
			//иначе - копируем содержимое строки за исключением столбца col
			newMatrix[j] = new double[rank - 1];
			for (int k = 0, l = 0; k < rank; k++)
				if (k == col)
					continue;
				else
					newMatrix[j][l++] = matrix[i][k];

			j++;
		}

	//т.к. мы вычеркнули одну строку и столбец из матрицы
	//то ее ранг уменьшился
	rank--;

	//если ранг матрицы равен 1, то она состоит из одного элемента (1х1)
	if (rank == 1)
	{
		//тогда определитель равен этому элементу
		double det = newMatrix[0][0];

		//очищаем память от созданной матрицы
		for (int i = 0; i < rank; i++)
			delete[] newMatrix[i];
		delete[] newMatrix;

		return det;
	}

	//иначе считаем определитель для данной матрицы как произведение элементов 
	//первой строки на их миноры и на (-1)^i
	double det = 0;
	for (int i = 0; i < rank; i++)
		det += newMatrix[0][i] * minor(0, i, rank, newMatrix) * pow(-1, i);

	//очищаем выделенную под матрицу память
	for (int i = 0; i < rank; i++)
		delete[] newMatrix[i];
	delete[] newMatrix;

	return det;
}

//оператор вычисления функции
double SquareMatrix::operator()()
{
	//вычисляем определитель матрицы
	return determinant();
}