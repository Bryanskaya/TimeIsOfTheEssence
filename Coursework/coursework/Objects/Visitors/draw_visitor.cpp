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
   // cout << "drawing ended" << endl;
}

void DrawVisitor::visit(DemoBox &stand)
{
    _visual->draw_model(*stand.get_model());
   // cout << "drawing ended" << endl;
}

void DrawVisitor::visit(Glass &glass)
{
    //_visual->draw_model(*glass.get_model());
   _visual->draw_intensity(*glass.get_model(), glass.get_transparency());
}


/*TransparencyVisitor::TransparencyVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

TransparencyVisitor::~TransparencyVisitor() {}

void TransparencyVisitor::visit(Camera&) {}

void TransparencyVisitor::visit(LightSource&) {}

void TransparencyVisitor::visit(Hourglass &hourglass)
{
    //_visual->draw_model();
}

void TransparencyVisitor::visit(Stand &stand)
{
    //_visual->draw_intensity(*stand.get_model());
   // cout << "drawing ended" << endl;
}

void TransparencyVisitor::visit(Glass &glass) // надо ли делать на само стекло
{
    cout << "hi\n";
    _visual->draw_intensity(*glass.get_model(), glass.get_transparency());
   // cout << "drawing ended" << endl;
}*/
