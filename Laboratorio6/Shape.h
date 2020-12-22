#pragma once
#include <string>

struct Color {
	double r;
	double g;
	double b;

	Color(double _r, double _g, double _b) : r( _r ), g{ _g }, b{ _b } {}
};

class Shape
{
private:
	Color shapeColor;
public:

	virtual std::string what_shape() = 0;
	virtual double perimeter() = 0;
	virtual double area() = 0;
};

