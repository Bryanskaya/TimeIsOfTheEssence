#include "draw_visitor.h"


DrawVisitor::DrawVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

DrawVisitor::~DrawVisitor() {}

void DrawVisitor::visit(Camera&) {}

void DrawVisitor::visit(LightSource&) {}

void DrawVisitor::visit(Hourglass &hourglass)
{
    //_visual->draw_model();
}

void DrawVisitor::visit(Stand &stand)
{
    _visual->draw_model(*stand.get_model());
    cout << "drawing ended" << endl;
}
