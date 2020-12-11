
#include "QueueTests/QueueIntTests.h"
#include "QueueTests/QueueMatrixTests.h"
#include "MatrixTests/MatrixTests.h"

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
		cout << "Queue<int> tests:" << endl;

		QueueIntTests tester;

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

	{
		cout << "Queue<matrix> tests:" << endl;

		QueueMatrixTests tester;

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

	system("pause");
	return 0;
}