#ifndef BOX_H
#define BOX_H

#include "Primitives/Model/model.h"

class Box : public Model
{
public:
    Box(const Point& pnt1, const Point& pnt2, QRgb color);

    virtual ~Box();

private:
    QRgb _color;

    void _find_center(const Point& pnt1, const Point& pnt2);
};



#endif // BOX_H
