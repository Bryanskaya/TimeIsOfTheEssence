#include "transform_command.h"

TransformCommand::TransformCommand(const shared_ptr<Transformator>& transf) :
    _transf(transf) {}

TransformCommand::~TransformCommand() {}

void TransformCommand::execute(weak_ptr<Scene>) {}


RotateCommand::RotateCommand(const Point& center, const Vector& vect) :
    TransformCommand(shared_ptr<Transformator>(new Transformator(new Rotate(vect, center)))) {}

RotateCommand::~RotateCommand() {}

void RotateCommand::execute(weak_ptr<Scene>) {}


RotateCamera::RotateCamera(const Vector& vect) :
    RotateCommand(Point(0, 0, 0), vect) {}

RotateCamera::~RotateCamera() {}

void RotateCamera::execute(weak_ptr<Scene> scene)
{
    TransformManager(scene, _transf).camera_execute();
}


RotateLightSource::RotateLightSource(const Point& center, const Vector& vect) :
    RotateCommand(center, vect) {}

RotateLightSource::~RotateLightSource() {}

void RotateLightSource::execute(weak_ptr<Scene> scene)
{
    TransformManager(scene, _transf).light_execute();
}



MoveCommand::MoveCommand(const Vector& vect) :
    TransformCommand(shared_ptr<Transformator>(new Transformator(new Move(vect)))) {}

MoveCommand::~MoveCommand() {}

void MoveCommand::execute(weak_ptr<Scene>) {}


MoveCamera::MoveCamera(const Vector& vect) :
    MoveCommand(vect) {}

MoveCamera::~MoveCamera() {}

void MoveCamera::execute(weak_ptr<Scene> scene)
{
    TransformManager(scene, _transf).camera_execute();
}


MoveLightSource::MoveLightSource(const Vector& vect) :
    MoveCommand(vect) {}

MoveLightSource::~MoveLightSource() {}

void MoveLightSource::execute(weak_ptr<Scene> scene)
{
    TransformManager(scene, _transf).light_execute();
}
