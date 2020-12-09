#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H

#include "base_command.h"
#include "Manager/managers.h"


class InitDrawCommand : public BaseCommand
{
public:
    InitDrawCommand(const weak_ptr<QImage>& image);
    virtual ~InitDrawCommand();

    virtual void execute(weak_ptr<Scene> scene);

private:
    weak_ptr<QImage> _image;
};


class DrawCommand : public BaseCommand
{
public:
    DrawCommand();
    virtual ~DrawCommand();

    virtual void execute(weak_ptr<Scene> scene);
};

#endif // DRAW_COMMAND_H
