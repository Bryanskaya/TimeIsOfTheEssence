#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "Objects/camera.h"
#include "Objects/light_source.h"
#include "Objects/stand.h"
#include "Objects/glass.h"
#include "Objects/surface_object.h"
#include "Objects/sand.h"


class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(Camera& camera) = 0;
    virtual void visit(LightSource& light) = 0;

    virtual void visit(Stand& stand) = 0;
    virtual void visit(Glass& glass) = 0;

    virtual void visit(SandUpP& sand) = 0;
    virtual void visit(SurfaceObject& sand) = 0;
    virtual void visit(SandItem& item) = 0;
};

#endif // OBJECT_VISITOR_H
