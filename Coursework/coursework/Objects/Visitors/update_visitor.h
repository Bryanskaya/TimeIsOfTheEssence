#ifndef UPDATE_VISITOR_H
#define UPDATE_VISITOR_H

#include "object_visitor.h"
#include "Update/updater.h"


class UpdateVisitor : public ObjectVisitor
{
public:
    UpdateVisitor(double t, double border); //shared_ptr<Updater>& updater,
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

    void set_border(double border);
    void set_temp_time(double t);

    void _move_sand_items(shared_ptr<SandItem> &item, double step);

private:
    //shared_ptr<Updater> _updater;
    double _temp_time = 0;
    double _dtime;
    double _border;
};

#endif // UPDATE_VISITOR_H
