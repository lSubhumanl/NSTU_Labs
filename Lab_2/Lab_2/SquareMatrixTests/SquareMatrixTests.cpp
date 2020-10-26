#include "SquareMatrixTests.h"
#include <exception>
#include <iostream>

using namespace std;

//тест конструктора с параметрами
void constructorWithParametrsTest()
{
	//создаем матрицу для сравнения
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект этой матрицей
	SquareMatrix matrixObject(rank, matrix);

	//получаем матрицу, которая находится внутри объекта
	double** matrixResult = matrixObject.getMatrix();
	
	//и сравниваем элементы этих двух матриц
	for (int i = 0; i < rank; i++)
		for (int j = 0; j < rank; j++)
			//если соответствующие элементы не равны
			if (matrixResult[i][j] != matrix[i][j])
			{

				//то очищаем память от матриц
				for (int i = 0; i < rank; i++)
				{
					delete[] matrix[i];
					delete[] matrixResult[i];
				}
				delete[] matrix;
				delete[] matrixResult;

				//и выбрасываем исключение
				throw exception("Error in constructor with parametrs");
			}

	//очищаем выделенную под матрицы память
	for (int i = 0; i < rank; i++)
	{
		delete[] matrix[i];
		delete[] matrixResult[i];
	}
	delete[] matrix;
	delete[] matrixResult;

	//если в объекте установлено неверное значение ранга
	if (matrixObject.getRank() != rank)
		throw exception("Error in constructor with parametrs");

	cout << "Constructor with parametrs test completed!" << endl;
}

//тест конструктора копирования
void copyConstructorTest()
{
	//создаем матрицу для сравнения
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект 1 этой матрицей, а объект 2 - объектом 1
	SquareMatrix matrixObject1(rank, matrix), matrixObject2(matrixObject1);

	//получаем матрицы, которые находится внутри объекта
	double** matrixResult1 = matrixObject1.getMatrix();
	double** matrixResult2 = matrixObject2.getMatrix();

	//и сравниваем элементы этих двух матриц
	for (int i = 0; i < rank; i++)
		for (int j = 0; j < rank; j++)
			//если соответствующие элементы не равны
			if (matrixResult1[i][j] != matrixResult2[i][j])
			{

				//то очищаем память от матриц
				for (int i = 0; i < rank; i++)
				{
					delete[] matrix[i];
					delete[] matrixResult1[i];
					delete[] matrixResult2[i];
				}
				delete[] matrix;
				delete[] matrixResult1;
				delete[] matrixResult2;

				//и выбрасываем исключение
				throw exception("Error in copy constructor");
			}

	//очищаем выделенную под матрицы память
	for (int i = 0; i < rank; i++)
	{
		delete[] matrix[i];
		delete[] matrixResult1[i];
		delete[] matrixResult2[i];
	}
	delete[] matrix;
	delete[] matrixResult1;
	delete[] matrixResult2;

	//если в объекте установлено неверное значение ранга
	if (matrixObject1.getRank() != matrixObject2.getRank())
		throw exception("Error in copy constructor");

	cout << "Copy constructor test completed!" << endl;
}

//тест сеттера для матрицы
void setMatrixTest()
{
	//создаем матрицу 1
	int rank1 = 5, value = 0;
	double** matrix1 = new double* [rank1];
	for (int i = 0; i < rank1; i++)
	{
		matrix1[i] = new double[rank1];
		for (int j = 0; j < rank1; j++)
			matrix1[i][j] = value++;
	}

	//создаем матрицу 2
	int rank2 = 3;
	double** matrix2 = new double* [rank2];
	for (int i = 0; i < rank2; i++)
	{
		matrix2[i] = new double[rank2];
		for (int j = 0; j < rank2; j++)
			matrix2[i][j] = value++;
	}

	//инициализируем объект матрицей 1
	SquareMatrix matrixObject(rank1, matrix1);

	//устанавливаем в объект матрицу 2
	matrixObject.setMatrix(rank2, matrix2);

	for (int i = 0; i < rank2; i++)
	{
		for(int j = 0;j<rank2;j++)
			//если установленные коэффициенты не совпдают с теми, что в матрице 2
			if (matrixObject.getValue(i, j) != matrix2[i][j])
			{
				//очищаем выделенную под матрицы память
				for (int i = 0; i < rank1; i++)
					delete[] matrix1[i];
				delete[] matrix1;

				for (int i = 0; i < rank2; i++)
					delete[] matrix2[i];
				delete[] matrix2;

				//то возвращаем ошибку
				throw exception("Error in setMatrix() method");
			}
	}

	for (int i = 0; i < rank1; i++)
		delete[] matrix1[i];
	delete[] matrix1;

	for (int i = 0; i < rank2; i++)
		delete[] matrix2[i];
	delete[] matrix2;

	//также, проверяем значение ранга
	if(matrixObject.getRank() != rank2)
		throw exception("Error in setMatrix() method");

	cout << "setMatrix() test completed!" << endl;
}

