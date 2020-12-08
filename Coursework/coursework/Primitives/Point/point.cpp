#include "point.h"
#include "Primitives/Vector/vector.h"


Point::Point() :
    x(0), y(0), z(0) {}

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

double Point::to_radians(double angle)
{
    return angle * PI / 180;
}

void Point::rotate(const Point &center, const Vector &angles)
{
    rotate_oy(center, angles.y);
    rotate_ox(center, angles.x);
    rotate_oz(center, angles.z);
}

void Point::rotate_ox(const Point &center, double angle)
{
    double y_temp, z_temp;

    y_temp = center.y + (this->y - center.y) * cos(angle) + (this->z - center.z) * sin(angle);
    z_temp = center.z + (this->z - center.z) * cos(angle) - (this->y - center.y) * sin(angle);

    this->y = y_temp;
    this->z = z_temp;
}

void Point::rotate_oy(const Point &center, double angle)
{
    double x_temp, z_temp;

    x_temp = center.x + (this->x - center.x) * cos(angle) - (this->z - center.z) * sin(angle);
    z_temp = center.z + (this->z - center.z) * cos(angle) + (this->x - center.x) * sin(angle);

    this->x = x_temp;
    this->z = z_temp;
}

void Point::rotate_oz(const Point &center, double angle)
{
    double x_temp, y_temp;

    x_temp = center.x + (this->x - center.x) * cos(angle) + (this->y - center.y) * sin(angle);
    y_temp = center.y + (this->y - center.y) * cos(angle) - (this->x - center.x) * sin(angle);

    this->x = x_temp;
    this->y = y_temp;
}
