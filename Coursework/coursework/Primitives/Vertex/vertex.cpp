#include "vertex.h"

Vertex::Vertex() {}

Vertex::~Vertex() {}

Vertex::Vertex(double data_x, double data_y, double data_z) :
    Point(data_x, data_y, data_z) {}

Vertex::Vertex(const Point& other) :
    Point(other) {}

Vertex::Vertex(const Vertex& other) :
    Point(other), n(other.n) {}


bool Vertex::operator==(const Vertex &other)
{
    if (fabs(this->x - other.x) > EPS)  return false;
    if (fabs(this->y - other.y) > EPS)  return false;
    if (fabs(this->z - other.z) > EPS)  return false;

    return true;
}
