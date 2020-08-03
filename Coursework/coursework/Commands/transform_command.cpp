#include "transform_command.h"

//TransformCommand::TransformCommand() {}

TransformCommand::~TransformCommand() {}

void TransformCommand::execute(weak_ptr<Scene> scene)
{
    //TransformManager(scene, _transf, _index).execute();
}


/*RotateCommand::RotateCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Rotate(ax, ay, az), index) {}*/

RotateCommand::~RotateCommand() {}


/*MoveCommand::MoveCommand(double ax, double ay, double az, size_t index) :
    TransformCommand(new Move(ax, ay, az), index) {}*/

MoveCommand::~MoveCommand() {}
