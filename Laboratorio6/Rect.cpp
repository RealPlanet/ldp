#include "Rect.h"

std::string Rect::what_shape() const
{
    return "Square";
}

double Rect::perimeter() const
{
    return 2 * b_side + 2 * h_side;
}

double Rect::area() const
{
    return b_side * h_side;
}