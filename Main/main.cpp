#include <iostream>

#include "FractionClass.h"
#include "Point.h"
#include "Triangle.h"


void main()
{

	double half = 0.333333;
	FractionClass h1 = FractionClass { 5, 10 };
	FractionClass h3 = half; // Implicit
	h3.print();
	std::cout << h3 << std::endl;
	
	/*
	double x1, x2, x3;
	double y1, y2, y3;
	std::cin >> x1;
	std::cin >> y1;
	std::cin >> x2;
	std::cin >> y2;
	std::cin >> x3;
	std::cin >> y3;
	Triangle m = { Point(x1, y1), Point(x2, y2), Point(x3, y3) };
	Triangle n = { Point(x2, y2), Point(x3, y3) };
	Triangle z = Triangle(n);
	
	
	m.print();
	n.print();
	*/
}
