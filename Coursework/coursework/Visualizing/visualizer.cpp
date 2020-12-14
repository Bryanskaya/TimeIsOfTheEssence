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
    int max_y = _draw->get_max_y();
    int min_y = _draw->get_min_y();
    int min_x = _draw->get_min_x();
    int max_x = _draw->get_max_x();

    for (auto side : model.s_arr)
    {
        ProjectedSide p_side;

        _project_side(p_side, side->vertex_arr);

        if (!p_side.edges.size())
            continue;

        p_side.init();

        while (p_side.active_edges.size() && p_side.y_temp > max_y)
            p_side.step();

        while (p_side.active_edges.size() && p_side.y_temp > min_y)
        {
            double x = p_side.active_edges[0].x;
            double z = p_side.active_edges[0].z;
            double i = p_side.active_edges[0].i;

            double dz = (z - p_side.active_edges[1].z) / (x - p_side.active_edges[1].x);
            double di = (i - p_side.active_edges[1].i) / (x - p_side.active_edges[1].x);

            Point pnt(x, p_side.y_temp, z);

            //for (; pnt.x < p_side.active_edges[1].x; pnt.x++)
            for (; pnt.x < min_x; pnt.x++)
            {
                pnt.z += dz;
                i += di;
            }

            double st = min(p_side.active_edges[1].x, static_cast<double>(max_x));

            //for (; pnt.x < p_side.active_edges[1].x; pnt.x++)
            for (; pnt.x < st; pnt.x++)
            {
                _draw->draw_point(pnt, side->color, i);
                pnt.z += dz;
                i += di;
            }

            p_side.step();
        }
    }
}

void Visualizer::draw_intensity(const Model &model, double tr)  //hi
{
    int max_y = _draw->get_max_y();
    int min_y = _draw->get_min_y();
    int min_x = _draw->get_min_x();
    int max_x = _draw->get_max_x();


    for (auto side : model.s_arr)
    {
        ProjectedSide p_side;
        Vector n = side->n;

        _project_side(p_side, side->vertex_arr);

        if (!p_side.edges.size())
            continue;

        p_side.init();

        while (p_side.active_edges.size() && p_side.y_temp > max_y)
            p_side.step();

        while (p_side.active_edges.size() && p_side.y_temp > min_y)
        {
            double x = p_side.active_edges[0].x;
            double z = p_side.active_edges[0].z;
            double i = p_side.active_edges[0].i;

            double dz = (z - p_side.active_edges[1].z) / (x - p_side.active_edges[1].x);
            double di = (i - p_side.active_edges[1].i) / (x - p_side.active_edges[1].x);

            Point pnt(x, p_side.y_temp, z);

            //for (; pnt.x < p_side.active_edges[1].x; pnt.x++)
            for (; pnt.x < min_x; pnt.x++)
            {
                pnt.z += dz;
                i += di;
            }

            Point invt_pnt1 = _invert_project_point(pnt); //
            Point invt_pnt2(p_side.active_edges[1].x, p_side.y_temp, p_side.active_edges[1].z); //
            invt_pnt2 = _invert_project_point(invt_pnt2); //

            double dx_invt = (invt_pnt2.x - invt_pnt1.x) / (pnt.x - p_side.active_edges[1].x);//
            double dy_invt = (invt_pnt2.y - invt_pnt1.y) / (pnt.x - p_side.active_edges[1].x);//
            double dz_invt = (invt_pnt2.z - invt_pnt1.z) / (pnt.x - p_side.active_edges[1].x);//

            double st = min(p_side.active_edges[1].x, static_cast<double>(max_x));

            for (; pnt.x < st; pnt.x++)
            {
                _draw->correct_intensity(pnt, i / 0.95 + _glare_i(invt_pnt1, n), tr);
                //_draw->correct_intensity(pnt, i / 1.5, tr);

                pnt.z += dz;
                i += di;
                invt_pnt1.x += dx_invt;
                invt_pnt1.y += dy_invt;
                invt_pnt1.z += dz_invt;
            }

            p_side.step();
        }
    }
}

double Visualizer::_glare_i(const Point& pnt, const Vector& n)
{
    Vector vct1(pnt, _light.get_position());
    Vector vct2(pnt, _camera.get_position());

    vct1.normalize();    
    vct2.normalize();

    Vector res((vct1.x + vct2.x) / 2, (vct1.y + vct2.y) / 2, (vct1.z + vct2.z) / 2); //проверить

    double i = abs(res.scalar_mult(n));

    i = pow(i, K_GLARE) * 5;

    return i;
}

void Visualizer::show_scene()
{
    _draw->move_to_qimage();
}

void Visualizer::clear()
{
    _draw->fill_zmap_onedepth(-10000);
    _draw->make_map_plain(QColor("#74737a").rgba()); //4682B4
    _draw->make_itenmap_plain(0.9);
}

Point Visualizer::_project_point(const Point &pnt)
{
    Point result = pnt;
    Point camera = _camera.get_position();
    double k;

    result.rotate(camera, _camera.get_direction());

    if (result.z >= camera.z)
        throw error::BehindScene(__FILE__, typeid (*this).name(), __LINE__ - 1);
    else
        k = 500 / (camera.z - result.z);

    //k = 500 / sqrt(camera.x * camera.x + camera.z * camera.z);
    result.x = (result.x - camera.x) * k;
    result.y = (result.y - camera.y) * k;

    return result;
}

Point Visualizer::_invert_project_point(const Point &pnt)
{
    Point result = pnt;
    Point camera = _camera.get_position();
    double k;

    k = 500 / (camera.z - result.z);

    //k = 500 / sqrt(camera.x * camera.x + camera.z * camera.z);
    result.x = result.x / k + camera.x;
    result.y = result.y / k + camera.y;

    Vector temp_camera = _camera.get_direction();
    temp_camera.invert();
    result.invert_rotate(camera, temp_camera); //

    return result;
}

void Visualizer::_project_side(ProjectedSide &side, const vector<shared_ptr<Vertex>>& vertex_arr)
{
    for (size_t i = 0; i < vertex_arr.size(); i++)
    {
        Point pnt1 = _project_point(*vertex_arr[i]);
        Point pnt2 = _project_point(*vertex_arr[(i + 1) % vertex_arr.size()]);

        double i1 = _calculate_intensity(*vertex_arr[i]);
        double i2 = _calculate_intensity(*vertex_arr[(i + 1) % vertex_arr.size()]);

        side.add_edge(ProjectedEdge(pnt1, i1, pnt2, i2));
    }
}

double Visualizer::_calculate_intensity(const Vertex &v)
{
    Vector vect(v, _light.get_position());

    double i = vect.scalar_mult(v.n) / vect.get_length() / (vect.get_length() + 50);

    i = i * K_LIGHTSOURCE * _light.get_itensity();

    i = min(i, 1.0);
    return max(i, 0.1);
}
