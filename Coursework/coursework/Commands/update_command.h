#ifndef UPDATE_COMMAND_H
#define UPDATE_COMMAND_H

#include "base_command.h"


class InitUpdateCommand : public BaseCommand
{
public:
    InitUpdateCommand(double limit);
    virtual ~InitUpdateCommand();

    virtual void execute(weak_ptr<Scene> scene);

private:
    double _t_limit;
};


class UpdateCommand : public BaseCommand
{
public:
    UpdateCommand(time_t t_cur, time_t dt);
    virtual ~UpdateCommand();

    virtual void execute(weak_ptr<Scene> scene);

private:
    double _t_cur;
    double _dt;
};

#endif // UPDATE_COMMAND_H
