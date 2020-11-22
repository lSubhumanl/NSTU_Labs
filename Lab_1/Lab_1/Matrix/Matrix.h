#pragma once

#include <iostream>
#include <fstream>

using namespace std;

//класс матрицы
class Matrix
{
public:

	/*
	Конструктор по умолчанию
	Создает матрицу размера  1х1 со значением 0
	*/
	Matrix();

	/*
	конструктор с параметрами
	args:
		rows - количество строк в матрице
		cols - количество столбцов в матрице
		matrix - матрица
	выбрасывает исключение, если rows или cols меньше 0, а в matrix встречен нулевой указатель
	*/
	Matrix(int rows, int cols, double** matrix);

	/*
	конструктор копирования
	args:
		matrix - копируемая матрица
	*/
	Matrix(const Matrix& matrix);

	//деструктор
	virtual ~Matrix();


	/*
	Получение количества строк
	return - количество строк
	*/
	int getRows();

	/*
	Получение количества столбцов
	return - количество столбцов
	*/
	int getCols();

	/*
	Получение копии матрицы
	return - копия матрицы
	*/
	double** getMatrix();

	/*
	Получение значения по индексами
	args:
		rowIndex - номер строки
		colIndex - номер столбца
	return - ссылка на значение
	выбрасывает исключение, если индексы выходят за пределы матрицы
	*/
	double& getValue(int rowIndex, int colIndex);

	/*
	изменение матрицы
	Изменяет текущую матрицу на входну
	args:
		rows - количество строк в матрице
		cols - количество столбцов в матрице
		matrix - матрица
	выбрасывает исключение, если rows или cols меньше 0, а в matrix встречен нулевой указатель
	*/
	virtual void setMatrix(int rows, int cols, double** matrix);


	/*
	Получение строкового представления матрицы
	return - строковое представление матрицы
	*/
	char* toString();

	/*
	Транспонирование матрицы
	*/
	virtual void transponse();


	/*
	Оператор сложения матрицы
	args:
		matrix - второе слагаемое
	return - результат сложения матриц
	выбрасывает исключение, если размеры матриц не равны друг другу
	*/
	Matrix operator+(const Matrix& matrix);

	/*
	Оператор сложения матрицы
	args:
		matrix - вычитаемая матрица
	return - результат вычитания матриц
	выбрасывает исключение, если размеры матриц не равны друг другу
	*/
	Matrix operator-(const Matrix& matrix);

	/*
	Оператор индексирования
	args:
		rowIndex - номер строки
	return - копия строки под номером rowIndex
	выбрасывает исключение, если rowIndex выходит за пределы матрицы
	*/
	double * operator[](int rowIndex);

	/*
	Оператор присваивания матриц
	args:
		matrix - присваиваемая матрица
	return - ссылка на текущий объект
	*/
	Matrix& operator=(const Matrix& matrix);



	/*
	Оператор вывода в поток вывода
	Работает и с файловыми потоками, и с обычными
	args:
		stream - поток вывода
		matrix - выводимая матрица
	return - ссылка на поток вывода
	*/
	friend ostream& operator<<(ostream& stream, const Matrix& matrix);

	/*
	Оператор ввода из потока ввода
	Работает и с файловыми потоками, и с обычными
	args:
		stream - поток ввода
		matrix - вводимая матрица
	return - ссылка на поток ввода
	*/
	friend istream& operator>>(istream& stream, Matrix& matrix);

	/*
	Запись в бинарный файл
	args:
		file - бинарный файл для записи
	выбрасывает исключение, если file не открыт
	*/
	void write(fstream& file);

	/*
	Чтение из бинарного файла
	args:
		file - бинарный файл для чтения
	выбрасывает исключение, если file не открыт
	*/
	void read(fstream& file);

protected:

	/*
	Матрица
	*/
	double** _matrix;

	/*
	количество строк матрицы
	*/
	int _rows;

	/*
	количество столбцов матрицы
	*/
	int _cols;


	/*
	копирование матрицы
	Возвращает копию матрицы matrix
	args:
		rows - количество строк в матрице
		cols - количество столбцов в матрице
		matrix - копируемая матрица
	return - копия матрицы matrix
	*/
	double** copyMatrix(int rows, int cols, double** matrix);
	
};

