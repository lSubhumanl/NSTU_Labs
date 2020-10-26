#include "SquareMatrixTests.h"
#include <exception>
#include <iostream>

using namespace std;

//���� ������������ � �����������
void constructorWithParametrsTest()
{
	//������� ������� ��� ���������
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ���� ��������
	SquareMatrix matrixObject(rank, matrix);

	//�������� �������, ������� ��������� ������ �������
	double** matrixResult = matrixObject.getMatrix();
	
	//� ���������� �������� ���� ���� ������
	for (int i = 0; i < rank; i++)
		for (int j = 0; j < rank; j++)
			//���� ��������������� �������� �� �����
			if (matrixResult[i][j] != matrix[i][j])
			{

				//�� ������� ������ �� ������
				for (int i = 0; i < rank; i++)
				{
					delete[] matrix[i];
					delete[] matrixResult[i];
				}
				delete[] matrix;
				delete[] matrixResult;

				//� ����������� ����������
				throw exception("Error in constructor with parametrs");
			}

	//������� ���������� ��� ������� ������
	for (int i = 0; i < rank; i++)
	{
		delete[] matrix[i];
		delete[] matrixResult[i];
	}
	delete[] matrix;
	delete[] matrixResult;

	//���� � ������� ����������� �������� �������� �����
	if (matrixObject.getRank() != rank)
		throw exception("Error in constructor with parametrs");

	cout << "Constructor with parametrs test completed!" << endl;
}

//���� ������������ �����������
void copyConstructorTest()
{
	//������� ������� ��� ���������
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ 1 ���� ��������, � ������ 2 - �������� 1
	SquareMatrix matrixObject1(rank, matrix), matrixObject2(matrixObject1);

	//�������� �������, ������� ��������� ������ �������
	double** matrixResult1 = matrixObject1.getMatrix();
	double** matrixResult2 = matrixObject2.getMatrix();

	//� ���������� �������� ���� ���� ������
	for (int i = 0; i < rank; i++)
		for (int j = 0; j < rank; j++)
			//���� ��������������� �������� �� �����
			if (matrixResult1[i][j] != matrixResult2[i][j])
			{

				//�� ������� ������ �� ������
				for (int i = 0; i < rank; i++)
				{
					delete[] matrix[i];
					delete[] matrixResult1[i];
					delete[] matrixResult2[i];
				}
				delete[] matrix;
				delete[] matrixResult1;
				delete[] matrixResult2;

				//� ����������� ����������
				throw exception("Error in copy constructor");
			}

	//������� ���������� ��� ������� ������
	for (int i = 0; i < rank; i++)
	{
		delete[] matrix[i];
		delete[] matrixResult1[i];
		delete[] matrixResult2[i];
	}
	delete[] matrix;
	delete[] matrixResult1;
	delete[] matrixResult2;

	//���� � ������� ����������� �������� �������� �����
	if (matrixObject1.getRank() != matrixObject2.getRank())
		throw exception("Error in copy constructor");

	cout << "Copy constructor test completed!" << endl;
}

//���� ������� ��� �������
void setMatrixTest()
{
	//������� ������� 1
	int rank1 = 5, value = 0;
	double** matrix1 = new double* [rank1];
	for (int i = 0; i < rank1; i++)
	{
		matrix1[i] = new double[rank1];
		for (int j = 0; j < rank1; j++)
			matrix1[i][j] = value++;
	}

	//������� ������� 2
	int rank2 = 3;
	double** matrix2 = new double* [rank2];
	for (int i = 0; i < rank2; i++)
	{
		matrix2[i] = new double[rank2];
		for (int j = 0; j < rank2; j++)
			matrix2[i][j] = value++;
	}

	//�������������� ������ �������� 1
	SquareMatrix matrixObject(rank1, matrix1);

	//������������� � ������ ������� 2
	matrixObject.setMatrix(rank2, matrix2);

	for (int i = 0; i < rank2; i++)
	{
		for(int j = 0;j<rank2;j++)
			//���� ������������� ������������ �� �������� � ����, ��� � ������� 2
			if (matrixObject.getValue(i, j) != matrix2[i][j])
			{
				//������� ���������� ��� ������� ������
				for (int i = 0; i < rank1; i++)
					delete[] matrix1[i];
				delete[] matrix1;

				for (int i = 0; i < rank2; i++)
					delete[] matrix2[i];
				delete[] matrix2;

				//�� ���������� ������
				throw exception("Error in setMatrix() method");
			}
	}

	for (int i = 0; i < rank1; i++)
		delete[] matrix1[i];
	delete[] matrix1;

	for (int i = 0; i < rank2; i++)
		delete[] matrix2[i];
	delete[] matrix2;

	//�����, ��������� �������� �����
	if(matrixObject.getRank() != rank2)
		throw exception("Error in setMatrix() method");

	cout << "setMatrix() test completed!" << endl;
}

