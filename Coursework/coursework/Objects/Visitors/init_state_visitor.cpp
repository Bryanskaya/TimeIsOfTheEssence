#include "init_state_visitor.h"

InitStateVisitor::InitStateVisitor(){}

InitStateVisitor::~InitStateVisitor() {}


void InitStateVisitor::visit(Camera&) {}

void InitStateVisitor::visit(LightSource&) {}

void InitStateVisitor::visit(Hourglass&) {}

void InitStateVisitor::visit(Stand&) {}

void InitStateVisitor::visit(Glass&) {}

void InitStateVisitor::visit(SandUpP&)
{
    throw 1001;
}

void InitStateVisitor::visit(SurfaceObject&)
{
    throw 1002;
}

void InitStateVisitor::visit(SandItem&)
{
    throw 1003;
}

void InitStateVisitor::visit(DemoBox&) {}
