
#pragma once

//����� ���������� �������
class SquareMatrix
{
public:
	
	/*--------------������������ ������ 1--------------*/

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
		�������������� ������� � ������ char *
		return - ��������� ������������� �������
	*/
	char* toString();

	/*--------------������������ ������ 2--------------*/

	/*
		�������� �������� ������
		args:
			matrix1 - ����� ���������
			matrix2 - ������ ���������
		����������:
			���� _rank != matrix._rank, �� ���� ������� ������ ���� ����������� �������
		return - �������-��������� �������� �������1 � ��������2
	*/
	friend SquareMatrix operator+(const SquareMatrix& matrix1,const SquareMatrix& matrix2);

	/*
		�������� ��������� ������
		args:
			matrix1 - ����������� �������
			matrix2 - ���������� �������
		����������:
			���� _rank != matrix._rank, �� ���� ������� ������ ���� ����������� �������
		return - �������-��������� ��������� �������2 �� �������1
	*/
	friend SquareMatrix operator-(const SquareMatrix& matrix1, const SquareMatrix& matrix2);

	/*
		�������� ��������������
		args:
			index - ����� ������ �������
		����������:
			���� index < 0
			���� index >=_rank
		return - ����� �������-������ �������
	*/
	double* operator[](int index);

	/*
		�������� ()
		return - �������� ������������ �������
	*/
	double operator()();

	/*
		�������� ������������ ������
		args:
			matrix - ������������� �������
		return - ������ �� ������� �������
		������ ���������� ��� ����, ����� ������� ������������� ������������
		� �������, obj1 = obj2 = obj3 = obj4;
	*/
	SquareMatrix& operator=(const SquareMatrix& matrix);

private:

	//������� ������� (����)
	int _rank;

	//������ ������� - ��������� ������ � �������������
	double** _matrix;

	//����������� ���� ������ ��� �������� ���������� ��������� ��������
	static int _count;

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