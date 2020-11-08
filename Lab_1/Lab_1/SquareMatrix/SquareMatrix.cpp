#include "SquareMatrix.h"
#include <exception>
#include <cmath>

//�������������� ����������� ����������
int SquareMatrix::_count = 0;

//����������� �� ���������
SquareMatrix::SquareMatrix(int rank, double ** matrix)
{
	//���� ������� �� ������ ���� �������������
	if (rank <= 0)
		throw exception("Bad rank");

	//������� �� ������ ���� ������������ ������� ����������
	if (!matrix)
		throw exception("Nullptr matrix");

	//��������� ���� � �������� ���������� �������
	_rank = rank;
	_matrix = copyMatrix(rank, matrix);

	//����������� �������
	_count++;
}

//����������� �����������
SquareMatrix::SquareMatrix(const SquareMatrix & matrix)
{
	//�������� ���� � ���������� �������
	_rank = matrix._rank;
	_matrix = copyMatrix(matrix._rank, matrix._matrix);

	//����������� �������
	_count++;
}

//����������
SquareMatrix::~SquareMatrix()
{
	//����� ������������ ������� ������� ������, ���������� ��� �������
	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//��������� �������
	_count--;
}

//��������� �������
void SquareMatrix::setMatrix(int rank, double ** matrix)
{
	//���� �� ������ ���� �������������
	if (rank <= 0)
		throw exception("Bad rank");

	//������� �� ������ ���� ������������ ������� ����������
	if (!matrix)
		throw exception("Nullptr matrix");

	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//��������� ���� � ���������� �������
	_rank = rank;
	_matrix = copyMatrix(rank, matrix);
}

//��������� �������� �� ��������
void SquareMatrix::setValue(int row, int col, double value)
{
	//������ ������ �� ������ �������� �� ����� �����
	if ((row < 0) || (row >= _rank))
		throw exception("Bad row index");

	//������ ������� �� ������ �������� �� ����� �����
	if ((col < 0) || (col >= _rank))
		throw exception("Bad col index");

	//�������� �������
	_matrix[row][col] = value;
}

//��������� �������� �����
int SquareMatrix::getRank()
{
	return _rank;
}

//��������� ����� �������
double ** SquareMatrix::getMatrix()
{
	return copyMatrix(_rank, _matrix);
}

//��������� �������� �� ��������
double SquareMatrix::getValue(int row, int col)
{
	//������ ������ �� ������ �������� �� ����� �����
	if ((row < 0) || (row >= _rank))
		throw exception("Bad row index");

	//������ ������� �� ������ �������� �� ����� �����
	if ((col < 0) || (col >= _rank))
		throw exception("Bad col index");

	return _matrix[row][col];
}

//���������������� �������
void SquareMatrix::transponse()
{
	int swap;
	for (int i = 0; i < _rank; i++)
		for (int j = i; j < _rank; j++)
		{
			//������ ������� �������� [i,j] � [j,i]
			swap = _matrix[i][j];
			_matrix[i][j] = _matrix[j][i];
			_matrix[j][i] = swap;
		}
}

//���������� ������������
double SquareMatrix::determinant()
{
	//������������ �������, ��������� �� ������ �������� ����� ����� ��������
	if (_rank == 1)
		return _matrix[0][0];

	double det = 0;
	//������������ ������������ �� ������ ������
	for (int i = 0; i < _rank; i++)
		//���������� ����� ����� ������������ ��������� ������ �� �� ������ � �� (-1)^(i+j), � ����� ������ j = 0
		det += _matrix[0][i] * minor(0, i, _rank, _matrix)*pow(-1,i);

	return det;
}

