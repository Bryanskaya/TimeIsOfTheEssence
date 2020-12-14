#ifndef UPDATE_VISITOR_H
#define UPDATE_VISITOR_H

#include "object_visitor.h"
#include "Objects/sand.h"

#define K_BOOST     9.8 * 100

class UpdateVisitor : public ObjectVisitor
{
public:
    UpdateVisitor(double t_cur, double dt, double border_y, double t_limit); //shared_ptr<Updater>& updater,
    virtual ~UpdateVisitor();

    virtual void visit(Camera& camera);
    virtual void visit(LightSource& light);

    virtual void visit(Stand& stand);
    virtual void visit(Glass& glass);

    virtual void visit(SandUpP& sand);
    virtual void visit(SurfaceObject& sand);
    virtual void visit(SandItem& item);

private:
    double _t_cur;
    double _dt;
    double _general_time;
    double _border_y;
};

#endif // UPDATE_VISITOR_H
