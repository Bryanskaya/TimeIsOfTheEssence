#ifndef HOURGLASS_H
#define HOURGLASS_H

#include "base_error.h"

namespace error {

class WrongTimeLimit : public BaseError
{
public:
    WrongTimeLimit(string filename, string classname, int num_line);
    virtual ~WrongTimeLimit();
};

}

#endif // HOURGLASS_H
