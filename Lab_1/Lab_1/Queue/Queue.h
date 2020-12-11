#pragma once

#include <exception>
#include <iostream>

using namespace std;

//����� �������
template <typename T>
class Queue
{

public:
	
	/*
	����������� �� ���������
	*/
	Queue();

	/*
	����������
	*/
	~Queue();

	/*
	��������� ����� �������
	return - �������� ����� �������
	*/
	int getLength();

	/*
	���������� � ����� �������
	args:
		data - ����������� ������
	*/
	void push(T data);

	/*
	���������� �� �������
	args:
		data - ����������� ������
		index - ������ �������
	����������� ����������,	���� index ������� �� ������� �������
	*/
	void push(T data, int index);

	/*
	���������� �� ������ �������
	return - ������ ������� �������
	����������� ���������� ���� ������� ��� �����
	*/
	T pop();

	/*
	���������� �� �������
	return - ������� ������� ��� ������� index
	����������� ����������, ���� ������� ��� ����� ��� ���� ������ ������� �� ������� �������
	*/
	T pop(int index);

	/*
	������� �������
	*/
	void clear();

	/*
	����� �� ���������
	args:
		data - ������� ������
	return - ������, ��� ������� ��������� ������ data � �������
	*/
	int search(T data);
	
	/*
	����� � �������
	*/
	void print();

private:

	//����� ����
	class Node
	{
	public:

		//�������� ������
		T _data;

		//��������� �� ��������� � ���������� ��������
		Node* _next, * _prev;

		//����������� � ����������
		Node(T data) : _data(data)
		{
			_next = _prev = this;
		}

	};

	//����� �������
	int _length;

	//��������� �� ������ � ����� �������
	Node* _head, * _tail;
};


//�����������
template <typename T>
Queue<T>::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//����������
template <typename T>
Queue<T>::~Queue()
{
	clear();
}

//��������� ����� �������
template <typename T>
int Queue<T>::getLength()
{
	return _length;
}

//���������� � ����� �������
template <typename T>
void Queue<T>::push(T data)
{
	if (!_length)
	{
		_head = new Node(data);
		_tail = _head;
	}
	else
	{
		_tail->_next = new Node(data);
		_tail->_next->_prev = _tail;

		_tail = _tail->_next;

		_tail->_next = _head;
		_head->_prev = _tail;
	}

	_length++;
}

//���������� �� ������
template <typename T>
void Queue<T>::push(T data, int index)
{

	if ((index < 0) || (index > _length))
		throw exception("Bad index!");

	if (index == _length)
	{
		push(data);

		return;
	}

	if (!_length)
	{
		_head = _tail = new Node(data);
	}
	else
	{
		Node* temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		Node* prev = temp->_prev;

		prev->_next = new Node(data);
		prev->_next->_prev = prev;

		temp->_prev = prev->_next;
		prev->_next->_next = temp;

		if (!index)
			_head = temp->_prev;
	}

	_length++;
}

template <typename T>
T Queue<T>::pop()
{
	if (!_length)
		throw exception("The Queue is empty!");

	T data = _head->_data;

	if (_length == 1)
	{
		delete[] _head;
		_head = _tail = nullptr;
	}
	else
	{
		_head = _head->_next;

		delete _head->_prev;

		_head->_prev = _tail;
		_tail->_next = _head;
	}

	_length--;

	return data;
}

//���������� �� ������
template <typename T>
T Queue<T>::pop(int index)
{
	if (!_length)
		throw exception("The Queue is empty!");

	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	if (_length == 1)
	{
		T data = _head->_data;

		delete _head;
		_head = _tail = nullptr;

		_length--;

		return data;
	}
	else
	{

		Node* temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		temp->_next->_prev = temp->_prev;
		temp->_prev->_next = temp->_next;

		if (!index)
			_head = _head->_next;

		if (index == _length - 1)
			_tail = _tail->_prev;

		T data = temp->_data;
		delete temp;

		_length--;

		return data;
	}
}

//������� ������
template <typename T>
void Queue<T>::clear()
{

	Node* temp = _tail;

	for (int i = _length; i > 1; i--)
	{
		temp = temp->_prev;

		delete temp->_next;
	}

	delete _head;

	_head = _tail = nullptr;

	_length = 0;
}

//����� �� �������
template <typename T>
void Queue<T>::print()
{
	Node* temp = _head;

	for (int i = 0; i < _length; i++)
	{
		cout << temp->_data << endl;

		temp = temp->_next;
	}
}

//����� � �������
template <typename T>
int Queue<T>::search(T data)
{
	Node* temp = _head;

	for (int i = 0; i < _length; i++)
	{
		if (temp->_data == data)
			return i;

		temp = temp->_next;
	}

	return -1;
}