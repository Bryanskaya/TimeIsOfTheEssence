#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <ostream>

#include "Errors/vector_errors.h"
#include "Objects/Point/point.h"

#define     EPS     1e-5

class Vector
{
public:
    double x, y, z;

    Vector();
    Vector(double data_x, double data_y, double data_z);
    Vector(const Vector& other);
    Vector(const Point& begin_pnt, const Point& end_pnt);

    virtual ~Vector();


    double get_length() const;
    void normalize();
    void invert();
    double scalar_mult(const Vector& other);
    Vector vect_mul(const Vector& v1, const Vector& v2) const;

    Vector operator +(const Vector& other);
    void operator +=(const Vector& other);
};

#endif // VECTOR_H
