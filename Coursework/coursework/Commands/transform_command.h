#ifndef TRANSFORM_COMMAND_H
#define TRANSFORM_COMMAND_H

#include "base_command.h"
#include "Transformation/transformator.h"
#include "Transformation/transformation.h"


class TransformCommand : public BaseCommand
{
public:
    TransformCommand(const shared_ptr<Transformator>& transf);
    virtual ~TransformCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;

protected:
    shared_ptr<Transformator> _transf;
};


class RotateCommand : public TransformCommand
{
public:
    RotateCommand(const Point& center, const Vector& vect);
    virtual ~RotateCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};


class MoveCommand : public TransformCommand
{
public:
    MoveCommand(const Vector& vect);
    virtual ~MoveCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};



class RotateCamera : public RotateCommand
{
public:
     RotateCamera(const Vector& vect);
     virtual ~RotateCamera();

     virtual void execute(weak_ptr<Scene> scene);
};


class RotateLightSource : public RotateCommand
{
public:
    RotateLightSource(const Point& center, const Vector& vect);
    virtual ~RotateLightSource();

    virtual void execute(weak_ptr<Scene> scene);
};


class MoveCamera : public MoveCommand
{
public:
    MoveCamera(const Vector& vect);
    virtual ~MoveCamera();

    virtual void execute(weak_ptr<Scene> scene);
};


class MoveLightSource : public MoveCommand
{
public:
    MoveLightSource(const Vector& vect);
    virtual ~MoveLightSource();

    virtual void execute(weak_ptr<Scene> scene);
};



#endif // TRANSFORM_COMMAND_H
