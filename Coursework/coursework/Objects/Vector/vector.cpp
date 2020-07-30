#include "vector.h"

Vector::Vector() {}

Vector::~Vector() {}

Vector::Vector(double data_x, double data_y, double data_z) :
    x(data_x), y(data_y), z(data_z) {}


double Vector::get_length() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector::normalize()
{
    double len = get_length();

    /*if (len < EPS)
        throw ErrorInvalidOperation(__FILE__, typeid (*this).name(), __LINE__ - 1);*/

    x /= len;
    y /= len;
    z /= len;
}
