#include "init_state_visitor.h"

InitStateVisitor::InitStateVisitor(){}

InitStateVisitor::~InitStateVisitor() {}


void InitStateVisitor::visit(Camera&) {}

void InitStateVisitor::visit(LightSource&) {}

void InitStateVisitor::visit(Stand&) {}

void InitStateVisitor::visit(Glass&)
{
    throw 1004;
}

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
