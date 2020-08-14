#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "Objects/camera.h"
#include "Objects/light_source.h"
#include "Objects/hourglass.h"


class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(Camera& camera) = 0;
    virtual void visit(LightSource& light) = 0;

    virtual void visit(Hourglass& hourglass) = 0;
};

#endif // OBJECT_VISITOR_H
