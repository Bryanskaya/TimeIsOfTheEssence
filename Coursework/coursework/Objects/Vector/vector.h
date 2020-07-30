#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

#define     EPS     1e-5

class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);

    virtual ~Vector();

    double x;
    double y;
    double z;

    double get_length() const;
    void normalize();


};

#endif // VECTOR_H
