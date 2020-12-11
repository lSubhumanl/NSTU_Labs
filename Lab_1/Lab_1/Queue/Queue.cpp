
#include "Queue.h"
#include <exception>

using namespace std;

//�����������
Queue::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//����������
Queue::~Queue()
{
	clear();
}

//��������� ����� �������
int Queue::getLength()
{
	return _length;
}

//���������� � ����� �������
void Queue::push(Matrix& matrix)
{
	if (!_length)
	{
		_head = new Node(matrix);
		_tail = _head;
	}
	else
	{
		_tail->_next = new Node(matrix);
		_tail->_next->_prev = _tail;

		_tail = _tail->_next;

		_tail->_next = _head;
		_head->_prev = _tail;
	}

	_length++;
}

//���������� �� ������
void Queue::push(Matrix& matrix, int index)
{

	if ((index < 0) || (index > _length))
		throw exception("Bad index!");

	if (index == _length)
	{
		push(matrix);

		return;
	}

	if (!_length)
	{
		_head = _tail = new Node(matrix);
	}
	else
	{
		Node * temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		Node * prev = temp->_prev;

		prev->_next = new Node(matrix);
		prev->_next->_prev = prev;

		temp->_prev = prev->_next;
		prev->_next->_next = temp;

		if (!index)
			_head = temp->_prev;
	}

	_length++;
}

Matrix& Queue::pop()
{
	if (!_length)
		throw exception("The Queue is empty!");

	Matrix& result = _head->_data;

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

	return result;
}

//���������� �� ������
Matrix& Queue::pop(int index)
{
	if (!_length)
		throw exception("The Queue is empty!");
	
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	if (_length == 1)
	{
		Matrix& result = _head->_data;

		delete _head;
		_head = _tail = nullptr;

		_length--;

		return result;
	}
	else
	{

		Node * temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		temp->_next->_prev = temp->_prev;
		temp->_prev->_next = temp->_next;

		if (!index)
			_head = _head->_next;

		if (index == _length - 1)
			_tail = _tail->_prev;

		Matrix& result = temp->_data;
		delete temp;

		_length--;

		return result;
	}
}

//������� ������
void Queue::clear()
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
void Queue::print()
{
	Node * temp = _head;

	for (int i = 0; i < _length; i++)
	{
		temp->_data.print();
		cout << endl;
		
		temp = temp->_next;
	}
}

//����� � �������
int Queue::search(Matrix& matrix)
{
	Node * temp = _head;

	for (int i = 0; i < _length; i++)
	{
		if (temp->_data == matrix)
			return i;

		temp = temp->_next;
	}

	return -1;
}