#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(double x, double y, double z);

    virtual ~Point();

    double x;
    double y;
    double z;
};

#endif // POINT_H
