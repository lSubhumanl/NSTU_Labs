
#include "SquareMatrixTests/SquareMatrixTests.h"
#include <iostream>

using namespace std;

int main()
{

	try
	{
		constructorWithParametrsTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		copyConstructorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		setMatrixTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		setValueTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		transponseTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		determinantTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		assignmentOperatorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		indexingOperatorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		functionOperatorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		additionOperatorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		subtractionOperatorTest();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	cout << "Press any key:" << endl;
	char c;
	cin >> c;

	return 0;
}
