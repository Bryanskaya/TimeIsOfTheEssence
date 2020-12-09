#ifndef SURFACE_H
#define SURFACE_H

#include "simple_object.h"


class Surface : public VisibleObject
{
public:
    double a, b, c, d;

    Surface();
    Surface(double data_a, double data_b, double data_c, double data_d);

    virtual ~Surface();

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();
};

#endif // SURFACE_H