//�������������� � ������
char* SquareMatrix::toString()
{
	//����� �������������� ������
	int str_len = 1024;
	//����� ������, ���������� �����
	int number_len = 15;

	//������� �������������� ������
	char* str = new char[str_len];
	//� ������, ������� ����� �� ��� ���������
	int index = 0;

	//����������� �� ���� ������ �������
	for (int i = 0; i < _rank; i++)
	{
		for (int j = 0; j < _rank; j++)
		{
			//������ ����� ����������� � ������ � ������� �������� _itoa_s
			char* number = new char[number_len];
			_itoa_s(_matrix[i][j], number, number_len, 10);

			//��������� ��������� ������������� ����� � �������������� ������
			for (int k = 0; k < strlen(number); k++)
				str[index++] = number[k];
			//����� ������� ����� ����� ���������
			str[index++] = '\t';

			delete[] number;
		}

		//� ����� ������ ������ ������� ����� ������ �������� ������
		str[index++] = '\n';
	}

	str[index] = '\0';

	return str;
}

/*--------------������������ ������ 2--------------*/

//�������� �������� ������
SquareMatrix operator+(const SquareMatrix& matrix1, const SquareMatrix& matrix2)
{
	//������� ������ ���� ����������� �������
	if (matrix1._rank != matrix2._rank)
		throw exception("Bad matrix rank");

	//�������������� �������� ���������������� ��������1
	SquareMatrix result(matrix1);

	//���������� ��������������� �������� ������
	for (int i = 0; i < result._rank; i++)
		for (int j = 0; j < result._rank; j++)
			result._matrix[i][j] += matrix2._matrix[i][j];

	return result;
}

//�������� ��������� ������
SquareMatrix operator-(const SquareMatrix& matrix1, const SquareMatrix& matrix2)
{
	//������� ������ ���� ����������� �������
	if (matrix1._rank != matrix2._rank)
		throw exception("Bad matrix rank");

	//�������������� �������� ���������������� ��������2
	SquareMatrix result(matrix1);

	//�������� ��������������� �������� ������
	for (int i = 0; i < result._rank; i++)
		for (int j = 0; j < result._rank; j++)
			result._matrix[i][j] -= matrix2._matrix[i][j];

	return result;
}

//�������� ��������������
double* SquareMatrix::operator[](int index)
{
	//��������� ������ �� ��������� ������
	if ((index < 0) || (index >= _rank))
		throw exception("Bad index");

	//�������� ������ �������
	double* row = new double[_rank];
	for (int i = 0; i < _rank; i++)
		row[i] = _matrix[index][i];

	return row;
}

//�������� ���������� �������
double SquareMatrix::operator()()
{
	//��������� ������������ �������
	return determinant();
}

//�������� ������������
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& matrix)
{
	//������� ������� �������
	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//�������� ���� � ���������� ������������� �������
	_rank = matrix._rank;
	_matrix = copyMatrix(matrix._rank, matrix._matrix);

	return *this;
}

//����������� �������
double** SquareMatrix::copyMatrix(int rank, double** matrix)
{
	//������� ����� �� �� ������� �������
	double ** copy = new double*[rank];
	for (int i = 0; i < rank; i++)
	{
		copy[i] = new double[rank];
		
		//�������� �� ����������
		for (int j = 0; j < rank; j++)
				copy[i][j] = matrix[i][j];
	}

	//���������� �����
	return copy;
}

