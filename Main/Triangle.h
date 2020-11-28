#pragma once
#include "Point.h"

class Triangle
{
public:
	Triangle(const Point&, const Point&, const Point& = Point(0, 0));
	Triangle(const Triangle&);
	void print();
	void printPoint(const Point&);
private:
	Point* points;
};
