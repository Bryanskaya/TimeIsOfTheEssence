#include "surface.h"

//constructors and destructor
Surface::Surface(QRgb color) : _color(color) {}

Surface::~Surface() {}


Point Surface::find_min_pnt(const Point& pnt1, const Point& pnt2)
{
    Point result;

    result.x = min(pnt1.x, pnt2.x);
    result.y = min(pnt1.y, pnt2.y);
    result.z = min(pnt1.z, pnt2.z);

    return result;
}

Point Surface::find_max_pnt(const Point& pnt1, const Point& pnt2)
{
    Point result;

    result.x = max(pnt1.x, pnt2.x);
    result.y = max(pnt1.y, pnt2.y);
    result.z = max(pnt1.z, pnt2.z);

    return result;
}

void Surface::find_center(const Point&, const Point&) {}



SurfaceUp::SurfaceUp(QRgb color, const Point& pnt1, const Point& pnt2, const Point& pnt3) : Surface(color)
{
    Point pnt_min = find_min_pnt(pnt1, pnt2);
    Point pnt_max = find_max_pnt(pnt1, pnt2);
    find_center(pnt3, pnt_max);

    _height = abs(pnt1.y - pnt3.y);

    size_t num_x = static_cast<int>(round((pnt_max.x - pnt_min.x) / _step));
    size_t num_z = static_cast<int>(round((pnt_max.z - pnt_min.z) / _step));

    if ((num_x + 1) % 2)
        num_x += 1;
    if ((num_z + 1) % 2)
        num_z += 1;

    double step_x = (pnt_max.x - pnt_min.x) / num_x;
    double step_z = (pnt_max.z - pnt_min.z) / num_z;

    Point pnt = pnt_min;
    add_points_row(pnt, step_z, num_z);

    for (size_t i = 0; i < num_x; i++)
    {
        pnt.x += step_x;

        add_points_row(pnt, step_z, num_z);
        create_polygons(num_z, i);
    }
    _num_nodes = v_arr.size();

    add_carcas(pnt1, pnt3);

    if ((num_z + 1) % 2)
    {
        for (size_t i = 1; i * 2 < (num_z + 2); i++)
            add_side({i - 1, i, _num_nodes}, _color);
        for (size_t i = (num_z + 2) / 2; i < num_z + 1; i++)
            add_side({i - 1, i, _num_nodes + 1}, _color);
        add_side({_num_nodes, num_z / 2, _num_nodes + 1}, _color);

        size_t d = num_x * (num_z + 1);

        for (size_t i = 1; i * 2 < (num_z + 2); i++)
            add_side({i - 1 + d, i + d, _num_nodes + 3}, _color);
        for (size_t i = (num_z + 2) / 2; i < num_z + 1; i++)
            add_side({i - 1 + d, i + d, _num_nodes + 2}, _color);
        add_side({_num_nodes + 3, num_z / 2 + d, _num_nodes + 2}, _color);
    }
    else
    {
        for (size_t i = 1; i * 2 < (num_z + 1); i++)
            add_side({i - 1, i, _num_nodes}, _color);
        for (size_t i = (num_z + 1) / 2 + 1; i < num_z + 1; i++)
            add_side({i - 1, i, _num_nodes + 1}, _color);
        add_side({(num_z + 1) / 2 - 1, (num_z + 1) / 2, _num_nodes + 1, _num_nodes}, _color);

        size_t d = num_x * (num_z + 1);

        for (size_t i = 1; i * 2 < (num_z + 1); i++)
            add_side({i - 1 + d, i + d, _num_nodes + 3}, _color);
        for (size_t i = (num_z + 1) / 2 + 1; i < num_z + 1; i++)
            add_side({i - 1 + d, i + d, _num_nodes + 2}, _color);
        add_side({(num_z + 1) / 2 - 1 + d, (num_z + 1) / 2 + d, _num_nodes + 2, _num_nodes + 3}, _color);
    }

    _num_nodes += 4;
    if ((num_x + 1) % 2)
    {
        size_t n = (num_x + 1) * (num_z + 1);
        size_t step = num_z + 1;

        for (size_t i = step; i * 2 < n + step; i += step)
            add_side({i - step, i, _num_nodes}, _color);
        for (size_t i = (n + step) / 2; i < n; i += step)
            add_side({i - step, i, _num_nodes + 3}, _color);
        add_side({_num_nodes, (n - step) / 2, _num_nodes + 3}, _color);

        size_t d = num_z;

        for (size_t i = step; i * 2 < n + step; i += step)
            add_side({i - step + d, i + d, _num_nodes + 1}, _color);
        for (size_t i = (n + step) / 2; i < n; i += step)
            add_side({i - step + d, i + d, _num_nodes + 2}, _color);
        add_side({_num_nodes + 1, (n - step) / 2 + d, _num_nodes + 2}, _color);
    }
    else
    {
        size_t n = (num_x + 1) * (num_z + 1);
        size_t step = num_z + 1;

        for (size_t i = step; i * 2 < n; i += step)
            add_side({i - step, i, _num_nodes}, _color);
        for (size_t i = n / 2 + step; i < n; i += step)
            add_side({i - step, i, _num_nodes + 3}, _color);
        add_side({n / 2 - step, n / 2, _num_nodes + 3, _num_nodes}, _color);

        size_t d = num_z;

        for (size_t i = step; i * 2 < n; i += step)
            add_side({i - step + d, i + d, _num_nodes + 1}, _color);
        for (size_t i = n / 2 + step; i < n; i += step)
            add_side({i - step + d, i + d, _num_nodes + 2}, _color);
        add_side({n / 2 - step + d, n / 2 + d, _num_nodes + 2, _num_nodes + 1}, _color);
    }

    normalize_n_vrt();

    /*correct_vert(_num_nodes);
    correct_vert(_num_nodes + 1);
    correct_vert(_num_nodes + 2);
    correct_vert(_num_nodes + 3);*/
}

