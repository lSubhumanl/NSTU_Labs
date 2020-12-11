
#include "MatrixTests/MatrixTests.h"
#include "SquareMatrixTests/SquareMatrixTests.h"
#include "CramersRuleTests/CramersRuleTests.h"
#include "QueueTests/QueueTests.h"

int main()
{
	{
		MatrixTests tester;

		cout << "Matrix tests:" << endl;

		try
		{
			tester.constructorWithParametrs();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.setMatrix();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.transponse();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.additionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.subtractionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.indexingOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.binaryInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.fileInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		cout << endl;
	}

	{
		CramersRuleTests tester;

		cout << "Cramers rule tests:" << endl;

		try
		{
			tester.constructorWithParametrs();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.setMatrix();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.transponse();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.additionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.subtractionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.indexingOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.binaryInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.fileInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.compute();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		cout << endl;
	}

	{
		cout << "Square matrix tests:" << endl;

		SquareMatrixTests tester;

		try
		{
			tester.constructorWithParametrs();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.setMatrix();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.transponse();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.additionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.subtractionOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.indexingOperator();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.binaryInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.fileInputOutput();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.determinant();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		cout << endl;
	}

	{
		cout << "Queue tests:" << endl;

		QueueTests tester;

		try
		{
			tester.pushPop();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}

		try
		{
			tester.pushPopIndex();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}

		try
		{
			tester.search();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
	}
	cout << endl;

	int rows = 4;
	int cols = 5;
	double** matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = -100 + rand() % 200;
	}

	int len = 3;
	Matrix** arr = new Matrix * [len];
	arr[0] = new Matrix(rows, cols - 2, matrix);
	arr[1] = new CramersRule(rows, cols, matrix);
	arr[2] = new SquareMatrix(rows, matrix);

	Queue queue;

	for (int i = 0; i < len; i++)
		queue.push((*arr[i]));

	queue.print();

	system("pause");
	return 0;
}