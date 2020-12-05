#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include "Primitives/Vector/vector.h"
#include "base_command.h"


class AddCommand : public BaseCommand
{
public:
    AddCommand();
    virtual ~AddCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene);
};

class AddCamera : public AddCommand
{
public:
    AddCamera(const Point& position, const Vector& direction);
    virtual ~AddCamera();
};


class AddLightSource : public AddCommand
{
public:
    AddLightSource(const Point& position, double itensity);
    virtual ~AddLightSource();
};

#endif // ADD_COMMAND_H
