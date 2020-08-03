#ifndef TRANSFORM_COMMAND_H
#define TRANSFORM_COMMAND_H

#include "base_command.h"

class TransformCommand : public BaseCommand
{
public:
    //TransformCommand(Transformation* transf, size_t index);
    virtual ~TransformCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene);

protected:
    //shared_ptr<Transformator> _transf;
    size_t _index;
};


class RotateCommand : public TransformCommand
{
public:
    //RotateCommand(double ax, double ay, double az, size_t index);
    virtual ~RotateCommand() = 0;
};


class MoveCommand : public TransformCommand
{
public:
    //MoveCommand(double dx, double dy, double dz, size_t index);
    virtual ~MoveCommand() = 0;
};



class RotateCamera : public RotateCommand
{
public:
    //RotateCamera(Vector move);
     virtual ~RotateCamera();
};


class RotateLightSource : public RotateCommand
{
public:
    //RotateLightSource(Vector move);
     virtual ~RotateLightSource();
};


class MoveCamera : public MoveCommand
{
public:
    //MoveCamera(Vector move);
     virtual ~MoveCamera();
};


class MoveLightSource : public MoveCommand
{
public:
    //MoveLightSource(Vector move);
     virtual ~MoveLightSource();
};



#endif // TRANSFORM_COMMAND_H
