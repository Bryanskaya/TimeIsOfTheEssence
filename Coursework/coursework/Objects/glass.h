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

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;

    double k;
};

#endif // GLASS_H
