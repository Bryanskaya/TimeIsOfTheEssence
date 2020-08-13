#include "transform_command.h"

TransformCommand::TransformCommand(const shared_ptr<Transformator>& transf) :
    _transf(transf) {}

TransformCommand::~TransformCommand() {}

void TransformCommand::execute(weak_ptr<Scene> scene)
{
    //TransformManager(scene, _transf).execute();
}


/*RotateCommand::RotateCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Rotate(ax, ay, az), index) {}*/

RotateCommand::~RotateCommand() {}


MoveCommand::MoveCommand(const Vector& vect) :
    TransformCommand(shared_ptr<Transformator>(new Transformator(new Move(vect)))) {}

MoveCommand::~MoveCommand() {}

void MoveCommand::execute(weak_ptr<Scene> scene) {}


MoveCamera::MoveCamera(const Vector& vect) :
    MoveCommand(vect) {}

MoveCamera::~MoveCamera() {}

void MoveCamera::execute(weak_ptr<Scene> scene)
{
    //
}


MoveLightSource::MoveLightSource(const Vector& vect) :
    MoveCommand(vect) {}

MoveLightSource::~MoveLightSource() {}

void MoveLightSource::execute(weak_ptr<Scene> scene)
{
    //
}
