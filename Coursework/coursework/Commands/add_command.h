#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include "Primitives/Vector/vector.h"
#include "base_command.h"


class AddCommand : public BaseCommand
{
public:
    AddCommand();
    virtual ~AddCommand() = 0;

    virtual void execute(weak_ptr<Scene>);
};

class AddCamera : public AddCommand
{
public:
    AddCamera(const Point&, const Vector&);
    virtual ~AddCamera();
};


class AddLightSource : public AddCommand
{
public:
    AddLightSource(const Point&, double);
    virtual ~AddLightSource();
};

#endif // ADD_COMMAND_H
