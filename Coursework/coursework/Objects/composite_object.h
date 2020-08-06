#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H

#include "scene_object.h"

class CompositeObject : public SceneObject
{
public:
    CompositeObject();

    virtual ~CompositeObject() = 0;

    virtual bool is_complex() const final {   return true;   }
};

#endif // COMPOSITE_OBJECT_H