void SurfaceUp::correct_vert(size_t ind)
{
    v_arr[ind]->n.y = 0;
    double length = v_arr[ind]->n.get_length();
    v_arr[ind]->n.x /= length;
    v_arr[ind]->n.z /= length;
}

void SurfaceUp::add_carcas(const Point &, const Point &pnt2)
{
    add_vertex(Point(pnt2.x, pnt2.y, pnt2.z - _up_length));
    add_vertex(Point(pnt2.x + _up_length, pnt2.y, pnt2.z - _up_length));
    add_vertex(Point(pnt2.x + _up_length, pnt2.y, pnt2.z));
    add_vertex(pnt2);

    add_vertex(Point(pnt2.x, pnt2.y, pnt2.z - _up_length));
    add_vertex(Point(pnt2.x + _up_length, pnt2.y, pnt2.z - _up_length));
    add_vertex(Point(pnt2.x + _up_length, pnt2.y, pnt2.z));
    add_vertex(pnt2);
}


SurfaceUp::~SurfaceUp(){}

void SurfaceUp::add_points_row(const Point& pnt_min, double step, int num)
{
    Point pnt = pnt_min;

    for (int i = 0; i < num + 1; i++)
    {
        add_vertex(pnt);
        pnt.z += step;
    }
}

void SurfaceUp::create_polygons(int num, int cur_i)
{
    size_t p1 = cur_i * (num + 1);
    size_t p2 = cur_i * (num + 1) + 1;
    size_t p3 = (cur_i + 1) * (num + 1) + 1;
    size_t p4 = (cur_i + 1) * (num + 1);

    for (int i = 0; i < num; i++)
    {
        add_side({ p1, p2, p3, p4 }, _color);

        p1 += 1;
        p2 += 1;
        p3 += 1;
        p4 += 1;
    }
}

void SurfaceUp::find_center(const Point &pnt1, const Point &pnt2)
{
    //_center.x = (pnt1.x + pnt2.x) / 2;
    _center.x = 0;
    _center.y = (pnt1.y + pnt2.y) / 2;
    //_center.z = (pnt1.z + pnt2.z) / 2;
    _center.z = 0;
}



SurfaceDown::SurfaceDown(QRgb color, const Point& pnt1, const Point& pnt2) : Surface(color)
{
    Point pnt_min = find_min_pnt(pnt1, pnt2);
    Point pnt_max = find_max_pnt(pnt1, pnt2);
    find_center(pnt1);

    size_t num_x = static_cast<int>(round((pnt_max.x - pnt_min.x) / _step));
    size_t num_z = static_cast<int>(round((pnt_max.z - pnt_min.z) / _step));

    double step_x = (pnt_max.x - pnt_min.x) / num_x;
    double step_z = (pnt_max.z - pnt_min.z) / num_z;

    Point pnt = pnt_min;
    add_points_row(pnt, step_z, num_z);

    for (size_t i = 0; i < num_x; i++)
    {
        pnt.x += step_x;

        add_points_row(pnt, step_z, num_z);
        create_polygons(num_z, i);
    }
    _num_nodes = v_arr.size();

    normalize_n_vrt();
}

void SurfaceDown::correct_vert(size_t ind)
{
    v_arr[ind]->n.y = 0;
    double length = v_arr[ind]->n.get_length();
    v_arr[ind]->n.x /= length;
    v_arr[ind]->n.z /= length;
}

SurfaceDown::~SurfaceDown(){}

void SurfaceDown::add_points_row(const Point& pnt_min, double step, int num)
{
    Point pnt = pnt_min;

    for (int i = 0; i < num + 1; i++)
    {
        add_vertex(pnt);
        pnt.z += step;
    }
}

void SurfaceDown::create_polygons(int num, int cur_i)
{
    size_t p1 = cur_i * (num + 1);
    size_t p2 = cur_i * (num + 1) + 1;
    size_t p3 = (cur_i + 1) * (num + 1) + 1;
    size_t p4 = (cur_i + 1) * (num + 1);

    for (int i = 0; i < num; i++)
    {
        add_side({ p1, p2, p3, p4 }, _color);

        p1 += 1;
        p2 += 1;
        p3 += 1;
        p4 += 1;
    }
}

void SurfaceDown::find_center(const Point &pnt)
{
    _center.x = 0;
    _center.y = pnt.y - 30;
    _center.z = 0;
}
