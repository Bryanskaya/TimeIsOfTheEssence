#include "visualizer.h"

#include <iostream>


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
    for (auto pnt : model.v_arr)
    {
        Point proj_pnt = _project_point(*pnt);
        _draw->draw_point(proj_pnt, model.s_arr[0]->color);
    }

    int i = 0;

    for (auto side : model.s_arr)
    {
        if (i == 1)
            break;

        cout << "help0 " << model.s_arr.size() << endl;
        ProjectedSide p_side;

        cout << "help1" << endl;

        _project_side(p_side, side->vertex_arr);
        cout << "help2" << endl;

        p_side.init();

        cout << "help3" << endl;

        while (!p_side.active_edges.size())
        {
            double x = p_side.active_edges[0].x;
            double z = p_side.active_edges[0].z;

            double dz = (z - p_side.active_edges[1].z) / (x - p_side.active_edges[1].x);

            Point pnt(x, p_side.y_temp, z);

            for (; pnt.x < p_side.active_edges[1].x; pnt.x++)
            {
                _draw->draw_point(pnt, side->color);
                pnt.z += dz;
            }
        }
        i++;
    }

}

void Visualizer::show_scene()
{
    _draw->move_to_qimage();
}

void Visualizer::clear()
{
    _draw->fill_zmap_onedepth(-10000);
    _draw->make_map_plain(QColor(Qt::black).rgba());
}

Point Visualizer::_project_point(const Point &pnt)
{
    Point result = pnt;
    Point camera = _camera.get_position();
    double k;

    result.rotate(camera, _camera.get_direction());

    if (fabs(result.z - camera.z) < EPS)
        k = 1e20;
    else
        k = 250 / (camera.z - result.z);

    result.x = camera.x + (result.x - camera.x) * k;
    result.y = camera.y + (result.y - camera.y) * k;

    //std::cout << "Point " << pnt.x << " " << pnt.y << " " << pnt.z << endl;
    //std::cout << "projected point " << result.x << " " << result.y << " " << result.z << endl;

    return result;
}

void Visualizer::_project_side(ProjectedSide &side, const vector<shared_ptr<Vertex>>& vertex_arr)
{
    for (size_t i = 0; i < vertex_arr.size(); i++)
    {
        Point pnt1 = _project_point(*vertex_arr[i]);
        Point pnt2 = _project_point(*vertex_arr[(i + 1) % vertex_arr.size()]);

        side.add_edge(ProjectedEdge(pnt1, pnt2));
        std::cout << "**** " << i << endl;
    }
}
