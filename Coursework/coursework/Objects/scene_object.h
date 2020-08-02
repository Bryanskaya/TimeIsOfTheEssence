#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <memory>

using namespace std;

class ObjectVisitor;

class SceneObject
{
public:
    SceneObject();

    virtual ~SceneObject() = 0;

    virtual bool is_drawable() const;
    virtual bool is_complex() const;

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // SCENE_OBJECT_H
