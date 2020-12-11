#include "QueueMatrixTests.h"
#include "../Matrix/Matrix.h"

const int MIN = -100;

const int MAX = 100;

//очистка памяти
void QueueMatrixTests::clearMemory(int rows, int cols, double** matrix)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void QueueMatrixTests::pushPop()
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
	arr[0] = new Matrix(expectedRows, expectedCols, expectedMatrix);
	arr[1] = new Matrix(expectedRows, expectedCols - 1, expectedMatrix);
	arr[2] = new Matrix(expectedRows, expectedCols - 2, expectedMatrix);

	Queue<Matrix> received;

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
		Matrix temp = received.pop();

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

void QueueMatrixTests::pushPopIndex()
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
	Matrix** arr = new Matrix * [expectedLen];
	arr[0] = new Matrix(expectedRows, expectedCols, expectedMatrix);
	arr[1] = new Matrix(expectedRows, expectedCols - 1, expectedMatrix);
	arr[2] = new Matrix(expectedRows, expectedCols - 2, expectedMatrix);

	Queue<Matrix> received;

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
		Matrix temp = received.pop(i);

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



void QueueMatrixTests::search()
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
	Matrix** arr = new Matrix * [expectedLen];
	arr[0] = new Matrix(expectedRows, expectedCols, expectedMatrix);
	arr[1] = new Matrix(expectedRows, expectedCols - 1, expectedMatrix);
	arr[2] = new Matrix(expectedRows, expectedCols - 2, expectedMatrix);

	Queue<Matrix> received;

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
