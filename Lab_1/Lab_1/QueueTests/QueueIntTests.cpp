#include "QueueIntTests.h"
#include <exception>
#include <iostream>

using namespace std;

const int MIN = -100;

const int MAX = 100;

void QueueIntTests::pushPop()
{	
	const int expectedLen = 6;
	int arr[expectedLen] = { 1,2,3,4,5,6 };

	Queue<int> received;

	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	if (received.getLength() != expectedLen)
		throw exception("Error in push-pop methods!");

	for (int i = 0; i < received.getLength(); i++)
	{
		int temp = received.pop();

		if(!(temp == arr[i]))
			throw exception("Error in push-pop methods!");
	}

	cout << "Push-pop methods test completed!" << endl;	
}

void QueueIntTests::pushPopIndex()
{
	const int expectedLen = 6;
	int arr[expectedLen] = { 1,2,3,4,5,6 };

	Queue<int> received;

	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i],i);

	if (received.getLength() != expectedLen)
		throw exception("Error in push-pop with index methods!");

	for (int i = received.getLength() - 1; i >=0; i--)
	{
		int temp = received.pop(i);

		if (!(temp == arr[i]))
			throw exception("Error in push-pop with index methods!");
	}

	cout << "Push-pop with index methods test completed!" << endl;

	
}



void QueueIntTests::search()
{
	const int expectedLen = 6;
	int arr[expectedLen] = { 1,2,3,4,5,6 };

	Queue<int> received;

	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	for (int i = 0; i < received.getLength(); i++)
		if (received.search(arr[i]) != i)
			throw exception("Error in search method!");

	cout << "Search method test completed!" << endl;
}
