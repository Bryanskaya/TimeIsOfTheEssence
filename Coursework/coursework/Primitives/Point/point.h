#ifndef POINT_H
#define POINT_H

#define    PI    3.1415

#include <cmath>
#include <iostream>

using namespace std;


class Vector;

class Point
{
public:
    double x, y, z;

    Point();
    Point(double x, double y, double z);
    Point(const Point& other);

    virtual ~Point();

    void operator =(const Point& other);

    double to_radians(double angle);
    void rotate(const Point& center, const Vector& angles);
    void invert_rotate(const Point &center, const Vector &angles);

    void rotate_ox(const Point& center, double k);
    void rotate_oy(const Point& center, double k);
    void rotate_oz(const Point& center, double k);
};

#endif // POINT_H
