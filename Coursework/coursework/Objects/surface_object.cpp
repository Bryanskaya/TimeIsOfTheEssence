#include "surface_object.h"
#include "Visitors/object_visitor.h"

SurfaceObject::SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3, bool up_part)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    _limit_y = pnt1.y;
    _is_up_part = up_part;

    Model* model_ptr;

    if (up_part)
        model_ptr = new SurfaceUp(_color, pnt1, pnt2, pnt3);
    else
        model_ptr = new SurfaceDown(_color, pnt1, pnt2);

    _model = shared_ptr<Model>(model_ptr);
}

SurfaceObject::SurfaceObject(const SurfaceObject& other) : VisibleObject(other)
{
    _color = other._color;
}

SurfaceObject::~SurfaceObject() {}

double func_up(double x, double z, double t, double h)
{
    double k = pow(h / 100, 1.5) * h * 0.16; //0.095
    return exp(-pow(pow(x / k, 2) + pow(z / k, 2), 2) / 10) / t; // /k  *t
}

double func_down(double x, double z, double t, double h)
{
    h = abs(h);
    //double k = 55;
    double k = 55;
    return exp(-pow(pow(x / k, 2) + pow(z / k, 2), 2) / 5) / t;
}

void SurfaceObject::update(double t_cur, double dt, double t_limit)
{
    if (_is_up_part)
        update_up(t_cur, dt, t_limit);
    else
        update_down(t_cur, dt, t_limit);
}

void SurfaceObject::update_up(double t_cur, double dt, double t_limit)
{
    double dh, k;

    if (t_cur < TIME_HILL * t_limit)
    {
        k = pow(t_cur, -1.5) * 2;//pow(50/t_limit, 2);
        //k = t_cur / _limit_y * 2;
        for (size_t i = 0; i < _model->v_arr.size() - 8; i++)
             _model->v_arr[i]->y = _limit_y - func_up(_model->v_arr[i]->x, _model->v_arr[i]->z, k, _limit_y);
        _model->get_center().y = (_limit_y - func_up(0, 0, k, _limit_y)) / 2;
        //cout << "**** " << _model->get_center().y << endl;

        _model->correct_n();
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

void SurfaceObject::update_down(double t_cur, double dt, double t_limit)
{
    double k = pow(t_cur + 4, -0.8) * 0.75;

    for (size_t i = 0; i < _model->v_arr.size(); i++)
        _model->v_arr[i]->y = _limit_y + func_down(_model->v_arr[i]->x, _model->v_arr[i]->z, k, _limit_y);

    _model->correct_n();
}

bool SurfaceObject::get_status_part()
{
    return _is_up_part;
}

void SurfaceObject::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* SurfaceObject::clone()
{
    return new SurfaceObject(*this);
}
