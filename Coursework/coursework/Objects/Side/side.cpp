#include "side.h"

Side::Side() {}

Side::~Side() {}


void Side::n_correction(const Point &control_p)
{
    Vector temp(control_p, *vertex_arr[0]);

    if (n.scalar_mult(temp) < 0)
        n.invert();
}


void Side::_find_normal()
{
    Vertex p1 = *vertex_arr[0];
    Vertex p2 = *vertex_arr[1];
    Vertex p3 = *vertex_arr[2];

    n.x = (p2.y - p1.y)*(p3.z - p1.z) - (p3.y - p1.y)*(p2.z - p1.z);
    n.y = (p3.x - p1.x)*(p2.z - p1.z) - (p2.x - p1.x)*(p3.z - p1.z);
    n.z = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);

    n.normalize();
}
