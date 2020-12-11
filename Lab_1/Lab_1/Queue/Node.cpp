
#include "Queue.h"

//конструктор с параметром и по умолчанию
Queue::Node::Node(Matrix& matrix) : _data(matrix)
{
	_next = _prev = this;
}