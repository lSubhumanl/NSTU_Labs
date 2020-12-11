#include "SquareMatrixTests.h"
#include <exception>
#include <iostream>
#include <cmath>

using namespace std;

const int MIN = -100;

const int MAX = 100;

//очистка памяти
void SquareMatrixTests::clearMemory(int rows, int cols, double** matrix)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

//тест конструктора с параметрами
void SquareMatrixTests::constructorWithParametrs()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//инициализируем объект конструктором с параметром
	SquareMatrix received(expectedRows, expectedMatrix);

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in constructor with parametrs!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in constructor with parametrs!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in constructor with parametrs!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Constructor with parametrs test completed!" << endl;
}

//тест конструктора копирования
void SquareMatrixTests::copyConstructor()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//создаем матрицу с помощью конструктора с параметрами, второй объект - инициализируем с помощью объекта
	SquareMatrix matrixForCopy(expectedRows, expectedMatrix), received(matrixForCopy);

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in copy constructor!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in copy constructor!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in copy constructor!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Copy constructor  test completed!" << endl;
}

//тест метода setMatrix()
void SquareMatrixTests::setMatrix()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//создаем объект и изменяем в нем матрицу
	SquareMatrix received(1, expectedMatrix);
	received.setMatrix(expectedRows, expectedCols, expectedMatrix);

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in setMatrix()!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in setMatrix()!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in setMatrix()!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "setMatrix() test completed!" << endl;
}

//тест транспонирования
void SquareMatrixTests::transponse()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//создаем матрицу и транспонируем ее
	SquareMatrix received(expectedRows, expectedMatrix);
	received.transponse();

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//все сравнения проводятся с учетом транспонирования

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in transponse()!");
	}

	if (receivedCols != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in transponse()!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[j][i] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in transponse()!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Transponse() test completed!" << endl;
}

//тест оператора присваивания
void SquareMatrixTests::assignmentOperator()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//создаем матрицу с помощью конструктора с параметрами, второй объект - инициализируем с помощью объекта
	SquareMatrix matrixForCopy(expectedRows, expectedMatrix), received = matrixForCopy;

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in assignment operator!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in assignment operator!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in assignment operator!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Assignment operator test completed!" << endl;
}

//тест оператора суммы
void SquareMatrixTests::additionOperator()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	SquareMatrix sumObj(expectedRows, expectedMatrix);

	//инициализируем объект суммой одинаковых матриц
	SquareMatrix received;
	received = sumObj + sumObj;
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] *= 2;

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in addition operator!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in addition operator!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in addition operator!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Addition operator test completed!" << endl;
}

//тест оператора вычитания
void SquareMatrixTests::subtractionOperator()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	SquareMatrix sumObj(expectedRows, expectedMatrix);

	//инициализируем объект суммой одинаковых матриц
	SquareMatrix received;
	received = sumObj - sumObj;
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = 0;

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in subtraction operator!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in subtraction operator!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in subtraction operator!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Subtraction operator test completed!" << endl;
}

//тест оператора индексирования
void SquareMatrixTests::indexingOperator()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//инициализируем объект конструктором с параметром
	SquareMatrix received(expectedRows, expectedMatrix);

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (received[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);

				throw exception("Error in indexing operator!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);

	cout << "Indexing operator test completed!" << endl;
}

//тест бинарного ввода-вывода
void SquareMatrixTests::binaryInputOutput()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//инициализируем объект для вывода в файл конструктором с параметром
	SquareMatrix objectForOutput(expectedRows, expectedMatrix);
	//выводим объект в файл
	fstream output("test.bin", ios::out | ios::trunc | ios::binary);
	objectForOutput.write(output);
	output.close();

	//в новый объект (для сравнения) считываем данные из файла
	SquareMatrix received(1, expectedMatrix);
	fstream input("test.bin", ios::in | ios::binary);
	received.read(input);
	input.close();

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in binary input-output!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in binary input-output!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in binary input-output!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "Binary input-output test completed!" << endl;
}

//тест файлового ввода-вывода
void SquareMatrixTests::fileInputOutput()
{
	int expectedRows = 4;
	int expectedCols = 4;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//инициализируем объект для вывода в файл конструктором с параметром
	SquareMatrix objectForOutput(expectedRows, expectedMatrix);
	//выводим объект в файл
	ofstream output("test.txt");
	output << objectForOutput;
	output.close();

	//в новый объект (для сравнения) считываем данные из файла
	SquareMatrix received( 1, expectedMatrix);
	ifstream input("test.txt");
	input >> received;
	input.close();

	int receivedRows = received.getRows();
	int receivedCols = received.getCols();
	double** receivedMatrix = received.getMatrix();

	//если количество строк и столбцов не совпадает
	if (receivedRows != expectedRows)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in file input-output!");
	}

	if (receivedCols != expectedCols)
	{
		clearMemory(expectedRows, expectedCols, expectedMatrix);
		clearMemory(receivedRows, receivedCols, receivedMatrix);

		throw exception("Error in file input-output!");
	}

	//если элементы матриц не совпадают
	for (int i = 0; i < expectedRows; i++)
		for (int j = 0; j < expectedCols; j++)
			if (receivedMatrix[i][j] != expectedMatrix[i][j])
			{
				clearMemory(expectedRows, expectedCols, expectedMatrix);
				clearMemory(receivedRows, receivedCols, receivedMatrix);

				throw exception("Error in file input-output!");
			}

	clearMemory(expectedRows, expectedCols, expectedMatrix);
	clearMemory(receivedRows, receivedCols, receivedMatrix);

	cout << "File input-output test completed!" << endl;
}

//тест вычисления определителя
void SquareMatrixTests::determinant()
{
	int rows = 3;
	int cols = 3;
	double** matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	//высчитываем определитель для матрицы 3го порядка
	double expected =
		matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][1] * matrix[1][0] * matrix[2][2] -
		matrix[0][0] * matrix[1][2] * matrix[2][1];

	//инициализируем объект конструктором с параметром
	SquareMatrix matrixObj(rows, matrix);

	//вычисляем с помощью метода объекта
	double received = matrixObj.determinant();

	//сравниваем ожидаемый результат и полученный
	if (received != expected)
	{
		clearMemory(rows, cols, matrix);

		throw exception("Error in determinant()!");
	}

	clearMemory(rows, cols, matrix);

	cout << "determinant() test completed!" << endl;
}
