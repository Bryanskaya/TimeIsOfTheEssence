#include "box.h"

#include <iostream>
using namespace std;

Box::Box(const Point& pnt1, const Point& pnt2, QRgb color) :
    _color(color)
{
    //Нижняя грань
    add_vertex(pnt1);   //Ближайшая к наблюдателю слева снизу
    add_vertex(Point(pnt1.x, pnt1.y, pnt2.z));
    add_vertex(Point(pnt2.x, pnt1.y, pnt2.z));
    add_vertex(Point(pnt2.x, pnt1.y, pnt1.z));

    //Верхняя грань
    add_vertex(Point(pnt1.x, pnt2.y, pnt1.z));
    add_vertex(Point(pnt1.x, pnt2.y, pnt2.z));
    add_vertex(pnt2);
    add_vertex(Point(pnt2.x, pnt2.y, pnt1.z));

    cout << "hi, vertex1 " << pnt1.x << " " << pnt1.y << " " << pnt1.z << endl;
    cout << "hi, vertex2 " << pnt1.x << " " << pnt1.y << " " << pnt2.z << endl;
    cout << "hi, vertex3 " << pnt2.x << " " << pnt1.y << " " << pnt2.z << endl;
    cout << "hi, vertex4 " << pnt2.x << " " << pnt1.y << " " << pnt1.z << endl;

    cout << "hi, vertex5 " << pnt1.x << " " << pnt2.y << " " << pnt1.z << endl;
    cout << "hi, vertex6 " << pnt1.x << " " << pnt2.y << " " << pnt2.z << endl;
    cout << "hi, vertex7 " << pnt2.x << " " << pnt2.y << " " << pnt2.z << endl;
    cout << "hi, vertex8 " << pnt2.x << " " << pnt2.y << " " << pnt1.z << endl;


    add_side({0, 1, 2, 3}, color);  //Нижняя грань
    add_side({4, 5, 6, 7}, color);  //Верхняя грань

    add_side({0, 4, 7, 3}, color);  //Лицевая
    add_side({0, 4, 5, 1}, color);  //Левая
    add_side({1, 5, 6, 2}, color);  //Задняя
    add_side({3, 7, 6, 2}, color);  //Правая

    normalize_n_vrt();
    _find_center(pnt1, pnt2);
}

Box::~Box() {}


void Box::_find_center(const Point &pnt1, const Point &pnt2)
{
    _center.x = (pnt1.x + pnt2.x) / 2;
    _center.y = (pnt1.y + pnt2.y) / 2;
    _center.z = (pnt1.z + pnt2.z) / 2;
}
