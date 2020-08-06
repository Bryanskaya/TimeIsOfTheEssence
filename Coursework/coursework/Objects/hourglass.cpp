#include "hourglass.h"


Hourglass::Hourglass() {}

Hourglass::~Hourglass() {}


double Hourglass::get_time() {  return _timelimit;  }

double Hourglass::get_height() {    return _height; }

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
