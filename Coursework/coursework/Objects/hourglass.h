#ifndef HOURGLASS_H
#define HOURGLASS_H

#include <memory>

#include "Errors/hourglass_error.h"
#include "sand.h"
//#include "glass.h"


class Hourglass
{
public:
    Sand sand;
    //Glass glass;
    Model stand_models;


    Hourglass();
    explicit Hourglass(const Hourglass& other);

    virtual ~Hourglass();

    double get_height();
    double get_time();
    Point& get_pos();

    void set_height(double height);
    void set_time(double time_limit);
    void set_pos(const Point& pnt);

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();

private:
    double _height = 400;
    double _timelimit = 60;
    Point _pos;
};

#endif // HOURGLASS_H