//���� ������� ��� ��������
void setValueTest()
{
	//������� ������� ��� ���������
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	SquareMatrix matrixObject(rank, matrix);

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			//������������� ������ ������� ������� � -1
			matrixObject.setValue(i, j, -1);
			
			//� ���������, ����������� �� ��
			if (matrixObject.getValue(i,j) != -1)
				//���� ���, �� ����������� ����������
				throw exception("Error in setValue() method");
		}
	}

	cout << "setValue() test completed!" << endl;
}

//���� ������ ����������������
void transponseTest()
{
	//������� ������� ��� ���������
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	//������������� �������
	matrixObject.transponse();

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			//� ���������, ����������������� �� �������
			if (matrixObject.getValue(i, j) != matrix[j][i])
			{	
				for (int i = 0; i < rank; i++)
					delete[] matrix[i];
				delete[] matrix;

				//���� ���, �� ����������� ����������
				throw exception("Error in transponse() method");
			}
		}
	}

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	cout << "transponse() test completed!" << endl;
}

//���� ������ ���������� ������������
void determinantTest()
{
	//������� ������� ��� ���������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}
	matrix[0][0] = 2;

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	if (matrixObject.determinant() != -3)
		throw exception("Error in determinant() method");
	
	cout << "determinant() test completed!" << endl;
}

//���� ��������� ��������
void additionOperatorTest()
{
	//������� �������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	//������� ������ �� �������
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//���������� ������� � ����� � ��������� ���������
	SquareMatrix result = matrixObject + matrixObject;

	//�������, ��� � �������������� ������� ��� �������� ������ ���� � ��� ���� ������
	for(int i =0;i<result.getRank();i++)
		for(int j = 0;j<result.getRank();j++)
			if(result.getValue(i,j) != 2*matrixObject.getValue(i,j))
				throw exception("Error in + operator");

	cout << "+ operator test completed!" << endl;
}

//���� ��������� ���������
void subtractionOperatorTest()
{
	//������� �������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	//������� ������ �� �������
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//���������� ������� � ����� � ��������� ���������
	SquareMatrix result = matrixObject - matrixObject;

	//�������, ��� � �������������� ������� ��� �������� ������ ���� ����� ����
	for (int i = 0; i < result.getRank(); i++)
		for (int j = 0; j < result.getRank(); j++)
			if (result.getValue(i, j) != 0)
				throw exception("Error in - operator");

	cout << "- operator test completed!" << endl;
}

//���� ��������� []
void indexingOperatorTest()
{
	//������� �������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	//������� ������ �� �������
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//�������, ��� � �������������� ������� ��� �������� ������ ���� ����� ����
	for (int i = 0; i < matrixObject.getRank(); i++)
		for (int j = 0; j < matrixObject.getRank(); j++)
			if (matrixObject.getValue(i, j) != matrixObject[i][j])
				throw exception("Error in [] operator");

	cout << "[] operator test completed!" << endl;
}

//���� ��������� ()
void functionOperatorTest()
{
	//������� �������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}
	matrix[0][0] = 2;

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	if (matrixObject() != matrixObject.determinant())
		throw exception("Error in () operator");

	cout << "() operator test completed!" << endl;
}

//���� ��������� ������������
void assignmentOperatorTest()
{
	//������� �������
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//�������������� ������ ��������
	SquareMatrix matrixObject(rank, matrix);

	//������� ������ �� �������
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//���������� ������� � ����� � ��������� ���������
	SquareMatrix result = matrixObject;

	if(result.getRank() != matrixObject.getRank())
		throw exception("Error in = operator");

	//�������, ��� � �������������� ������� ��� �������� ������ ���� ����� ����
	for (int i = 0; i < result.getRank(); i++)
		for (int j = 0; j < result.getRank(); j++)
			if (result.getValue(i, j) != matrixObject.getValue(i,j))
				throw exception("Error in = operator");

	cout << "= operator test completed!" << endl;
}