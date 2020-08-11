#include "hourglass_error.h"

using namespace error;

WrongTimeLimit::WrongTimeLimit(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong time limit"){}
WrongTimeLimit::~WrongTimeLimit() = default;

WrongHeight::WrongHeight(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong height"){}
WrongHeight::~WrongHeight() = default;

WrongLimits::WrongLimits(string filename, string classname, int num_line, int left_limit, int right_limit) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong limits of creating sand's surface (left: " + to_string(left_limit) + "; right: " + to_string(right_limit) + ")"){}
WrongLimits::~WrongLimits() = default;
