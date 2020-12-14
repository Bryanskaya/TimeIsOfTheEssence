#include "box.h"

#include <iostream>
using namespace std;

Box::Box(const Point& pnt1, const Point& pnt2, QRgb color) :
    _color(color)
{
    Point pnt_min = find_min_pnt(pnt1, pnt2);
    Point pnt_max = find_max_pnt(pnt1, pnt2);

    _find_center(pnt1, pnt2);

    size_t num_x = static_cast<int>(round((pnt_max.x - pnt_min.x) / _step));
    size_t num_z = static_cast<int>(round((pnt_max.z - pnt_min.z) / _step));

    double step_x = (pnt_max.x - pnt_min.x) / num_x;
    double step_z = (pnt_max.z - pnt_min.z) / num_z;

    Point pnt = pnt_min;
    add_points_row(pnt, step_z, num_z);

    for (size_t i = 0; i < num_x; i++)
    {
        pnt.x += step_x;

        add_points_row(pnt, step_z, num_z);
        create_polygons(num_z, i);
    }

    pnt = pnt_min;
    pnt.y = pnt_max.y;
    add_points_row(pnt, step_z, num_z);

    for (size_t i = 0; i < num_x; i++)
    {
        pnt.x += step_x;

        add_points_row(pnt, step_z, num_z);
        create_polygons(num_z, i + num_x + 1);
    }








    //Нижняя грань
    /*add_vertex(pnt1);   //Ближайшая к наблюдателю слева снизу
    add_vertex(Point(pnt1.x, pnt1.y, pnt2.z));
    add_vertex(Point(pnt2.x, pnt1.y, pnt2.z));
    add_vertex(Point(pnt2.x, pnt1.y, pnt1.z));

    //Верхняя грань
    add_vertex(Point(pnt1.x, pnt2.y, pnt1.z));
    add_vertex(Point(pnt1.x, pnt2.y, pnt2.z));
    add_vertex(pnt2);
    add_vertex(Point(pnt2.x, pnt2.y, pnt1.z));

    add_side({0, 1, 2, 3}, color);  //Нижняя грань
    add_side({4, 5, 6, 7}, color);  //Верхняя грань

    add_side({0, 4, 7, 3}, color);  //Лицевая
    add_side({0, 4, 5, 1}, color);  //Левая
    add_side({1, 5, 6, 2}, color);  //Задняя
    add_side({3, 7, 6, 2}, color); */ //Правая

    normalize_n_vrt();
}

Box::~Box() {}


void Box::_find_center(const Point &pnt1, const Point &pnt2)
{
    _center.x = (pnt1.x + pnt2.x) / 2;
    _center.y = (pnt1.y + pnt2.y) / 2;
    _center.z = (pnt1.z + pnt2.z) / 2;
}

Point Box::find_min_pnt(const Point& pnt1, const Point& pnt2)
{
    Point result;

    result.x = min(pnt1.x, pnt2.x);
    result.y = min(pnt1.y, pnt2.y);
    result.z = min(pnt1.z, pnt2.z);

    return result;
}

Point Box::find_max_pnt(const Point& pnt1, const Point& pnt2)
{
    Point result;

    result.x = max(pnt1.x, pnt2.x);
    result.y = max(pnt1.y, pnt2.y);
    result.z = max(pnt1.z, pnt2.z);

    return result;
}

void Box::add_points_row(const Point& pnt_min, double step, int num)
{
    Point pnt = pnt_min;

    for (int i = 0; i < num + 1; i++)
    {
        add_vertex(pnt);
        pnt.z += step;
    }
}

void Box::create_polygons(int num, int cur_i)
{
    size_t p1 = cur_i * (num + 1);
    size_t p2 = cur_i * (num + 1) + 1;
    size_t p3 = (cur_i + 1) * (num + 1) + 1;
    size_t p4 = (cur_i + 1) * (num + 1);

    for (int i = 0; i < num; i++)
    {
        add_side({ p1, p2, p3, p4 }, _color);

        p1 += 1;
        p2 += 1;
        p3 += 1;
        p4 += 1;
    }
}
