#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <memory>
#include <math.h>

#include "Objects/camera.h"

#define PI  3.1415


using namespace std;

class Transformation
{
public:
    Transformation();
    virtual ~Transformation() = 0;

    virtual void rotate(const Vector& vect) = 0;

    virtual void execute(double& x, double& y, double& z) = 0;
    virtual void execute(Point& pnt) = 0;
    virtual void execute(Vertex& vertex) = 0;
    virtual void execute(Vector& vect) = 0;
    virtual void execute(Camera& camera) = 0;
};

class Move : public Transformation
{
public:
    Move(double dx, double dy, double dz);
    Move(const Vector& vect);
    virtual ~Move();

    virtual void rotate(const Vector& vect);

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Point& pnt);
    virtual void execute(Vertex& vertex);
    virtual void execute(Vector& vect);
    virtual void execute(Camera& camera);

private:
    Vector _dir;
};

class Rotate : public Transformation
{
public:
    Rotate(const Vector& vect, const Point& pnt);
    Rotate(const Vector& vect);
    virtual ~Rotate();

    virtual void rotate(const Vector& vect);

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Point& pnt);
    virtual void execute(Vertex& vertex);
    virtual void execute(Vector& vect);
    virtual void execute(Camera& camera);

    void to_radians();

private:
    Vector _dir;
    Point _center;

    double _to_radians(double angle);

    void rotate_x(double& x, double& y, double& z);
    void rotate_y(double& x, double& y, double& z);
    void rotate_z(double& x, double& y, double& z);

    void rotate_ox(double& x, double& y, double& z);
    void rotate_oy(double& x, double& y, double& z);
    void rotate_oz(double& x, double& y, double& z);
};

class Scale : public Transformation
{
public:
    Scale(const Vector& vect);
    Scale(const Vector& vect, const Point& pnt);
    virtual ~Scale();

    virtual void rotate(const Vector& vect);

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Point& pnt);
    virtual void execute(Vertex& vertex);
    virtual void execute(Vector& vect);
    virtual void execute(Camera& camera);

private:
    Vector _dir;
    Point _center;
};

#endif // TRANSFORMATION_H
