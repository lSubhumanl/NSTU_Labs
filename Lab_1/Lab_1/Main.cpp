
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

	char c;
	cin >> c;

	return 0;
}