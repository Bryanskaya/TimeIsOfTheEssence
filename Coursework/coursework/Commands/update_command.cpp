#include "update_command.h"


InitUpdateCommand::InitUpdateCommand(double limit)
{
    _t_limit = limit;
}

InitUpdateCommand::~InitUpdateCommand() {}


void InitUpdateCommand::execute(weak_ptr<Scene> scene)
{
    InitStateManager(scene, _t_limit).execute();
}



UpdateCommand::UpdateCommand(time_t t_cur, time_t dt)
{
    _t_cur = t_cur / 1000.0;
    _dt = dt / 1000.0;
}

UpdateCommand::~UpdateCommand() {}


void UpdateCommand::execute(weak_ptr<Scene> scene)
{
    UpdateManager(scene, _t_cur, _dt).execute();
}
