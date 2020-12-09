#include "surface_object.h"
#include "Visitors/object_visitor.h"

SurfaceObject::SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3, bool up_part)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    Model* model_ptr;

    if (up_part)
    {
        cout << "true" << endl;
        model_ptr = new SurfaceUp(_color, pnt1, pnt2, pnt3);
    }
    else
    {
        cout << "false" << endl;
        //model_ptr = new SurfaceUp(_color, pnt1, pnt2);
        /*Model* model_ptr = new SurfaceDown(_color, pnt1, pnt2);*/
    }

    _model = shared_ptr<Model>(model_ptr);
}

SurfaceObject::SurfaceObject(const SurfaceObject& other) : VisibleObject(other)
{
    _color = other._color;
}

SurfaceObject::~SurfaceObject() {}

void SurfaceObject::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* SurfaceObject::clone()
{
    return new SurfaceObject(*this);
}
