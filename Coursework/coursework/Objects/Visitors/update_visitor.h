#ifndef UPDATE_VISITOR_H
#define UPDATE_VISITOR_H

#include "object_visitor.h"
#include "Update/updater.h"


class UpdateVisitor : public ObjectVisitor
{
public:
    UpdateVisitor(shared_ptr<Updater>& updater); // время, координата-у нижней подставки
    virtual ~UpdateVisitor();


    virtual void visit(Camera& camera) = 0;
    virtual void visit(LightSource& light) = 0;

    virtual void visit(Hourglass& hourglass) = 0;
    virtual void visit(Stand& stand) = 0;
    virtual void visit(Glass& glass) = 0;

    virtual void visit(SandUpP& sand) = 0;
    virtual void visit(SurfaceObject& sand) = 0;
    virtual void visit(SandItem& item) = 0;

    virtual void visit(DemoBox& demobox) = 0;



private:
    shared_ptr<Updater> _updater;
    double temp_time = 0;
    double d_time;
};

#endif // UPDATE_VISITOR_H
