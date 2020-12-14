#ifndef DRAW_VISITOR_H
#define DRAW_VISITOR_H

#include "object_visitor.h"
#include "Visualizing/visualizer.h"


class DrawVisitor : public ObjectVisitor
{
public:
    DrawVisitor(shared_ptr<Visualizer>& visual);
    virtual ~DrawVisitor();

    virtual void visit(Camera& camera);
    virtual void visit(LightSource& light);

    virtual void visit(Stand& stand);

    virtual void visit(Glass& glass);
    virtual void visit(SandUpP& sand);
    virtual void visit(SurfaceObject& sand);
    virtual void visit(SandItem& item);

private:
    shared_ptr<Visualizer> _visual;
};

#endif // DRAW_VISITOR_H
