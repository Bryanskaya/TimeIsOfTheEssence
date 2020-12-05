#include "glass.h"
#include "Visitors/object_visitor.h"


//constructors and destructor
Glass::Glass(const Point& pnt1, const Point& pnt2)
{
    _color = QColor(Qt::lightGray).rgba();

    Model* model_ptr = new Piramid(pnt1, pnt2, _color);
    _model = shared_ptr<Model>(model_ptr);
}

Glass::Glass(const Glass& other) : VisibleObject(other)
{
    _color = other._color;
}

Glass::~Glass() {}


//methonds
void Glass::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Glass::clone()
{
    return new Glass(*this);
}
