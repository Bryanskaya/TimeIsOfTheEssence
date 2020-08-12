#ifndef CAMERA_H
#define CAMERA_H

#include "Objects/simple_object.h"

class Camera : public InvisibleObject
{
public:
    Camera();
    Camera(const Point& position);
    Camera(const Point& position, const Vector& direction);
    explicit Camera(const Camera& other);
    virtual ~Camera();

    Point& get_position();
    Vector& get_direction();

    const Point& get_position() const;
    const Vector& get_direction() const;

    void operator=(const Camera& other);

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();

private:
    Point _pos;
    Vector _dir;
};

#endif // CAMERA_H
