#pragma once

#include <iostream>
#include <fstream>

using namespace std;

//����� �������
class Matrix
{
public:

	/*
	����������� �� ���������
	������� ������� �������  1�1 �� ��������� 0
	*/
	Matrix();

	/*
	����������� � �����������
	args:
		rows - ���������� ����� � �������
		cols - ���������� �������� � �������
		matrix - �������
	����������� ����������, ���� rows ��� cols ������ 0, � � matrix �������� ������� ���������
	*/
	Matrix(int rows, int cols, double** matrix);

	/*
	����������� �����������
	args:
		matrix - ���������� �������
	*/
	Matrix(const Matrix& matrix);

	//����������
	virtual ~Matrix();


	/*
	��������� ���������� �����
	return - ���������� �����
	*/
	int getRows();

	/*
	��������� ���������� ��������
	return - ���������� ��������
	*/
	int getCols();

	/*
	��������� ����� �������
	return - ����� �������
	*/
	double** getMatrix();

	/*
	��������� �������� �� ���������
	args:
		rowIndex - ����� ������
		colIndex - ����� �������
	return - ������ �� ��������
	����������� ����������, ���� ������� ������� �� ������� �������
	*/
	double& getValue(int rowIndex, int colIndex);

	/*
	��������� �������
	�������� ������� ������� �� ������
	args:
		rows - ���������� ����� � �������
		cols - ���������� �������� � �������
		matrix - �������
	����������� ����������, ���� rows ��� cols ������ 0, � � matrix �������� ������� ���������
	*/
	virtual void setMatrix(int rows, int cols, double** matrix);


	/*
	��������� ���������� ������������� �������
	return - ��������� ������������� �������
	*/
	char* toString();

	/*
	���������������� �������
	*/
	virtual void transponse();


	/*
	�������� �������� �������
	args:
		matrix - ������ ���������
	return - ��������� �������� ������
	����������� ����������, ���� ������� ������ �� ����� ���� �����
	*/
	Matrix operator+(const Matrix& matrix);

	/*
	�������� �������� �������
	args:
		matrix - ���������� �������
	return - ��������� ��������� ������
	����������� ����������, ���� ������� ������ �� ����� ���� �����
	*/
	Matrix operator-(const Matrix& matrix);

	/*
	�������� ��������������
	args:
		rowIndex - ����� ������
	return - ����� ������ ��� ������� rowIndex
	����������� ����������, ���� rowIndex ������� �� ������� �������
	*/
	double * operator[](int rowIndex);

	/*
	�������� ������������ ������
	args:
		matrix - ������������� �������
	return - ������ �� ������� ������
	*/
	Matrix& operator=(const Matrix& matrix);



	/*
	�������� ������ � ����� ������
	�������� � � ��������� ��������, � � ��������
	args:
		stream - ����� ������
		matrix - ��������� �������
	return - ������ �� ����� ������
	*/
	friend ostream& operator<<(ostream& stream, const Matrix& matrix);

	/*
	�������� ����� �� ������ �����
	�������� � � ��������� ��������, � � ��������
	args:
		stream - ����� �����
		matrix - �������� �������
	return - ������ �� ����� �����
	*/
	friend istream& operator>>(istream& stream, Matrix& matrix);

	/*
	������ � �������� ����
	args:
		file - �������� ���� ��� ������
	����������� ����������, ���� file �� ������
	*/
	void write(fstream& file);

	/*
	������ �� ��������� �����
	args:
		file - �������� ���� ��� ������
	����������� ����������, ���� file �� ������
	*/
	void read(fstream& file);

protected:

	/*
	�������
	*/
	double** _matrix;

	/*
	���������� ����� �������
	*/
	int _rows;

	/*
	���������� �������� �������
	*/
	int _cols;


	/*
	����������� �������
	���������� ����� ������� matrix
	args:
		rows - ���������� ����� � �������
		cols - ���������� �������� � �������
		matrix - ���������� �������
	return - ����� ������� matrix
	*/
	double** copyMatrix(int rows, int cols, double** matrix);
	
};

