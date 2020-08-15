#include "draw_visitor.h"


DrawVisitor::DrawVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

DrawVisitor::~DrawVisitor() {}

void DrawVisitor::visit(Camera &camera) {}

void DrawVisitor::visit(LightSource &light) {}

void DrawVisitor::visit(Hourglass &hourglass)
{
    //_visual->draw_model();
}

void DrawVisitor::visit(Stand &stand)
{
    _visual->draw_model(*stand.get_model());
}
