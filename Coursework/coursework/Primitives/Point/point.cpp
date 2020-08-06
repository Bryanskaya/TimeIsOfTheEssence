#include "point.h"

Point::Point() {}

Point::~Point() {}

Point::Point(double data_x, double data_y, double data_z) :
    x(data_x), y(data_y), z(data_z) {}

Point::Point(const Point& other) :
    x(other.x), y(other.y), z(other.z) {}

void Point::operator=(const Point &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

