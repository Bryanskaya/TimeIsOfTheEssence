#include "piramid.h"

#include <iostream>
using namespace std;

Piramid::Piramid(const Point& pnt1, const Point& pnt2, QRgb color, double down_length, double up_length) :
    _color(color)
{
    _center = Point(pnt2.x, (pnt1.y + pnt2.y) / 2 , pnt2.z);

    add_vertex(pnt1);
    add_vertex(Point(pnt1.x, pnt1.y, pnt1.z - down_length));
    add_vertex(Point(pnt1.x + down_length, pnt1.y, pnt1.z - down_length));
    add_vertex(Point(pnt1.x + down_length, pnt1.y, pnt1.z));

    /*add_vertex(Point((pnt1.x + pnt2.x) / 2, (pnt1.y + pnt2.y) / 2, (pnt1.z + pnt2.z) / 2));
    add_vertex(Point((pnt1.x + pnt2.x) / 2, (pnt1.y + pnt2.y) / 2, (pnt1.z - down_length + pnt2.z - up_length) / 2));
    add_vertex(Point((pnt1.x + down_length + pnt2.x + up_length) / 2, (pnt1.y + pnt2.y) / 2, (pnt1.z - down_length + pnt2.z - up_length) / 2));
    add_vertex(Point((pnt1.x + down_length + pnt2.x + up_length) / 2, (pnt1.y + pnt2.y) / 2, (pnt1.z + pnt2.z) / 2));*/

    add_vertex(pnt2);
    add_vertex(Point(pnt2.x, pnt2.y, pnt2.z - up_length));
    add_vertex(Point(pnt2.x + up_length, pnt2.y, pnt2.z - up_length));
    add_vertex(Point(pnt2.x + up_length, pnt2.y, pnt2.z));

    add_side({1, 5, 6, 2}, color);  // Задняя грань
    add_side({0, 4, 5, 1}, color);  // Левая боковая грань
    add_side({2, 6, 7, 3}, color);  // Правая боковая грань
    add_side({0, 4, 7, 3}, color);  // Лицевая грань

    /*add_side({5, 9, 10, 6}, color);
    add_side({4, 8, 9, 5}, color);
    add_side({6, 10, 11, 7}, color);
    add_side({4, 8, 11, 7}, color);*/


    /*add_vertex(pnt1);
    add_vertex(Point(pnt1.x, pnt1.y, pnt1.z - down_length));
    add_vertex(Point(pnt1.x + down_length, pnt1.y, pnt1.z - down_length));
    add_vertex(Point(pnt1.x + down_length, pnt1.y, pnt1.z));

    add_vertex(pnt2);
    add_vertex(Point(pnt2.x, pnt2.y, pnt2.z - up_length));
    add_vertex(Point(pnt2.x + up_length, pnt2.y, pnt2.z - up_length));
    add_vertex(Point(pnt2.x + up_length, pnt2.y, pnt2.z));

    add_side({1, 5, 6, 2}, color);  // Задняя грань
    add_side({0, 4, 5, 1}, color);  // Левая боковая грань
    add_side({2, 6, 7, 3}, color);  // Правая боковая грань
    add_side({0, 4, 7, 3}, color);  // Лицевая грань*/

    normalize_n_vrt();
}

Piramid::~Piramid() {}
