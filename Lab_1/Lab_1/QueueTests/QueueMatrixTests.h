#pragma once

#include "../Queue/Queue.h"

//класс тестирования очереди
class QueueMatrixTests
{
public:

	//тест обычной вставки и извлечения
	void pushPop();

	//тест вставки и извлечения по номеру
	void pushPopIndex();

	//тест поиска 
	void search();

	//очистка памяти
	void clearMemory(int rows, int cols, double** matrix);

};

