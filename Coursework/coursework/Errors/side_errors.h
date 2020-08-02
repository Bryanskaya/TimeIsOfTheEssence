#ifndef SIDE_ERRORS_H
#define SIDE_ERRORS_H

#include "base_error.h"

namespace error {

class DegenerateSide : public BaseError
{
public:
    DegenerateSide(string filename, string classname, int num_line, double cur_size);
    virtual ~DegenerateSide();
};

}

#endif // SIDE_ERRORS_H
