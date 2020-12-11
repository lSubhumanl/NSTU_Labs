#pragma once

#include "../Queue/Queue.h"

//класс тестирования очереди
class QueueIntTests
{
public:

	//тест обычной вставки и извлечения
	void pushPop();

	//тест вставки и извлечения по номеру
	void pushPopIndex();

	//тест поиска 
	void search();

};

