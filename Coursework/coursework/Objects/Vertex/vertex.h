#ifndef VERTEX_H
#define VERTEX_H

#include "Objects/Point/point.h"
#include "Objects/Vector/vector.h"

class Vertex
{
public:
    Vertex();

    virtual ~Vertex();

    Point pnt;
    Vector vect;
};

#endif // VERTEX_H
