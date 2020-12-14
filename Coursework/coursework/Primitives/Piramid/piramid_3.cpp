#include "piramid_3.h"


Piramid_3::Piramid_3(const Point& pnt1, const Point& pnt2, const Point& pnt3, const Point& pnt_top, QRgb color) :
    _color(color)
{
    _center = Point((pnt1.x + pnt2.x + pnt3.x + pnt_top.x) / 4,
                    (pnt1.y + pnt2.y + pnt3.y + pnt_top.y) / 4,
                    (pnt1.z + pnt2.z + pnt3.z + pnt_top.z) / 4);

    add_vertex(pnt1);
    add_vertex(pnt2);
    add_vertex(pnt3);
    add_vertex(pnt_top);

    add_side({1, 2, 3}, color);  // Правая боковая грань
    add_side({2, 0, 3}, color);  // Левая боковая грань
    add_side({0, 1, 3}, color);  // Лицевая грань
    add_side({0, 1, 2}, color);  // Дно

    normalize_n_vrt();
}

Piramid_3::~Piramid_3() {}
