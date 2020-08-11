#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include "simple_object.h"


class LightSource : public InvisibleObject
{
public:
    LightSource();
    LightSource(const Point& position);
    LightSource(const Point& position, double itensity);
    explicit LightSource(const LightSource& other);

    virtual ~LightSource();

    Point& get_position();
    double get_itensity();
    void set_itensity(double itensity);

    const Point& get_position() const;

    void operator =(const LightSource& other);

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();

private:
    Point _pos;
    double _i;
};

#endif // LIGHT_SOURCE_H
