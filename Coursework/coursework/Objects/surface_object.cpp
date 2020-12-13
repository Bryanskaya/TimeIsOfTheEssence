#include "surface_object.h"
#include "Visitors/object_visitor.h"

SurfaceObject::SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3, bool up_part)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    _limit_y = pnt1.y;

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

double func(double x, double z, double t, double h)
{
    double k = pow(h / 100, 1.5) * h * 0.075;
    return exp(-pow(pow(x, 2) + pow(z, 2), 2) / 10) * t;
}

void SurfaceObject::update(double t_cur, double dt, double t_limit)
{
    double dh, k;

    if (t_cur < TIME_HILL * t_limit)
    {
        //k = pow(t_cur, -2) * 0.1;//pow(60/t_limit, 3);
        k = t_cur / _limit_y * 2;
        for (size_t i = 0; i < _model->v_arr.size() - 8; i++)
             _model->v_arr[i]->y = _limit_y - func(_model->v_arr[i]->x, _model->v_arr[i]->z, k, _limit_y);
    }
    else
    {
        dh = pow(_limit_y, 3) / (3 * pow(_model->v_arr[0]->y, 2)) * dt / (t_limit * (1 - TIME_HILL - DTIME));
        k = 1 - dh / (_model->v_arr[0]->y + 124/70);

        Scale scl(Vector(k, k, k), Point(0, -124/70, 0));
        for (size_t i = 0; i < _model->v_arr.size() - 8; i++)
             scl.execute(*_model->v_arr[i]);
    }

}

void SurfaceObject::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* SurfaceObject::clone()
{
    return new SurfaceObject(*this);
}
