#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include "transformation.h"


class Transformator
{
public:
    Transformator(Transformation* transform) : _transform(transform) {}
    ~Transformator() {}

    void set_transformator(Transformation* transform)
    {
        _transform = unique_ptr<Transformation>(transform);
    }

    void transform(double& x, double& y, double& z) { _transform->execute(x, y, z); }
    void transform(Point& pnt) { _transform->execute(pnt); }
    void transform(Vertex& vertex) { _transform->execute(vertex); }
    void transform(Vector& vect) { _transform->execute(vect); }
    void transform(Camera& camera) { _transform->execute(camera); }

private:
    unique_ptr<Transformation> _transform;
};

#endif // TRANSFORMATOR_H
