#ifndef HOURGLASS_ERROR_H
#define HOURGLASS_ERROR_H

#include "base_error.h"

namespace error {

class WrongTimeLimit : public BaseError
{
public:
    WrongTimeLimit(string filename, string classname, int num_line);
    virtual ~WrongTimeLimit();
};

class WrongHeight : public BaseError
{
public:
    WrongHeight(string filename, string classname, int num_line);
    virtual ~WrongHeight();
};

class WrongLimits : public BaseError
{
public:
    WrongLimits(string filename, string classname, int num_line, int left_limit, int right_limit);
    virtual ~WrongLimits();
};

}

#endif // HOURGLASS_ERROR_H
