#ifndef SCENE_ERRORS_H
#define SCENE_ERRORS_H

#include "base_error.h"

namespace error {

class ImageExpired : public BaseError
{
public:
    ImageExpired(string filename, string classname, int num_line);
    virtual ~ImageExpired();
};


class SceneExpired : public BaseError
{
public:
    SceneExpired(string filename, string classname, int num_line);
    virtual ~SceneExpired();
};


class BehindScene : public BaseError
{
public:
    BehindScene(string filename, string classname, int num_line);
    virtual ~BehindScene();
};
}


#endif // SCENE_ERRORS_H
