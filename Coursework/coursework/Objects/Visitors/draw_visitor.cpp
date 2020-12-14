#include "draw_visitor.h"


DrawVisitor::DrawVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

DrawVisitor::~DrawVisitor() {}

void DrawVisitor::visit(Camera&) {}

void DrawVisitor::visit(LightSource&) {}

void DrawVisitor::visit(Stand &stand)
{
    _visual->draw_model(*stand.get_model());
}

void DrawVisitor::visit(Glass &glass)
{
   _visual->draw_intensity(*glass.get_model(), glass.get_transparency());
}

void DrawVisitor::visit(SandUpP &sand)
{
   _visual->draw_model(*sand.get_model());
}

void DrawVisitor::visit(SurfaceObject &sand)
{
   _visual->draw_model(*sand.get_model());
}

void DrawVisitor::visit(SandItem &item)
{
   _visual->draw_model(*item.get_model());
}