//��������� ������ �������
double SquareMatrix::minor(int row, int col, int rank, double** matrix)
{
	//����� - ���������� �������, ������������ ��� ������������ ������ row � ������� col �� ������� matrix

	//������� ����� �� �� ������� �������
	double** newMatrix = new double *[rank - 1];

	//���������� ��� ������ �������
	for (int i = 0, j = 0; i < rank; i++)
		//���� ����������� ������ ��� ������� row, �� ���������� ��
		if (i == row)
			continue;
		else
		{
			//����� - �������� ���������� ������ �� ����������� ������� col
			newMatrix[j] = new double[rank - 1];
			for (int k = 0, l = 0; k < rank; k++)
				if (k == col)
					continue;
				else
					newMatrix[j][l++] = matrix[i][k];

			j++;
		}
	
	//�.�. �� ���������� ���� ������ � ������� �� �������
	//�� �� ���� ����������
	rank--;

	//���� ���� ������� ����� 1, �� ��� ������� �� ������ �������� (1�1)
	if (rank == 1)
	{
		//����� ������������ ����� ����� ��������
		double det = newMatrix[0][0];

		//������� ������ �� ��������� �������
		for (int i = 0; i < rank; i++)
			delete[] newMatrix[i];
		delete[] newMatrix;

		return det;
	}

	//����� ������� ������������ ��� ������ ������� ��� ������������ ��������� 
	//������ ������ �� �� ������ � �� (-1)^i
	double det = 0;
	for (int i = 0; i < rank; i++)
		det += newMatrix[0][i] * minor(0, i, rank, newMatrix) * pow(-1, i);

	//������� ���������� ��� ������� ������
	for (int i = 0; i < rank; i++)
		delete[] newMatrix[i];
	delete[] newMatrix;

	return det;
}

/*--------------������������ ������ 3--------------*/

//����� � ������� �����
ostream& operator<<(ostream& stream, const SquareMatrix& matrix)
{
	//������� ��� �������� �������
	for (int i = 0; i < matrix._rank; i++)
	{
		for (int j = 0; j < matrix._rank; j++)
			stream << matrix._matrix[i][j] << endl;
		stream << endl;
	}

	return stream;
}

//����� � �������� �����
ofstream& operator<<(ofstream& stream, const SquareMatrix& matrix)
{
	if (!stream.is_open())
		throw exception("Stream is closed");

	//������� ���� �������
	stream << matrix._rank << endl;
	//������� ��� �������� �������
	for (int i = 0; i < matrix._rank; i++)
	{
		for (int j = 0; j < matrix._rank; j++)
			stream << matrix._matrix[i][j] << endl;
		stream << endl;
	}
	
	return stream;
}

//������ � �������� ������
istream& operator>>(istream& stream, SquareMatrix& matrix)
{
	for (int i = 0; i < matrix._rank; i++)
		delete[] matrix._matrix[i];
	delete[] matrix._matrix;

	//��������� ���� �������
	stream >> matrix._rank;
	matrix._matrix = new double* [matrix._rank];
	//��������� ��� �������� �������
	for (int i = 0; i < matrix._rank; i++)
	{
		matrix._matrix[i] = new double [matrix._rank];
		for (int j = 0; j < matrix._rank; j++)
			stream >> matrix._matrix[i][j];
	}
	
	return stream;
}

//������ � ��������� ������
ifstream& operator>>(ifstream& stream, SquareMatrix& matrix)
{
	for (int i = 0; i < matrix._rank; i++)
		delete[] matrix._matrix[i];
	delete[] matrix._matrix;

	//��������� ���� �������
	stream >> matrix._rank;
	matrix._matrix = new double* [matrix._rank];
	//��������� ��� �������� �������
	for (int i = 0; i < matrix._rank; i++)
	{
		matrix._matrix[i] = new double [matrix._rank];
		for (int j = 0; j < matrix._rank; j++)
			stream >> matrix._matrix[i][j];
	}
	
	return stream;
}

//������ � �������� ����
void SquareMatrix::write(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed");

	//���������� ��������������� ���� ������� � �� ��������
	file.write((char*)&_rank, sizeof(int));
	for (int i = 0; i < _rank; i++)
		for (int j = 0; j < _rank; j++)
			file.write((char*)&_matrix[i][j], sizeof(double));
}

//������ �� ��������� �����
void SquareMatrix::read(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed");

	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;

	//��������� ��������������� ���� ������� � �� ��������
	file.read((char*)&_rank, sizeof(int));
	_matrix = new double* [_rank];
	for (int i = 0; i < _rank; i++)
	{
		_matrix[i] = new double[_rank];
		for (int j = 0; j < _rank; j++)
			file.read((char*)&_matrix[i][j], sizeof(double));
	}
}

