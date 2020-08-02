#include "vector.h"

//constructors and destructor
Vector::Vector() {}

Vector::~Vector() {}

Vector::Vector(double data_x, double data_y, double data_z) :
    x(data_x), y(data_y), z(data_z) {}

Vector::Vector(const Vector& other) :
    x(other.x), y(other.y), z(other.z) {}

Vector::Vector(const Point &begin_pnt, const Point &end_pnt)
{
    x = end_pnt.x - begin_pnt.x;
    y = end_pnt.y - begin_pnt.y;
    z = end_pnt.z - begin_pnt.z;
}


//methonds
double Vector::get_length() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector::normalize()
{
    double len = this->get_length();

    if (len < EPS)
        throw error::InvalidOperation(__FILE__, typeid (*this).name(), __LINE__ - 1);

    x /= len;
    y /= len;
    z /= len;
}

void Vector::invert()
{
    x = -x;
    y = -y;
    z = -z;
}

double Vector::scalar_mult(const Vector &other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector Vector::vect_mul(const Vector &v1, const Vector &v2) const
{
    Vector result;

    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;

    return result;
}


//operators
Vector Vector::operator+(const Vector &other)
{
    Vector result;

    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + other.z;

    return result;
}

void Vector::operator+=(const Vector &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}
