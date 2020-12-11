#pragma once

#include <exception>
#include <iostream>

using namespace std;

//Класс очереди
template <typename T>
class Queue
{

public:
	
	/*
	конструктор по умолчанию
	*/
	Queue();

	/*
	деструктор
	*/
	~Queue();

	/*
	получение длины очереди
	return - значение длины очереди
	*/
	int getLength();

	/*
	добавление в конец очереди
	args:
		data - вставляемый объект
	*/
	void push(T data);

	/*
	добавление по индексу
	args:
		data - вставляемый объект
		index - индекс вставки
	Выбрасывает исключение,	если index выходит за пределы очереди
	*/
	void push(T data, int index);

	/*
	извлечение из начала очереди
	return - первый элемент очереди
	выбрасывает исключение если очередь уже пуста
	*/
	T pop();

	/*
	извлечение по индексу
	return - элемент очереди под номером index
	выбрасывает исключение, если очередь уже пуста или если индекс выходит за пределы очереди
	*/
	T pop(int index);

	/*
	очистка очереди
	*/
	void clear();

	/*
	поиск по структуре
	args:
		data - искомый объект
	return - индекс, под которым находится объект data в очереди
	*/
	int search(T data);
	
	/*
	вывод в консоль
	*/
	void print();

private:

	//класс узла
	class Node
	{
	public:

		//хранимый объект
		T _data;

		//указатели на следующий и предыдущий элементы
		Node* _next, * _prev;

		//конструктор с параметром
		Node(T data) : _data(data)
		{
			_next = _prev = this;
		}

	};

	//длина очереди
	int _length;

	//указатели на начало и конец очереди
	Node* _head, * _tail;
};


//конструктор
template <typename T>
Queue<T>::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//деструктор
template <typename T>
Queue<T>::~Queue()
{
	clear();
}

//получение длины очереди
template <typename T>
int Queue<T>::getLength()
{
	return _length;
}

//добавление в конец очереди
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

//добавление по номеру
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

//извлечение по номеру
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

//очистка списка
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

//вывод на консоль
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

//поиск в очереди
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