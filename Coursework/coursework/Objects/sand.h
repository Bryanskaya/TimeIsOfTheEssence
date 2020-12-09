#ifndef SAND_H
#define SAND_H

#include <vector>

#include "simple_object.h"
#include "Errors/hourglass_error.h"
#include "Primitives/Piramid/piramid.h"
#include "Primitives/Surface/surface.h"


class Sand : public VisibleObject
{
public:
    Model model_up;
    Model surf_up;
    Model model_down;
    Model surf_down;
    vector<Model> models_arr;

    Sand();

    virtual ~Sand();

    void create_topsurface(int x_start, int x_end, int z_start, int z_end, int sand_level, QRgb color);

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();

private:
    double _speed_y = 10;

    void _add_vertices_line(int x, int y, int z, size_t step, size_t num);
};

class SandUpP : public VisibleObject
{
public:
    SandUpP(const Point& pnt1, const Point& pnt2);
    explicit SandUpP(const SandUpP& other);

    virtual ~SandUpP();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    double _down_length = 140;
    double _up_length = 2;
};


class SandUpS : public VisibleObject
{
public:
    SandUpS(const Point& pnt1, const Point& pnt2);
    explicit SandUpS(const SandUpS& other);

    virtual ~SandUpS();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    double _length;
};

#endif // SAND_H
