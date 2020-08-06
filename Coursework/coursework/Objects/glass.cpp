#include "glass.h"

//constructors and destructor
Glass::Glass() {}

Glass::~Glass() {}


//methonds
void Glass::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *Glass::clone()
{
    return new Glass(*this);
}
