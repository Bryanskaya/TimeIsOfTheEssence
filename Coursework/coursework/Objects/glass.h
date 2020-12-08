#ifndef GLASS_H
#define GLASS_H

#include "simple_object.h"
#include "Primitives/Piramid/piramid.h"


class Glass : public VisibleObject
{
public:
    Glass(const Point& pnt1, const Point& pnt2);
    explicit Glass(const Glass& other);

    virtual ~Glass();

    double get_transparency();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    double _tr = 0.3;
    double _down_length = 240;
    double _up_length = 10;
};

#endif // GLASS_H
