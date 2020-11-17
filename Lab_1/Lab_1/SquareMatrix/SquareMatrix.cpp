#include "SquareMatrix.h"
#include <exception>
#include <cmath>

//инициализируем статическую переменную
int SquareMatrix::_count = 0;

//конструктор по умолчанию
SquareMatrix::SquareMatrix(int rank, double ** matrix)
{
	//ранг матрицы не должен быть отрицательным
	if (rank <= 0)
		throw exception("Bad rank");

	//матрица не должна быть представлена нулевым указателем
	if (!matrix)
		throw exception("Nullptr matrix");

	//сохраняем ранг и копируем содержимое матрицы
	_rank = rank;
	_matrix = copyMatrix(rank, matrix);

	//увеличиваем счетчик
	_count++;
}

//конструктор копирования
SquareMatrix::SquareMatrix(const SquareMatrix & matrix)
{
	//копируем ранг и содержимое матрицы
	_rank = matrix._rank;
	_matrix = copyMatrix(matrix._rank, matrix._matrix);

	//увеличиваем счетчик
	_count++;
}

//деструктор
SquareMatrix::~SquareMatrix()
{
	//перед уничтожением объекта очищаем память, выделенную под матрицу
	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//уменьшаем счетчик
	_count--;
}

//изменение матрицы
void SquareMatrix::setMatrix(int rank, double ** matrix)
{
	//ранг не должен быть отрицательным
	if (rank <= 0)
		throw exception("Bad rank");

	//матрица не должна быть представлена нулевым указателем
	if (!matrix)
		throw exception("Nullptr matrix");

	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//сохраняем ранг и содержимое матрицы
	_rank = rank;
	_matrix = copyMatrix(rank, matrix);
}

//изменение значения по индексам
void SquareMatrix::setValue(int row, int col, double value)
{
	//индекс строки не должен выходить за рамки ранга
	if ((row < 0) || (row >= _rank))
		throw exception("Bad row index");

	//индекс столбца не должен выходить за рамки ранга
	if ((col < 0) || (col >= _rank))
		throw exception("Bad col index");

	//изменяем элемент
	_matrix[row][col] = value;
}

//получение значения ранга
int SquareMatrix::getRank()
{
	return _rank;
}

//получение копии матрицы
double ** SquareMatrix::getMatrix()
{
	return copyMatrix(_rank, _matrix);
}

//получение значения по индексам
double SquareMatrix::getValue(int row, int col)
{
	//индекс строки не должен выходить за рамки ранга
	if ((row < 0) || (row >= _rank))
		throw exception("Bad row index");

	//индекс столбца не должен выходить за рамки ранга
	if ((col < 0) || (col >= _rank))
		throw exception("Bad col index");

	return _matrix[row][col];
}

//транспонирование матрицы
void SquareMatrix::transponse()
{
	int swap;
	for (int i = 0; i < _rank; i++)
		for (int j = i; j < _rank; j++)
		{
			//меняем местами элементы [i,j] и [j,i]
			swap = _matrix[i][j];
			_matrix[i][j] = _matrix[j][i];
			_matrix[j][i] = swap;
		}
}

//вычисление определителя
double SquareMatrix::determinant()
{
	//определитель матрицы, состоящей из одного элемента равен этому элементу
	if (_rank == 1)
		return _matrix[0][0];

	double det = 0;
	//раскладываем определитель по первой строке
	for (int i = 0; i < _rank; i++)
		//определить равен сумме произведений элементов строки на их миноры и на (-1)^(i+j), в нашем случае j = 0
		det += _matrix[0][i] * minor(0, i, _rank, _matrix)*pow(-1,i);

	return det;
}

//преобразование в строку
char* SquareMatrix::toString()
{
	//длина результирующей строки
	int str_len = 1024;
	//длина строки, содержащей число
	int number_len = 15;

	//создаем результирующую строку
	char* str = new char[str_len];
	//и индекс, который будет по ней двигаться
	int index = 0;

	//пробегаемся по всем числам матрицы
	for (int i = 0; i < _rank; i++)
	{
		for (int j = 0; j < _rank; j++)
		{
			//каждое число преобразуем в строку с помощью ффункции _itoa_s
			char* number = new char[number_len];
			_itoa_s(_matrix[i][j], number, number_len, 10);

			//переносим строковое представление числа в результирующую строку
			for (int k = 0; k < strlen(number); k++)
				str[index++] = number[k];
			//после каждого числа пишем табуляцию
			str[index++] = '\t';

			delete[] number;
		}

		//в конце каждой строки матрицы пишем символ переноса строки
		str[index++] = '\n';
	}

	str[index] = '\0';

	return str;
}

/*--------------ЛАБОРАТОРНАЯ РАБОТА 2--------------*/

//оператор сложения матриц
SquareMatrix operator+(const SquareMatrix& matrix1, const SquareMatrix& matrix2)
{
	//матрицы должны быть одинакового размера
	if (matrix1._rank != matrix2._rank)
		throw exception("Bad matrix rank");

	//результирующая мматрица инициализируется матрицей1
	SquareMatrix result(matrix1);

	//складываем соответствующие элементы матриц
	for (int i = 0; i < result._rank; i++)
		for (int j = 0; j < result._rank; j++)
			result._matrix[i][j] += matrix2._matrix[i][j];

	return result;
}

