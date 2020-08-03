#include "model.h"

//constructors and destructor
Model::Model() {}

Model::Model(const Model& other)
{
    _center = other._center;


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
    shared_ptr<Side> new_side(new Side(vertex_arr, color, _center));
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




