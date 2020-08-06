#ifndef HOURGLASS_H
#define HOURGLASS_H

#include <memory>

#include "Errors/hourglass_error.h"


class Hourglass
{
public:
    Hourglass();

    virtual ~Hourglass();

    double get_height();
    double get_time();

    void set_height(double height);
    void set_time(double time_limit);

private:
    double _height = 500;
    double _timelimit = 60;
};

#endif // HOURGLASS_H
