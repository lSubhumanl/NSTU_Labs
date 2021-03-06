#pragma once

#include "../SquareMatrix/SquareMatrix.h"

class SquareMatrixTests
{
private:

	//����� ��� ������� ���������� ������
	void clearMemory(int rows, int cols, double** matrix);

public:

	//������� �� �����������, �.�. � ��� ��������� ����������� ���

	//���� ������������ � �����������
	void constructorWithParametrs();

	//���� ������������ �����������
	void copyConstructor();

	//���� ������ ��������� �������
	void setMatrix();

	//���� ������ ���������������� �������
	void transponse();

	//���� ��������� ������������
	void assignmentOperator();

	//���� ��������� ��������
	void additionOperator();

	//���� ��������� ���������
	void subtractionOperator();

	//���� ��������� ��������������
	void indexingOperator();

	//���� �����-������ � �������� ����
	void binaryInputOutput();

	//���� �����-������ � ��������� ����
	void fileInputOutput();

	//���� ���������� ������������
	void determinant();

};