#ifndef VERTEX_H
#define VERTEX_H

#include "Primitives/Point/point.h"
#include "Primitives/Vector/vector.h"

class Vertex : public Point
{
public:
    Vector n;

    Vertex();
    Vertex(double data_x, double data_y, double data_z);
    Vertex(const Point& other);
    Vertex(const Vertex& other);

    virtual ~Vertex();
};

#endif // VERTEX_H
