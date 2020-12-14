#ifndef SURFACE_OBJECT_H
#define SURFACE_OBJECT_H

#include "simple_object.h"
#include "Primitives/Surface/surface.h"
#include "Transformation/transformation.h"

#define TIME_HILL   0.2
#define DTIME       0.012

class SurfaceObject : public VisibleObject
{
public:
    SurfaceObject(const Point& pnt1, const Point& pnt2, const Point& pnt3 = Point(0, 0, 0), bool up_part = false);
    explicit SurfaceObject(const SurfaceObject& other);

    virtual ~SurfaceObject();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

    void update(double t_cur, double dt, double t_limit);
    void update_up(double t_cur, double dt, double t_limit);
    void update_down(double t_cur, double dt, double t_limit);

    bool get_status_part();

private:
    QRgb _color;
    double _limit_y;
    bool _is_up_part;
};

#endif // SURFACE_OBJECT_H
