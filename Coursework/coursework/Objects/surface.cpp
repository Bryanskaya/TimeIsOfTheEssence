#include "surface.h"

//constructors and destructor
Surface::Surface() {}

Surface::Surface(double data_a, double data_b, double data_c, double data_d) :
    a(data_a), b(data_b), c(data_c), d(data_d) {}

Surface::~Surface() {}


//methonds
void Surface::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *Surface::clone()
{
    return new Surface(*this);
}
