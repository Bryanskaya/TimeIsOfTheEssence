#include "vector_errors.h"

using namespace error;

InvalidOperation::InvalidOperation(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Vector error: invalid operation with vector"){}
InvalidOperation::~InvalidOperation() = default;
