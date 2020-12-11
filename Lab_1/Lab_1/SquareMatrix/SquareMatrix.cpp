#include "SquareMatrix.h"
#include <exception>
#include <cmath>

//����������� �� ���������
SquareMatrix::SquareMatrix() : Matrix()
{}

//����������� � �����������
SquareMatrix::SquareMatrix(int rank, double** matrix) : Matrix(rank,rank,matrix)
{}

//����������� �����������
SquareMatrix::SquareMatrix(const SquareMatrix& matrix) : Matrix(matrix)
{}

//�������� ������������ ��� ���������� �������
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& matrix)
{
	setMatrix(matrix._rows, matrix._cols, matrix._matrix);

	return *this;
}

//�������� ������������ ��� ������������� �������
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


//��������� �������
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

//��������� �������
void SquareMatrix::setMatrix(int rank, double** matrix)
{
    setMatrix(rank, rank, matrix);
}


//���������� ������������ �������
double SquareMatrix::determinant()
{
    //������������ �������, ��������� �� ������ �������� ����� ����� ��������
    if (_rows * _cols == 1)
        return _matrix[0][0];

    double det = 0;
    //������������ ������������ �� ������ ������
    for (int i = 0; i < _rows; i++)
        //���������� ����� ����� ������������ ��������� ������ �� �� ������ � �� (-1)^(i+j), � ����� ������ j = 0
        det += _matrix[0][i] * minor(0, i, _rows, _matrix) * pow(-1, i);

    return det;
}

//��������� ������ �������
double SquareMatrix::minor(int row, int col, int rank, double** matrix)
{
	//����� - ���������� �������, ������������ ��� ������������ ������ row � ������� col �� ������� matrix

	//������� ����� �� �� ������� �������
	double** newMatrix = new double* [rank - 1];

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

//�������� ���������� �������
double SquareMatrix::operator()()
{
	//��������� ������������ �������
	return determinant();
}