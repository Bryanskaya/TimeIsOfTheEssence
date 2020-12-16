#ifndef SURFACE_H
#define SURFACE_H

#include "Primitives/Model/model.h"

class Surface : public Model
{
public:
    Surface(QRgb color);

    virtual ~Surface();

    Point find_min_pnt(const Point& pnt1, const Point& pnt2);
    Point find_max_pnt(const Point& pnt1, const Point& pnt2);
    void find_center(const Point& pnt1, const Point& pnt2);

protected:
    QRgb _color;
};


class SurfaceUp : public Surface
{
public:
    SurfaceUp(QRgb color, const Point& pnt1, const Point& pnt2, const Point& pnt3);

    virtual ~SurfaceUp();

    void add_carcas(const Point& pnt1, const Point& pnt2);
    void add_points_row(const Point& pnt_min, double step, int num);
    void create_polygons(int num, int i);
    void find_center(const Point& pnt1, const Point& pnt2);
    void correct_vert(size_t ind);

private:
    double _step = 30; //50
    size_t _num_nodes;
    double _down_length = 140;
    double _up_length = 2;
    double _height;

    double _cur_length = 140;
};


class SurfaceDown : public Surface
{
public:
    SurfaceDown(QRgb color, const Point& pnt1, const Point& pnt2);

    virtual ~SurfaceDown();

    void add_points_row(const Point& pnt_min, double step, int num);
    void create_polygons(int num, int i);
    void find_center(const Point& pnt);
    void correct_vert(size_t ind);

private:
    double _step = 20; //50
    size_t _num_nodes;
    double _down_length = 140;

    double _cur_length = 140;
};

#endif // SURFACE_H
