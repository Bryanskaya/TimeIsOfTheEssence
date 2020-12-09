#include "base_error.h"

using namespace error;

BaseError::BaseError(string filename, string classname, int num_line,
                     string msg = "Error")
{
    time_t t = time(nullptr);

    errormsg = "\n\nFile name: " + filename +
               "\nClass:     " + classname +
               "\nIn line:   " + to_string(num_line) +
               "\nTime:      " + ctime(&t) +
               msg;
}

BaseError::~BaseError(){}

const char* BaseError::what() const noexcept
{
    return errormsg.c_str();
}
