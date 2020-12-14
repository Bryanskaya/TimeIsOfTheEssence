#ifndef BOX_H
#define BOX_H

#include "Primitives/Model/model.h"

class Box : public Model
{
public:
    Box(const Point& pnt1, const Point& pnt2, QRgb color);

    virtual ~Box();

    Point find_min_pnt(const Point& pnt1, const Point& pnt2);
    Point find_max_pnt(const Point& pnt1, const Point& pnt2);
    void add_points_row(const Point& pnt_min, double step, int num);
    void create_polygons(int num, int i);

private:
    QRgb _color;
    double _step = 30;

    void _find_center(const Point& pnt1, const Point& pnt2);
};



#endif // BOX_H
