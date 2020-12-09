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

    virtual void visit(Hourglass& hourglass);
    virtual void visit(Stand& stand);

    virtual void visit(DemoBox& demobox);


    virtual void visit(Glass& glass);
    virtual void visit(SandUpP& sand);
    virtual void visit(SurfaceObject& sand);

private:
    shared_ptr<Visualizer> _visual;
};

/*class TransparencyVisitor : public ObjectVisitor
{
public:
    TransparencyVisitor(shared_ptr<Visualizer>& visual);
    virtual ~TransparencyVisitor();

    virtual void visit(Camera& camera);
    virtual void visit(LightSource& light);

    virtual void visit(Hourglass& hourglass);
    virtual void visit(Stand& stand);

    virtual void visit(Glass& glass);

private:
    shared_ptr<Visualizer> _visual;
};*/

#endif // DRAW_VISITOR_H
