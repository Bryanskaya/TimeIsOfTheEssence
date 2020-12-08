#ifndef PIRAMID_H
#define PIRAMID_H

#include "Primitives/Model/model.h"

class Piramid : public Model
{
public:
    Piramid(const Point& pnt1, const Point& pnt2, QRgb color, double down_length, double up_length);

    virtual ~Piramid();

private:
    QRgb _color;
};

#endif // PIRAMID_H
