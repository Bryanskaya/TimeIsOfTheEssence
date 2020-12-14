#include "draw_command.h"


InitDrawCommand::InitDrawCommand(const weak_ptr<QImage>& image) :
    _image(image) {}

InitDrawCommand::~InitDrawCommand() {}

void InitDrawCommand::execute(weak_ptr<Scene> scene)
{
    shared_ptr<QDrawer> image(new QDrawer(_image));

    InitDrawManager(scene, image).execute();
}


DrawCommand::DrawCommand() {}

DrawCommand::~DrawCommand() {}

void DrawCommand::execute(weak_ptr<Scene> scene)
{
    DrawManager(scene).execute();
}
