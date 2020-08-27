#include "stand.h"
#include "Visitors/object_visitor.h"


//constructors and destructor
Stand::Stand(double x, double y, double z)
{
    //_color = QColor(Qt::darkRed).rgba();
    _color = QColor(Qt::yellow).rgba();

    Point pnt1(x, y, z);
    Point pnt2(x + _length, y + _height, z - _length);

    Model* model_ptr = new Box(pnt1, pnt2, _color);
    _model = shared_ptr<Model>(model_ptr);
}

Stand::Stand(const Stand& other) : VisibleObject(other)
{
    _color = other._color;
}

Stand::~Stand() {}


//methonds
void Stand::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Stand::clone()
{
    return new Stand(*this);
}
