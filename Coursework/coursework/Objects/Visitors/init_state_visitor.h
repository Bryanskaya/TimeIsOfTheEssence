#ifndef INIT_STATE_H
#define INIT_STATE_H

#include "object_visitor.h"


class InitStateVisitor : public ObjectVisitor
{
public:
    InitStateVisitor();
    virtual ~InitStateVisitor();

    virtual void visit(Camera& camera);
    virtual void visit(LightSource& light);

    virtual void visit(Stand& stand);
    virtual void visit(Glass& glass);

    virtual void visit(SandUpP& sand);
    virtual void visit(SurfaceObject& sand);
    virtual void visit(SandItem& item);
};


#endif // INIT_STATE_H
