#pragma once
#include <string>
class Shape
{
public:
	virtual std::string what_shape() const= 0;
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

