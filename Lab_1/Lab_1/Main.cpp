
#include "MatrixTests/MatrixTests.h"
#include "SquareMatrixTests/SquareMatrixTests.h"
#include "CramersRuleTests/CramersRuleTests.h"

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

	


	cout << "Press any key:" << endl;
	char c;
	cin >> c;

	return 0;
}
