#ifndef SAND_H
#define SAND_H

#include <vector>

#include "simple_object.h"


class Sand : public VisibleObject
{
public:
    Model model_up;
    Model model_down;
    vector<Model> models_arr;

    Sand();

    virtual ~Sand();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // SAND_H
