#ifndef SAND_H
#define SAND_H

#include <vector>

#include "simple_object.h"
#include "Errors/hourglass_error.h"


class Sand : public VisibleObject
{
public:
    Model model_up;
    Model surf_up;
    Model model_down;
    Model surf_down;
    vector<Model> models_arr;

    Sand();

    virtual ~Sand();

    void create_surface(int x_start, int x_end, int y_start, int y_end, QRgb color);

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();

private:
    double _speed_y = 10;

    void _add_vertices_line();
};

#endif // SAND_H
