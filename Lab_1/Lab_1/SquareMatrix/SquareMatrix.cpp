#include "SquareMatrix.h"
#include <exception>
#include <cmath>
#include <iostream>

using namespace std;

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
}

//����������� �����������
SquareMatrix::SquareMatrix(const SquareMatrix & matrix)
{
	//�������� ���� � ���������� �������
	_rank = matrix._rank;
	_matrix = copyMatrix(matrix._rank, matrix._matrix);
}

//����������
SquareMatrix::~SquareMatrix()
{
	//����� ������������ ������� ������� ������, ���������� ��� �������
	for (int i = 0; i < _rank; i++)
		delete[] _matrix[i];
	delete[] _matrix;
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

//����� �� �����
void SquareMatrix::show()
{
	for (int i = 0; i < _rank; i++)
	{
		for (int j = 0; j < _rank; j++)
			cout << _matrix[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
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