//тест сеттера для значения
void setValueTest()
{
	//создаем матрицу для сравнения
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	SquareMatrix matrixObject(rank, matrix);

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			//устанавливаем каждый элемент матрицы в -1
			matrixObject.setValue(i, j, -1);
			
			//и проверяем, установился ли он
			if (matrixObject.getValue(i,j) != -1)
				//если нет, то выбрасываем исключение
				throw exception("Error in setValue() method");
		}
	}

	cout << "setValue() test completed!" << endl;
}

//тест метода транспонирования
void transponseTest()
{
	//создаем матрицу для сравнения
	int rank = 5, value = 0;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	//транспонируем матрицу
	matrixObject.transponse();

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			//и проверяем, транспонировалась ли матрица
			if (matrixObject.getValue(i, j) != matrix[j][i])
			{	
				for (int i = 0; i < rank; i++)
					delete[] matrix[i];
				delete[] matrix;

				//если нет, то выбрасываем исключение
				throw exception("Error in transponse() method");
			}
		}
	}

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	cout << "transponse() test completed!" << endl;
}

//тест метода вычисления определителя
void determinantTest()
{
	//создаем матрицу для сравнения
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}
	matrix[0][0] = 2;

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	if (matrixObject.determinant() != -3)
		throw exception("Error in determinant() method");
	
	cout << "determinant() test completed!" << endl;
}

//тест оператора сложения
void additionOperatorTest()
{
	//создаем матрицу
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	//очищаем память от матрицы
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//складываем матрицу с собой и сохраняем результат
	SquareMatrix result = matrixObject + matrixObject;

	//выходит, что в результирующей матрице все элементы должны быть в два раза больше
	for(int i =0;i<result.getRank();i++)
		for(int j = 0;j<result.getRank();j++)
			if(result.getValue(i,j) != 2*matrixObject.getValue(i,j))
				throw exception("Error in + operator");

	cout << "+ operator test completed!" << endl;
}

//тест оператора вычитания
void subtractionOperatorTest()
{
	//создаем матрицу
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	//очищаем память от матрицы
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//складываем матрицу с собой и сохраняем результат
	SquareMatrix result = matrixObject - matrixObject;

	//выходит, что в результирующей матрице все элементы должны быть равны нулю
	for (int i = 0; i < result.getRank(); i++)
		for (int j = 0; j < result.getRank(); j++)
			if (result.getValue(i, j) != 0)
				throw exception("Error in - operator");

	cout << "- operator test completed!" << endl;
}

//тест оператора []
void indexingOperatorTest()
{
	//создаем матрицу
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	//очищаем память от матрицы
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//выходит, что в результирующей матрице все элементы должны быть равны нулю
	for (int i = 0; i < matrixObject.getRank(); i++)
		for (int j = 0; j < matrixObject.getRank(); j++)
			if (matrixObject.getValue(i, j) != matrixObject[i][j])
				throw exception("Error in [] operator");

	cout << "[] operator test completed!" << endl;
}

//тест оператора ()
void functionOperatorTest()
{
	//создаем матрицу
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}
	matrix[0][0] = 2;

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	if (matrixObject() != matrixObject.determinant())
		throw exception("Error in () operator");

	cout << "() operator test completed!" << endl;
}

//тест оператора присваивания
void assignmentOperatorTest()
{
	//создаем матрицу
	int rank = 3, value = 1;
	double** matrix = new double* [rank];
	for (int i = 0; i < rank; i++)
	{
		matrix[i] = new double[rank];
		for (int j = 0; j < rank; j++)
			matrix[i][j] = value++;
	}

	//инициализируем объект матрицей
	SquareMatrix matrixObject(rank, matrix);

	//очищаем память от матрицы
	for (int i = 0; i < rank; i++)
		delete[] matrix[i];
	delete[] matrix;

	//складываем матрицу с собой и сохраняем результат
	SquareMatrix result = matrixObject;

	if(result.getRank() != matrixObject.getRank())
		throw exception("Error in = operator");

	//выходит, что в результирующей матрице все элементы должны быть равны нулю
	for (int i = 0; i < result.getRank(); i++)
		for (int j = 0; j < result.getRank(); j++)
			if (result.getValue(i, j) != matrixObject.getValue(i,j))
				throw exception("Error in = operator");

	cout << "= operator test completed!" << endl;
}