//оператор вычитания матриц
SquareMatrix operator-(const SquareMatrix& matrix1, const SquareMatrix& matrix2)
{
	//матрицы должны быть одинакового размера
	if (matrix1._rank != matrix2._rank)
		throw exception("Bad matrix rank");

	//результирующая мматрица инициализируется матрицей2
	SquareMatrix result(matrix1);

	//вычитаем соответствующие элементы матриц
	for (int i = 0; i < result._rank; i++)
		for (int j = 0; j < result._rank; j++)
			result._matrix[i][j] -= matrix2._matrix[i][j];

	return result;
}

//оператор индексирования
double* SquareMatrix::operator[](int index)
{
	//проверяем индекс на нарушение границ
	if ((index < 0) || (index >= _rank))
		throw exception("Bad index");

	//копируем строку матрицы
	double* row = new double[_rank];
	for (int i = 0; i < _rank; i++)
		row[i] = _matrix[index][i];

	return row;
}

//оператор вычисления функции
double SquareMatrix::operator()()
{
	//вычисляем определитель матрицы
	return determinant();
}

//оператор присваивания
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& matrix)
{
	//удаляем текущую матрицу
	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//копируем ранг и содержимое присваиваемой матрицы
	_rank = matrix._rank;
	_matrix = copyMatrix(matrix._rank, matrix._matrix);

	return *this;
}

//скопировать матрицу
double** SquareMatrix::copyMatrix(int rank, double** matrix)
{
	//создаем такую же по размеру матрицу
	double ** copy = new double*[rank];
	for (int i = 0; i < rank; i++)
	{
		copy[i] = new double[rank];
		
		//копируем ее содержимое
		for (int j = 0; j < rank; j++)
				copy[i][j] = matrix[i][j];
	}

	//возвращаем копию
	return copy;
}

//получение минора матрицы
double SquareMatrix::minor(int row, int col, int rank, double** matrix)
{
	//минор - определить матрицы, составленной при вычеркивании строки row и столбца col из матрицы matrix

	//создаем такую же по размеру матрицу
	double** newMatrix = new double *[rank - 1];

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

/*--------------ЛАБОРАТОРНАЯ РАБОТА 3--------------*/

//вывод в обычный поток
ostream& operator<<(ostream& stream, const SquareMatrix& matrix)
{
	//выводим все элементы матрицы
	for (int i = 0; i < matrix._rank; i++)
	{
		for (int j = 0; j < matrix._rank; j++)
			stream << matrix._matrix[i][j] << endl;
		stream << endl;
	}

	return stream;
}

//вывод в файловый поток
ofstream& operator<<(ofstream& stream, const SquareMatrix& matrix)
{
	if (!stream.is_open())
		throw exception("Stream is closed");

	//выводим ранг матрицы
	stream << matrix._rank << endl;
	//выводим все элементы матрицы
	for (int i = 0; i < matrix._rank; i++)
	{
		for (int j = 0; j < matrix._rank; j++)
			stream << matrix._matrix[i][j] << endl;
		stream << endl;
	}
	
	return stream;
}

//чтение с обычного потока
istream& operator>>(istream& stream, SquareMatrix& matrix)
{
	for (int i = 0; i < matrix._rank; i++)
		delete[] matrix._matrix[i];
	delete[] matrix._matrix;

	//считываем ранг матрицы
	stream >> matrix._rank;
	matrix._matrix = new double* [matrix._rank];
	//считываем все элементы матрицы
	for (int i = 0; i < matrix._rank; i++)
	{
		matrix._matrix[i] = new double [matrix._rank];
		for (int j = 0; j < matrix._rank; j++)
			stream >> matrix._matrix[i][j];
	}
	
	return stream;
}

//чтение с файлового потока
ifstream& operator>>(ifstream& stream, SquareMatrix& matrix)
{
	for (int i = 0; i < matrix._rank; i++)
		delete[] matrix._matrix[i];
	delete[] matrix._matrix;

	//считываем ранг матрицы
	stream >> matrix._rank;
	matrix._matrix = new double* [matrix._rank];
	//считываем все элементы матрицы
	for (int i = 0; i < matrix._rank; i++)
	{
		matrix._matrix[i] = new double [matrix._rank];
		for (int j = 0; j < matrix._rank; j++)
			stream >> matrix._matrix[i][j];
	}
	
	return stream;
}

//запись в бинарный файл
void SquareMatrix::write(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed");

	//записываем последовательно ранг матрицы и ее элементы
	file.write((char*)&_rank, sizeof(int));
	for (int i = 0; i < _rank; i++)
		for (int j = 0; j < _rank; j++)
			file.write((char*)&_matrix[i][j], sizeof(double));
}

//чтение из бинарного файла
void SquareMatrix::read(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed");

	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//считываем последовательно ранг матрицы и ее элементы
	file.read((char*)&_rank, sizeof(int));
	_matrix = new double* [_rank];
	for (int i = 0; i < _rank; i++)
	{
		_matrix[i] = new double[_rank];
		for (int j = 0; j < _rank; j++)
			file.read((char*)&_matrix[i][j], sizeof(double));
	}
}

