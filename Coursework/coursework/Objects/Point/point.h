#ifndef POINT_H
#define POINT_H

class Point
{
public:
    double x, y, z;

    Point();
    Point(double x, double y, double z);
    Point(const Point& other);

    virtual ~Point();
};

#endif // POINT_H
