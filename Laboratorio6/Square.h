#pragma once
#include "Shape.h"
class Square : public Shape
{
private:
	double l_side; //Lenght of one side
public:
	Square(double sideLenght) : l_side{ sideLenght } {};
	std::string what_shape() const override;
	double perimeter() const override;
	double area() const override;
};

