
#include "Queue.h"

//����������� � ���������� � �� ���������
Queue::Node::Node(Matrix& matrix) : _data(matrix)
{
	_next = _prev = this;
}