#ifndef SURFACE_OBJECT_H
#define SURFACE_OBJECT_H

#include "simple_object.h"
#include "Primitives/Surface/surface.h"
#include "Transformation/transformation.h"

#define TIME_HILL   0.1
#define DTIME       0.012

class SurfaceObject : public VisibleObject
{
public:
    SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3, bool up_part);
    explicit SurfaceObject(const SurfaceObject& other);

    virtual ~SurfaceObject();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

    void update(double t_cur, double dt, double t_limit);

private:
    QRgb _color;
    double _limit_y;
};

#endif // SURFACE_OBJECT_H
