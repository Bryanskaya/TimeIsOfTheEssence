#include "vertex.h"

Vertex::Vertex() {}

Vertex::~Vertex() {}

Vertex::Vertex(double data_x, double data_y, double data_z) :
    Point(data_x, data_y, data_z) {}

Vertex::Vertex(const Point& other) :
    Point(other) {}

Vertex::Vertex(const Vertex& other) :
    Point(other), n(other.n) {}
