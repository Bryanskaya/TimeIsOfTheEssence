#include "scene_errors.h"

using namespace error;

ImageExpired::ImageExpired(string filename, string classname, int num_line) :
    BaseError(filename, classname, num_line,
              "Scene error: image was expired"){}
ImageExpired::~ImageExpired() = default;
