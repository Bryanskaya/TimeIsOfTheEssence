#include "update_command.h"


InitUpdateCommand::InitUpdateCommand() {}

InitUpdateCommand::~InitUpdateCommand() {}


void InitUpdateCommand::execute(weak_ptr<Scene> scene)
{
    InitUpdateManager(scene).execute();
}



UpdateCommand::UpdateCommand() {}

UpdateCommand::~UpdateCommand() {}


void UpdateCommand::execute(weak_ptr<Scene> scene)
{
    UpdateManager(scene).execute();
}
