#ifndef PIRAMID_3_H
#define PIRAMID_3_H

#include "Primitives/Model/model.h"

class Piramid_3 : public Model
{
public:
    Piramid_3(const Point& pnt1, const Point& pnt2, const Point& pnt3, const Point& pnt_top, QRgb color);

    virtual ~Piramid_3();

private:
    QRgb _color;
};

#endif // PIRAMID_3_H
