#include "transformation.h"


Transformation::Transformation() {}

Transformation::~Transformation() {}


Move::Move(double dx, double dy, double dz) :
    _dir(Vector(dx, dy, dz)) {}

Move::Move(const Vector& vect) :
    _dir(vect) {}

Move::~Move() {}


void Move::execute(double &x, double &y, double &z)
{
    x += _dir.x;
    y += _dir.y;
    z += _dir.z;
}

void Move::execute(Point &pnt)
{
    pnt.x += _dir.x;
    pnt.y += _dir.y;
    pnt.z += _dir.z;
}

void Move::execute(Vertex &vertex)
{
    vertex.x += _dir.x;
    vertex.y += _dir.y;
    vertex.z += _dir.z;
}

void Move::execute(Camera &camera)
{
    execute(camera.get_position());
}


Rotate::Rotate(const Vector& vect, const Point& pnt) :
    _center(pnt)
{
    _dir.x = _to_radians(vect.x);
    _dir.y = _to_radians(vect.y);
    _dir.z = _to_radians(vect.z);
}

Rotate::Rotate(const Vector& vect) :
    _center()
{
    _dir.x = _to_radians(vect.x);
    _dir.y = _to_radians(vect.y);
    _dir.z = _to_radians(vect.z);
}

Rotate::~Rotate() {}


double Rotate::_to_radians(double angle)
{
    return angle * PI / 180;
}

void Rotate::execute(double &x, double &y, double &z)
{
    rotate_x(x, y, z);
    rotate_y(x, y, z);
    rotate_z(x, y, z);
}

void Rotate::execute(Point &pnt)
{
    rotate_x(pnt.x, pnt.y, pnt.z);
    rotate_y(pnt.x, pnt.y, pnt.z);
    rotate_z(pnt.x, pnt.y, pnt.z);
}

void Rotate::execute(Vertex &vertex)
{
    rotate_x(vertex.x, vertex.y, vertex.z);
    rotate_y(vertex.x, vertex.y, vertex.z);
    rotate_z(vertex.x, vertex.y, vertex.z);
}

void Rotate::execute(Vector& vect)
{
    rotate_x(vect.x, vect.y, vect.z);
    rotate_y(vect.x, vect.y, vect.z);
    rotate_z(vect.x, vect.y, vect.z);
}

void Rotate::execute(Camera &camera)
{
    execute(camera.get_direction());
}

void Rotate::rotate_x(double&, double &y, double &z)
{
    double y_temp, z_temp;

    y_temp = _center.y + (y - _center.y) * cos(_dir.x) + (_center.z - z) * sin(_dir.x);
    z_temp = _center.z + (z - _center.z) * cos(_dir.x) - (_center.y - y) * sin(_dir.x);

    y = y_temp;
    z = z_temp;
}

void Rotate::rotate_y(double &x, double&, double &z)
{
    double x_temp, z_temp;

    x_temp = _center.x + (x - _center.x) * cos(_dir.y) + (z - _center.z) * sin(_dir.y);
    z_temp = _center.z + (z - _center.z) * cos(_dir.y) + (_center.x - x) * sin(_dir.y);

    x = x_temp;
    z = z_temp;
}

void Rotate::rotate_z(double &x, double &y, double&)
{
    double x_temp, y_temp;

    x_temp = _center.x + (x - _center.x) * cos(_dir.z) + (y - _center.y) * sin(_dir.z);
    y_temp = _center.y + (y - _center.y) * cos(_dir.z) + (_center.x - x) * sin(_dir.z);

    x = x_temp;
    y = y_temp;
}


Scale::Scale(const Vector& vect, const Point& pnt) :
    _dir(vect), _center(pnt) {}

Scale::Scale(const Vector& vect) :
    _dir(vect), _center() {}

Scale::~Scale() {}


void Scale::execute(double &x, double &y, double &z)
{
    x = _dir.x * (x - _center.x) + _center.x;
    y = _dir.y * (y - _center.y) + _center.y;
    z = _dir.z * (z - _center.z) + _center.z;
}

void Scale::execute(Point &pnt)
{
    pnt.x = _dir.x * (pnt.x - _center.x) + _center.x;
    pnt.y = _dir.y * (pnt.y - _center.y) + _center.y;
    pnt.z = _dir.z * (pnt.z - _center.z) + _center.z;
}

void Scale::execute(Vertex &vertex)
{
    vertex.x = _dir.x * (vertex.x - _center.x) + _center.x;
    vertex.y = _dir.y * (vertex.y - _center.y) + _center.y;
    vertex.z = _dir.z * (vertex.z - _center.z) + _center.z;

    execute(vertex.n);
}

void Scale::execute(Vector &vect)
{
    vect.x *= _dir.x;
    vect.y *= _dir.y;
    vect.z *= _dir.z;
}

void Scale::execute(Camera &camera)
{
    execute(camera.get_position());
}
