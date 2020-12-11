#ifndef UPDATE_COMMAND_H
#define UPDATE_COMMAND_H

#include "base_command.h"


class InitUpdateCommand : public BaseCommand
{
public:
    InitUpdateCommand();
    virtual ~InitUpdateCommand();

    virtual void execute(weak_ptr<Scene> scene);
};


class UpdateCommand : public BaseCommand
{
public:
    UpdateCommand();
    virtual ~UpdateCommand();

    virtual void execute(weak_ptr<Scene> scene);
};

#endif // UPDATE_COMMAND_H
