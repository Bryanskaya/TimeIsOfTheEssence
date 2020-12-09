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
    WrongLimits(string filename, string classname, int num_line, int x_start, int x_end, int y_start, int y_end);
    virtual ~WrongLimits();
};

class WrongLevelofSand : public BaseError
{
public:
    WrongLevelofSand(string filename, string classname, int num_line, int level);
    virtual ~WrongLevelofSand();
};

class WrongNumofVertices : public BaseError
{
public:
    WrongNumofVertices(string filename, string classname, int num_line, int num);
    virtual ~WrongNumofVertices();
};

}

#endif // HOURGLASS_ERROR_H
