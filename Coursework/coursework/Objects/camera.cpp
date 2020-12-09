#include "camera.h"
#include "Visitors/object_visitor.h"

//constructors and destructor
Camera::Camera() :
    _pos(Point(10, 10, 100)) {}

Camera::Camera(const Point& position) :
    _pos(position) {}

Camera::Camera(const Point& position, const Vector& direction) :
    _pos(position), _dir(direction) {}

Camera::Camera(const Camera& other) :
    _pos(other._pos), _dir(other._dir) {}

Camera::~Camera() {}


//methonds
Point& Camera::get_position() {     return _pos;    }

Vector& Camera::get_direction() {   return _dir;    }

const Point& Camera::get_position() const {     return _pos;    }

const Vector& Camera::get_direction() const {   return _dir;    }

void Camera::operator=(const Camera &other)
{
    this->_pos = other._pos;
    this->_dir = other._dir;
}


void Camera::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}

SceneObject *Camera::clone()
{
    return (new Camera(*this));
}
