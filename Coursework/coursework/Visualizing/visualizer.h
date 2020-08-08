#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "drawer.h"
#include "Objects/camera.h"
#include "Objects/light_source.h"
#include "Primitives/Model/model.h"


class Visualizer
{
public:
    Visualizer();
    Visualizer(shared_ptr<QDrawer>& drawer);

    virtual ~Visualizer();

    void set_draw(const shared_ptr<QDrawer>& drawer);
    void set_camera(const Camera& camera);
    void set_light(const LightSource& light);

    void draw_model(const Model& model);

    void clear();

private:
    shared_ptr<QDrawer> _draw;
    Camera _camera;
    LightSource _light;
};

#endif // VISUALIZER_H
