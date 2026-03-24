#pragma once

// Псевдоним для типа числа
using Number = double;

// Выводит true, если удалось прочитать число и сохранить его в result.
bool ReadNumber(Number& result);

// Выводит true, если работа завершилась штатно командой q.
// Если из-за ошибки, выводит false.
bool RunCalculatorCycle();