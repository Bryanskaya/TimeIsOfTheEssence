#include "sand.h"

//constructors and destructor
Sand::Sand() {}

Sand::~Sand() {}


//methonds
void Sand::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *Sand::clone()
{
    return new Sand(*this);
}
