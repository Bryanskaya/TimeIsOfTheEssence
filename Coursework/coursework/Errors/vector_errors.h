#ifndef VECTOR_ERRORS_H
#define VECTOR_ERRORS_H

#include "base_error.h"

namespace error {

class InvalidOperation : public BaseError
{
public:
    InvalidOperation(string filename, string classname, int num_line);
    virtual ~InvalidOperation();
};

}

#endif // VECTOR_ERRORS_H
