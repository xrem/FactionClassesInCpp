#pragma once
// #include "Triangle.h"

class Point
{
public:
	Point(double x, double y);
private:
	double x;
	double y;

	friend class Triangle;
	// friend void Triangle::printPoint(const Point&);
};
