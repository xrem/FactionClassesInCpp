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
	// STL-����������. 
	// vector - ������ � ����������� ���������� ��������.


	// T<> - �������� ��� ��������� �������/������/������
	// <int> - ������� ��������� ��� �����
	// { � ����������� } ������� ����� ����� ������� ����� ���������� ����������� � ���������� 
	std::vector<int> vectorInteger;
	// ���������� ��������� �������� � ��� ��������� � ����������� ��� ������ (�����)
	vectorInteger.push_back(1);
	vectorInteger.push_back(2);
	vectorInteger.push_back(3333);
	vectorInteger.push_back(3);
	vectorInteger.push_back(4);
	vectorInteger.push_back(5555);
	vectorInteger.push_back(5);
	vectorInteger.push_back(6);

	swap(vectorInteger, 2, 5);
	
	// vector.size() -> ����� ����������� ��������� ����� �����������.
	for (int i = 0; i < vectorInteger.size(); i++)
	{
		std::cout << vectorInteger[i] << std::endl;
	}	

	// ��� �� ����� ���� ����, ��� ������ ��������� ����������, � �������������� ����� for each
	// � ����� ���������� ������ �������� �� ������ ����������.
	for (int element : vectorInteger)
	{
		std::cout << element << std::endl;
	}

	// STL-��������� Array - ������ ��� �������� ������� � ������������� ������.
	int arr[5] = { 1, 2, 3, 4, 5 };
	std::array<int, 5> fixed_array = { 1, 2, 3, 4, 5 };
	std::cout << fixed_array.size() << std::endl;
	for (int element : fixed_array)
	{
		std::cout << element << std::endl;
	}

	// STL-��������� ����������� ����, ��������� ��������� �������� ������ � ����� ������� �����
	std::cout << "----------Forward list----------" << std::endl;
	std::forward_list<int> forward_list = { 1, 2, 3, 4, 5 };
	forward_list.push_front(55);
	forward_list.push_front(66);
	for (int element : forward_list)
	{
		std::cout << element << std::endl;
	}

	// STL-��������� ����������� ���� (��������� ������ ������ ��� �� ��������� �������, ��� � �� ����������)
	std::cout << "------------- List -------------" << std::endl;
	std::list<int> list = { 1, 2, 3, 4, 5 };
	list.push_front(66);
	list.push_back(55);
	for (int element : list)
	{
		std::cout << element << std::endl;
	}

	// STL-��������� ��� ����� (���� ���������� ���������� �������)
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

	// ��������� ������ � ������� ������������ ����� ���������� �������������� ��������.
	try {
		std::cin >> d2;
		if (d2 == 0) {
			// �������� throw - ���������� (�����������) ������ � ��������� �������������� ��������.
			// std::exception - ����������� ����� ��� �������� ���������� � ��������� ������.
			throw std::exception("Division by zero is forbidden");
		}
		if (d2 < 0)
		{
			// throw std::exception("Number should be positive");
			throw "Number should be positive";
		}
		// ��������� ������ � ������� ����� ����������� ��������� �������������� �������� ������������� �� ���� std::exception
	} catch (const std::exception& error) {
		std::cout << error.what() << std::endl;
		return -1;
	} catch (const char* error)	{
		std::cout << error << std::endl;
		return -2;
	}
}
