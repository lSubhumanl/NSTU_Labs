#pragma once

#include "../SquareMatrix/SquareMatrix.h"

//геттеры не тестируются, т.к. в них находится примитивный код

//тест конструктора с параметрами
void constructorWithParametrsTest();

//тест конструктора копирования
void copyConstructorTest();

//тест метода изменения матрицы
void setMatrixTest();

//тест метода изменения значения матрицы
void setValueTest();

//тест метода транспонирования матрицы
void transponseTest();

//тест метода вычисления определителя
void determinantTest();

//тест оператора сложения
void additionOperatorTest();

//тест оператора вычитания
void subtractionOperatorTest();

//тест оператора индексирования
void indexingOperatorTest();

//тест оператора ()
void functionOperatorTest();

//тест оператора присваивания
void assignmentOperatorTest();