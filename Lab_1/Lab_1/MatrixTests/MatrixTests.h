#pragma once

#include "../Matrix/Matrix.h"

class MatrixTests
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

	//���� ��������� ��������
	void additionOperator();

	//���� ��������� ���������
	void subtractionOperator();

	//���� ��������� ��������������
	void indexingOperator();

	//���� ��������� ������������
	void assignmentOperator();

	//���� �����-������ � �������� ����
	void binaryInputOutput();

	//���� �����-������ � ��������� ����
	void fileInputOutput();

};