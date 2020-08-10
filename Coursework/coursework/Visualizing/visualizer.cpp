#include "visualizer.h"

Visualizer::Visualizer() {}

Visualizer::Visualizer(shared_ptr<QDrawer>& drawer) :
    _draw(drawer) {}

Visualizer::~Visualizer() {}


void Visualizer::set_draw(const shared_ptr<QDrawer> &drawer)
{
    _draw = drawer;
}

void Visualizer::set_light(const LightSource &light)
{
    _light = light;
}

void Visualizer::set_camera(const Camera &camera)
{
    _camera = camera;
}

void Visualizer::draw_model(const Model &model)
{
    //
}

void Visualizer::show_scene()
{
    //
}

void Visualizer::clear()
{
    _draw->fill_zmap_onedepth(-100);
    _draw->make_map_plain(QColor(Qt::black).rgba());
}
