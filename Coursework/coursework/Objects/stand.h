#ifndef STAND_H
#define STAND_H

#include "simple_object.h"
#include "Primitives/Box/box.h"


class Stand : public VisibleObject
{
public:
    Stand(double x, double y, double z);
    explicit Stand(const Stand& other);

    virtual ~Stand();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    const double _height = 20;
    const double _length = 260;
};

class DemoBox : public VisibleObject
{
public:
    DemoBox(Point& pnt1, Point& pnt2);
    explicit DemoBox(const DemoBox& other);

    virtual ~DemoBox();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    const double _height = 10;
    const double _length = 10;
};

#endif // STAND_H
