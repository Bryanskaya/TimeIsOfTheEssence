#include "model.h"

//constructors and destructor
Model::Model() {}

Model::Model(const vector<Point>& p_arr)
{
    this->add_vertices(p_arr);

    _center.x = 0;
    _center.y = 0;
    _center.z = 0;

    for (Point pnt : p_arr)
    {
        _center.x += pnt.x;
        _center.y += pnt.y;
        _center.z += pnt.z;
    }

    _center.x /= p_arr.size();
    _center.y /= p_arr.size();
    _center.z /= p_arr.size();
}

Model::Model(const Model& other)
{
    _center = other._center;

    for (auto vertex : other.v_arr)
        this->add_vertex(*vertex);

    for (auto side : other.s_arr)
        this->_add_side(side->vertex_arr, side->color);
}

Model::~Model() {}


//methonds
void Model::normalize_n_vrt()
{
    for (auto vertex : v_arr)
        vertex->n.normalize();
}

void Model::_add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color)
{
    shared_ptr<Side> new_side(new Side(vertex_arr, _center, color));
    s_arr.push_back(new_side);
}

void Model::add_vertex(const Point &pnt)
{
    shared_ptr<Vertex> new_vertex(new Vertex(pnt));
    v_arr.push_back(new_vertex);
}

void Model::add_vertices(const vector<Point> &p_arr)
{
    for (Point point : p_arr)
        add_vertex(point);
}

void Model::add_side(std::initializer_list<size_t> ind_arr, QRgb color)
{
    vector<shared_ptr<Vertex>> new_side;

    for (size_t i : ind_arr)
    {
        if (i >= v_arr.size())
            throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1);

        new_side.push_back(v_arr[i]);
    }

    _add_side(new_side, color);
}

void Model::add_side(vector<int> ind_arr, QRgb color)
{
    vector<shared_ptr<Vertex>> new_side;

    for (auto i : ind_arr)
    {
        if (i >= v_arr.size())
            throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1);

        new_side.push_back(v_arr[i]);
    }

    _add_side(new_side, color);
}

