#ifndef FACADE_H
#define FACADE_H

#include "scene.h"
#include "Commands/base_command.h"


class Facade
{
public:
    Facade(Scene* scene) : _scene(scene) {}
    ~Facade() = default;

    void execute(BaseCommand& command)
    {
        command.execute(weak_ptr<Scene>(_scene));
    }

private:
    shared_ptr<Scene> _scene;
};

#endif // FACADE_H
