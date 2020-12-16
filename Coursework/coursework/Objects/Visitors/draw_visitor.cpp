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



DrawShdVisitor::DrawShdVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

DrawShdVisitor::~DrawShdVisitor() {}

void DrawShdVisitor::visit(Camera&) {}

void DrawShdVisitor::visit(LightSource&) {}

void DrawShdVisitor::visit(Stand &stand)
{
    _visual->draw_shadows(*stand.get_model());
}

void DrawShdVisitor::visit(Glass &glass)
{
   //_visual->draw_intensity(*glass.get_model(), glass.get_transparency());
}

void DrawShdVisitor::visit(SandUpP &sand)
{
   _visual->draw_shadows(*sand.get_model());
}

void DrawShdVisitor::visit(SurfaceObject &sand)
{
   _visual->draw_shadows(*sand.get_model());
}

void DrawShdVisitor::visit(SandItem &item)
{
   _visual->draw_shadows(*item.get_model());
}
