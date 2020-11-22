#pragma once

#include "../Matrix/Matrix.h"

class MatrixTests
{
private:

	//метод для очистки выделенной памяти
	void clearMemory(int rows, int cols, double** matrix);

public:

	//геттеры не тестируются, т.к. в них находится примитивный код

	//тест конструктора с параметрами
	void constructorWithParametrs();

	//тест конструктора копирования
	void copyConstructor();

	//тест метода изменения матрицы
	void setMatrix();

	//тест метода транспонирования матрицы
	void transponse();

	//тест оператора сложения
	void additionOperator();

	//тест оператора вычитания
	void subtractionOperator();

	//тест оператора индексирования
	void indexingOperator();

	//тест оператора присваивания
	void assignmentOperator();

	//тест ввода-вывода в бинарный файл
	void binaryInputOutput();

	//тест ввода-вывода в текстовый файл
	void fileInputOutput();

};