#ifndef MANAGERS_H
#define MANAGERS_H

#include "Scene/scene.h"


class SceneManager
{
public:
    SceneManager(weak_ptr<Scene> scene);
    virtual ~SceneManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<Scene> _scene;
    //Iterator<shared_ptr<SceneObject>> _find_pos(size_t index);
};


class DrawManager : public SceneManager
{
public:
    DrawManager(weak_ptr<Scene> scene);
    virtual ~DrawManager();

    virtual void execute();

/*private:
    weak_ptr<BaseDrawerFactory> _draw;*/
};


class InitManager : public SceneManager
{
public:
    InitManager(weak_ptr<Scene> scene, shared_ptr<QDrawer> draw);
    virtual ~InitManager();

    virtual void execute();

private:
    shared_ptr<QDrawer> _draw;
};

#endif // MANAGERS_H
