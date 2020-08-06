#include "hourglass_error.h"

using namespace error;

WrongTimeLimit::WrongTimeLimit(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong time limit"){}
WrongTimeLimit::~WrongTimeLimit() = default;

