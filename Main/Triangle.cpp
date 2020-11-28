#include "Triangle.h"
#include <iostream>

Triangle::Triangle(const Point& x, const Point& y, const Point& z)
{
	this->points = new Point[3] { x, y, z };
}

Triangle::Triangle(const Triangle& t)
{
	this->points = new Point[3] { t.points[0], t.points[1], t.points[2] };
}

void Triangle::print()
{
	for (int i = 0; i <= 2; i++) {
		std::cout << "Point #" << (i + 1) << std::endl
			<< ": X=" << this->points[i].x << std::endl
			<< ": Y=" << this->points[i].y << std::endl;
		std::cout << std::endl;
	}
}

void Triangle::printPoint(const Point& p)
{
	std::cout << "X=" << p.x << std::endl;
	std::cout << "Y=" << p.y << std::endl;
}
