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

WrongLimits::WrongLimits(string filename, string classname, int num_line, int x_start, int x_end, int y_start, int y_end) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong limits of creating sand's surface (x: " + to_string(x_start) + " x " + to_string(x_end) + \
              "; y: " + to_string(y_start) + " x " + to_string(y_end) + ")"){}
WrongLimits::~WrongLimits() = default;

WrongLevelofSand::WrongLevelofSand(string filename, string classname, int num_line, int level) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong level of sand in top part (level = " + to_string(level) + ")"){}
WrongLevelofSand::~WrongLevelofSand() = default;

WrongNumofVertices::WrongNumofVertices(string filename, string classname, int num_line, int num) :
    BaseError(filename, classname, num_line,
              "Hourglass error: wrong number of vertices (num = " + to_string(num) + ")"){}
WrongNumofVertices::~WrongNumofVertices() = default;
