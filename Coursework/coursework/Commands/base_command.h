#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include <memory>

#include "Scene/scene.h"
#include "Manager/managers.h"


class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};

#endif // BASE_COMMAND_H
