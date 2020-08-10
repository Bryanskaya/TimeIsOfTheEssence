#include "hourglass.h"


Hourglass::Hourglass() {}

Hourglass::Hourglass(const Hourglass &other)
{
    set_pos(other._pos);
    set_time(other._timelimit);
    set_height(other._height);

    sand = other.sand;
    glass = other.glass;
    stand_models = other.stand_models;
}

Hourglass::~Hourglass() {}


double Hourglass::get_time() {  return _timelimit;  }

double Hourglass::get_height() {    return _height; }

Point& Hourglass::get_pos() {   return _pos;    }

void Hourglass::set_time(double time_limit)
{
    if (time_limit < 0)
        throw error::WrongTimeLimit(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _timelimit = time_limit;
}

void Hourglass::set_height(double height)
{
    if (height <= 0)
        throw error::WrongHeight(__FILE__, typeid (*this).name(), __LINE__ - 1);

   _height = height;
}

void Hourglass::set_pos(const Point &pnt)
{
    _pos = pnt;
}
