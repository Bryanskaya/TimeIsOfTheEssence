#ifndef GLASS_H
#define GLASS_H

#include "simple_object.h"


class Glass : public VisibleObject
{
public:
    Model model;
    double k_ref;
    double k_art;

    Glass();

    virtual ~Glass();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // GLASS_H
