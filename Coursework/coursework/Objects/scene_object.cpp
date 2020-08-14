#include "scene_object.h"

//constructors and destructor
SceneObject::SceneObject() {}

SceneObject::~SceneObject() {}


//methods
bool SceneObject::is_drawable() const
{
    return false;
}

bool SceneObject::is_complex() const
{
    return false;
}

void SceneObject::accept(ObjectVisitor&) {}

SceneObject *SceneObject::clone()
{
    return nullptr;
}
