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


/*class DrawManager : public SceneManager
{
public:
    DrawManager(weak_ptr<Scene> scene,
                weak_ptr<BaseDrawerFactory> draw);
    virtual ~DrawManager();

    virtual void execute();

private:
    weak_ptr<BaseDrawerFactory> _draw;
}; */

#endif // MANAGERS_H
