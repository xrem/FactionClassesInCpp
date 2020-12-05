#include <iostream>
#include <vector>
#include <array>
#include <forward_list>
#include <list>


#include "FractionClass.h"
#include "Point.h"
#include "Triangle.h"

void swap(std::vector<int>& v, const int i, const int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int main()
{
	// Standard Template Library.
	// STL-Контейнеры. 
	// vector - Массив с динамически изменяемым размером.


	// T<> - Аргумент для шаблонной функции/метода/класса
	// <int> - Создаем контейнер для чисел
	// { в конструктор } передаём набор чисел которые будут изначально содержаться в контейнере 
	std::vector<int> vectorInteger;
	// динамичски добавляем элементы в наш контейнер и увеличиваем его размер (длину)
	vectorInteger.push_back(1);
	vectorInteger.push_back(2);
	vectorInteger.push_back(3333);
	vectorInteger.push_back(3);
	vectorInteger.push_back(4);
	vectorInteger.push_back(5555);
	vectorInteger.push_back(5);
	vectorInteger.push_back(6);

	swap(vectorInteger, 2, 5);
	
	// vector.size() -> метод позволяющий расчитать длину контрейнера.
	for (int i = 0; i < vectorInteger.size(); i++)
	{
		std::cout << vectorInteger[i] << std::endl;
	}	

	// Тот же самый блок кода, для вывода элементов поочередно, с использованием цикла for each
	// В какую переменную читать элементы из какого контейнера.
	for (int element : vectorInteger)
	{
		std::cout << element << std::endl;
	}

	// STL-Контейнер Array - обёртка для обычного массива с фиксированной длиной.
	int arr[5] = { 1, 2, 3, 4, 5 };
	std::array<int, 5> fixed_array = { 1, 2, 3, 4, 5 };
	std::cout << fixed_array.size() << std::endl;
	for (int element : fixed_array)
	{
		std::cout << element << std::endl;
	}

	// STL-Контейтер односвязный граф, позволяет добавлять элементы только с одной стороны графа
	std::cout << "----------Forward list----------" << std::endl;
	std::forward_list<int> forward_list = { 1, 2, 3, 4, 5 };
	forward_list.push_front(55);
	forward_list.push_front(66);
	for (int element : forward_list)
	{
		std::cout << element << std::endl;
	}

	// STL-Контейнер двухсвязный граф (сущесвует ссылки внутри как на следующий элемент, так и на предыдущий)
	std::cout << "------------- List -------------" << std::endl;
	std::list<int> list = { 1, 2, 3, 4, 5 };
	list.push_front(66);
	list.push_back(55);
	for (int element : list)
	{
		std::cout << element << std::endl;
	}

	// STL-Контейнер для строк (тема обсуждения следующего занятия)
	std::string hello = "Hello world";
	
	double half = 0.333333;
	FractionClass h1 = FractionClass { 5, 10 };
	FractionClass h3;
	try {
		 h3 = FractionClass{ 1, 0 };
	} catch (const std::exception& error) {
		std::cout << error.what() << std::endl;
		return -3;
	}
	
	double d1 = 5.0 / 10.0;
	double d2;
	double d3;

	// Объявляем секцию в коротой потенциально может возникнуть исключительная ситуация.
	try {
		std::cin >> d2;
		if (d2 == 0) {
			// Оператор throw - генерирует (выбрасывает) ошибку о возникшей исключительной ситуации.
			// std::exception - Специальный класс для передачи информации о возникшей ошибке.
			throw std::exception("Division by zero is forbidden");
		}
		if (d2 < 0)
		{
			// throw std::exception("Number should be positive");
			throw "Number should be positive";
		}
		// Объявляем секцию в которой будет происходить обработка исключительных ситуаций унаследовнных от типа std::exception
	} catch (const std::exception& error) {
		std::cout << error.what() << std::endl;
		return -1;
	} catch (const char* error)	{
		std::cout << error << std::endl;
		return -2;
	}
}
