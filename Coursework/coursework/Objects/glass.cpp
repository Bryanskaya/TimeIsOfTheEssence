#include "glass.h"
#include "Visitors/object_visitor.h"


//constructors and destructor
Glass::Glass(const Point& pnt1, const Point& pnt2)
{
    _color = QColor(Qt::green).rgba();

    Model* model_ptr = new Piramid(pnt1, pnt2, _color);
    _model = shared_ptr<Model>(model_ptr);
}

Glass::Glass(const Glass& other) : VisibleObject(other)
{
    _color = other._color;
    _tr = other._tr;
}

Glass::~Glass() {}

double Glass::get_transparency()
{
    return _tr;
}

//methonds
void Glass::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Glass::clone()
{
    return new Glass(*this);
}
