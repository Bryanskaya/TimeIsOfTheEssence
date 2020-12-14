#include "add_command.h"

AddCommand::AddCommand() {}

AddCommand::~AddCommand() {}

void AddCommand::execute(weak_ptr<Scene>)
{
    //AddManager(scene, _creator).execute();
}


AddCamera::AddCamera(const Point&, const Vector&)
{
    //_creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}

AddCamera::~AddCamera() {}


AddLightSource::AddLightSource(const Point&, double)
{
    //_creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}

AddLightSource::~AddLightSource() {}
