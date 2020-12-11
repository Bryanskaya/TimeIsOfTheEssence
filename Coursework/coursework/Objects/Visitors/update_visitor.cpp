#include "update_visitor.h"

UpdateVisitor::UpdateVisitor(shared_ptr<Updater>& updater) : _updater(updater) {}

UpdateVisitor::~UpdateVisitor() {}


void UpdateVisitor::visit(Camera&) {}

void UpdateVisitor::visit(LightSource&) {}

void UpdateVisitor::visit(Hourglass&) {}

void UpdateVisitor::visit(Stand&) {}

void UpdateVisitor::visit(Glass&) {}

void UpdateVisitor::visit(SandUpP& sand)
{
    //
}

void UpdateVisitor::visit(SurfaceObject& sand)
{

}

void UpdateVisitor::visit(SandItem& item)
{
    //_updater->add_item(item);
}

void UpdateVisitor::visit(DemoBox&) {}

