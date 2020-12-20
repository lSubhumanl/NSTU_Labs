#include "QueueTests.h"
#include "../CramersRule/CramersRule.h"
#include "../SquareMatrix/SquareMatrix.h"

const int MIN = -100;

const int MAX = 100;

//очистка памяти
void QueueTests::clearMemory(int rows, int cols, double** matrix)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void QueueTests::pushPop()
{

	int expectedRows = 4;
	int expectedCols = 5;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}
	
	int expectedLen = 3;
	Matrix** arr = new Matrix*[expectedLen];
	arr[0] = new Matrix(expectedRows, expectedCols-2, expectedMatrix);
	arr[1] = new CramersRule(expectedRows, expectedCols, expectedMatrix);
	arr[2] = new SquareMatrix(expectedRows, expectedMatrix);

	Queue received;

	for (int i = 0; i < expectedLen; i++)
		received.push((*arr[i]));

	if (received.getLength() != expectedLen)
	{
		delete[] arr;
		clearMemory(expectedRows, expectedCols, expectedMatrix);

		throw exception("Error in push-pop methods!");
	}

	for (int i = 0; i < received.getLength(); i++)
	{
		Matrix& temp = received.pop();

		if(!(temp == (*arr[i])))
		{
			delete[] arr;
			clearMemory(expectedRows, expectedCols, expectedMatrix);

			throw exception("Error in push-pop methods!");
		}
	}

	cout << "Push-pop methods test completed!" << endl;

	delete[] arr;
	clearMemory(expectedRows, expectedCols, expectedMatrix);
}

void QueueTests::pushPopIndex()
{
	int expectedRows = 4;
	int expectedCols = 5;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	int expectedLen = 3;
	Matrix** arr = new Matrix*[expectedLen];
	arr[0] = new Matrix(expectedRows, expectedCols-2, expectedMatrix);
	arr[1] = new CramersRule(expectedRows, expectedCols, expectedMatrix);
	arr[2] = new SquareMatrix(expectedRows, expectedMatrix);

	Queue received;

	for (int i = 0; i < expectedLen; i++)
		received.push(*arr[i],i);

	if (received.getLength() != expectedLen)
	{
		delete[] arr;
		clearMemory(expectedRows, expectedCols, expectedMatrix);

		throw exception("Error in push-pop with index methods!");
	}

	for (int i = received.getLength() - 1; i >=0; i--)
	{
		Matrix& temp = received.pop(i);

		if (!(temp == (*arr[i])))
		{
			delete[] arr;
			clearMemory(expectedRows, expectedCols, expectedMatrix);

			throw exception("Error in push-pop with index methods!");
		}
	}

	cout << "Push-pop with index methods test completed!" << endl;

	delete[] arr;
	clearMemory(expectedRows, expectedCols, expectedMatrix);
}



void QueueTests::search()
{
	int expectedRows = 4;
	int expectedCols = 5;
	double** expectedMatrix = new double* [expectedRows];
	for (int i = 0; i < expectedRows; i++)
	{
		expectedMatrix[i] = new double[expectedCols];
		for (int j = 0; j < expectedCols; j++)
			expectedMatrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}

	int expectedLen = 3;
	Matrix** arr = new Matrix*[expectedLen];
	arr[0] = new Matrix(expectedRows, expectedCols-2, expectedMatrix);
	arr[1] = new CramersRule(expectedRows, expectedCols, expectedMatrix);
	arr[2] = new SquareMatrix(expectedRows, expectedMatrix);

	Queue received;

	for (int i = 0; i < expectedLen; i++)
		received.push(*arr[i]);

	for (int i = 0; i < received.getLength(); i++)
		if (received.search(*arr[i]) != i)
		{
			delete[] arr;
			clearMemory(expectedRows, expectedCols, expectedMatrix);

			throw exception("Error in search method!");
		}

	cout << "Search method test completed!" << endl;

	delete[] arr;
	clearMemory(expectedRows, expectedCols, expectedMatrix);
}

void QueueTests::polymorphism()
{
	int rows = 4;
	int cols = 5;
	double** matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = MIN + rand() % (MAX + abs(MIN));
	}	
	
	int len = 3;
	Matrix** arr = new Matrix * [len];
	arr[0] = new Matrix(rows, cols - 2, matrix);
	arr[1] = new CramersRule(rows, cols, matrix);
	arr[2] = new SquareMatrix(rows, matrix);

	char** expected = new char* [3];
	expected[0] = const_cast<char*>(typeid(Matrix).name());
	expected[1] = const_cast<char*>(typeid(CramersRule).name());
	expected[2] = const_cast<char*>(typeid(SquareMatrix).name());

	Queue received;

	for (int i = 0; i < len; i++)
		received.push((*arr[i]));

	for (int i = 0; i < len; i++)
	{
		Matrix& temp = received.pop();

		if (strcmp(expected[i], typeid(temp).name()))
		{
			delete[] arr;
			clearMemory(rows, cols, matrix);

			throw exception("Error in polymophism test!");
		}
	}

	cout << "Polymophism test completed!" << endl;

	delete[] arr;
	clearMemory(rows, cols, matrix);
}
