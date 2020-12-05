#ifndef PIRAMID_H
#define PIRAMID_H

#include "Primitives/Model/model.h"

class Piramid : public Model
{
public:
    Piramid(const Point& pnt1, const Point& pnt2, QRgb color);

    virtual ~Piramid();

private:
    QRgb _color;
    const double _down_length = 240;
    const double _up_length = 10;
};

#endif // PIRAMID_H
