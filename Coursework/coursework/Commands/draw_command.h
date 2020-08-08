#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H

#include "base_command.h"


class DrawCommand : public BaseCommand
{
public:
    DrawCommand();
    virtual ~DrawCommand() = 0;

    virtual void execute(weak_ptr<Scene> scene);

/*protected:
    shared_ptr<BaseDrawerFactory> _draw;*/
};

#endif // DRAW_COMMAND_H
