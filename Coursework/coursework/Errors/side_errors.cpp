#include "side_errors.h"

using namespace error;

DegenerateSide::DegenerateSide(string filename, string classname, int num_line, double cur_size) :
    BaseError(filename, classname, num_line,
              "Side error: lack of vertices (" + to_string(cur_size) + ")"){}
DegenerateSide::~DegenerateSide() = default;
