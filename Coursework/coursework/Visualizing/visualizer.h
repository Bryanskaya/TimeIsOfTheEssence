#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "drawer.h"
#include "projecting.h"
#include "Objects/camera.h"
#include "Objects/light_source.h"
#include "Primitives/Model/model.h"
#include "Errors/scene_errors.h"



class Visualizer
{
public:
    Visualizer();
    Visualizer(shared_ptr<QDrawer>& drawer);

    ~Visualizer();

    void set_draw(const shared_ptr<QDrawer>& drawer);
    void set_camera(const Camera& camera);
    void set_light(const LightSource& light);

    void draw_model(const Model& model);
    void draw_intensity(const Model &model, double tr);  //hi

    void show_scene();
    void clear();

private:
    shared_ptr<QDrawer> _draw;
    Camera _camera;
    LightSource _light;

    Point _project_point(const Point& pnt);
    Point _invert_project_point(const Point &pnt);
    void _project_side(ProjectedSide &side, const vector<shared_ptr<Vertex>>& vertex_arr);
    double _calculate_intensity(const Vertex &v);
    double _glare_i(const Point& pnt, const Vector &n);
};

#endif // VISUALIZER_H
