#ifndef SURFACE_OBJECT_H
#define SURFACE_OBJECT_H

#include "simple_object.h"
#include "Primitives/Surface/surface.h"


class SurfaceObject : public VisibleObject
{
public:
    SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3, bool up_part);
    explicit SurfaceObject(const SurfaceObject& other);

    virtual ~SurfaceObject();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // SURFACE_OBJECT_H
