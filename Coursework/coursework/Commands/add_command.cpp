#include "add_command.h"

AddCommand::AddCommand() {}

AddCommand::~AddCommand() {}

void AddCommand::execute(weak_ptr<Scene> scene)
{
    //AddManager(scene, _creator).execute();
}


AddCamera::AddCamera(const Point& position, const Vector& direction)
{
    //_creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}

AddCamera::~AddCamera() {}


AddLightSource::AddLightSource(const Point& position, double itensity)
{
    //_creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}

AddLightSource::~AddLightSource() {}
