
#pragma once

//����� ���������� �������
class SquareMatrix
{
public:
	
	/*
		����������� � �����������
		������� ������� ����� rank � �������������� �� matrix
		args:
			rank - ���� �������
			matrix - ��������� ������ �������������
		����������:
			- ���� rank <= 0
			- ���� matrix == nullptr	
	*/
	SquareMatrix(int rank, double ** matrix);

	/*
		����������� �����������
		�������� ���������� ������� matrix
		args:
			matrix - ���������� �������
	*/
	SquareMatrix(const SquareMatrix& matrix);

	/*
		����������
		������� ���������� ������ ����� ������������ �������
	*/
	~SquareMatrix();

	/*
		������ ��� �������
		�������� ������� ������� �� ������� ����� rank � �������������� �� matrix
		args:
			rank - ���� �������
			matrix - ��������� ������ �������������
		����������:
			- ���� rank <= 0
			- ���� matrix == nullptr
	*/
	void setMatrix(int rank, double ** matrix);

	/*
		������ ��� �������� �������
		�������� �����������, ������� � ������ row � ������� col �� value
		args:
			row - ����� ������
			col - ����� �������
			value - ����� �������� �����������
		����������:
			- ���� row <= 0
			- ���� col <= 0
			- ���� row >= rank
			- ���� col >= rank
	*/
	void setValue(int row, int col, double value);

	/*
		������ ��� �����
		���������� �������� ����� �������
		return - �������� ����� �������
	*/
	int getRank();

	/*
		������ ��� �������
		���������� ����� �������
		return - ����� ������� _matrix
	*/
	double ** getMatrix();

	/*
		������ ��� �������� �������
		���������� �����������, ������� � ������ row � ������� col
		args:
			row - ����� ������
			col - ����� �������
		����������:
			- ���� row <= 0
			- ���� col <= 0
			- ���� row >= rank
			- ���� col >= rank
		return - �������� �����������, �������� � ������ row � ������� col
	*/
	double getValue(int row, int col);

	/*
		���������������� �������
	*/
	void transponse();

	/*
		���������� ������������ �������
		��������� �������� ������������ ������� � ������� ���������� �� ������ � �������
		return - �������� ������������
	*/
	double determinant();

	/*
		����� ������� �� �����
	*/
	void show();

private:

	//������� ������� (����)
	int _rank;

	//������ ������� - ��������� ������ � �������������
	double** _matrix;

	/*
		����� ��� ����������� �������
		args:
			rank - ���� ���������� �������
			matrix - ��������� ������ ������������� ���������� �������
		return - ����� ������� matrix
	*/
	double** copyMatrix(int rank, double** matrix);

	/*
		���������� ������ ��������, �������� � ������ row � ������ col ������� matrix ����� rank
		args:
			row - ������, � ������� ��������� �������, ����� �������� ����� ���������
			col - �������, � ������� ��������� �������, ����� �������� ����� ���������
			rank - ���� �������, � ������� ��������� �������, ����� �������� ����� ���������
			matrix - ���� ������� ����� rank
		return - �������� ������
	*/
	double minor(int row, int col, int rank, double** matrix);	

};