#pragma once

#include "../Queue/Queue.h"

//����� ������������ �������
class QueueTests
{
public:

	//���� ������� ������� � ����������
	void pushPop();

	//���� ������� � ���������� �� ������
	void pushPopIndex();

	//���� ������ 
	void search();

	//������� ������
	void clearMemory(int rows, int cols, double** matrix);

};

