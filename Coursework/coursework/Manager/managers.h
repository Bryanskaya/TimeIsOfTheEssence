#ifndef MANAGERS_H
#define MANAGERS_H

#include "Scene/scene.h"
#include "Visualizing/visualizer.h"
#include "Transformation/transformator.h"
#include "Objects/Visitors/draw_visitor.h"
#include "Objects/Visitors/update_visitor.h"


class SceneManager
{
public:
    SceneManager(weak_ptr<Scene> scene);
    virtual ~SceneManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<Scene> _scene;
};


class InitDrawManager : public SceneManager
{
public:
    InitDrawManager(weak_ptr<Scene> scene, shared_ptr<QDrawer> draw);
    virtual ~InitDrawManager();

    virtual void execute();

private:
    shared_ptr<QDrawer> _draw;
};


class DrawManager : public SceneManager
{
public:
    DrawManager(weak_ptr<Scene> scene);
    virtual ~DrawManager();

    virtual void execute();
};


class TransformManager : public SceneManager
{
public:
    TransformManager(weak_ptr<Scene> scene,
                     shared_ptr<Transformator> transf);
    virtual ~TransformManager();

    virtual void execute();

    void camera_execute();
    void light_execute();

private:
    shared_ptr<Transformator> _transf;
};


class InitUpdateManager : public SceneManager
{
public:
    InitUpdateManager(weak_ptr<Scene> scene);
    virtual ~InitUpdateManager();

    virtual void execute();
};

class UpdateManager : public SceneManager
{
public:
    UpdateManager(weak_ptr<Scene> scene);
    virtual ~UpdateManager();

    virtual void execute();
};

#endif // MANAGERS_H
