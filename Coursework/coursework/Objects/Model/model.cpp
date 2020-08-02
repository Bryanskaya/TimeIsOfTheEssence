#include "model.h"

//constructors and destructor
Model::Model() {}

Model::~Model() {}


//methonds
void Model::normalize_n_vrt()
{
    for (auto vertex : v_arr)
        vertex->n.normalize();
}

void Model::_add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color)
{
    /*shared_ptr<Side> new_side(vertex_arr, );//
    s_arr.push_back(new_side);*/
}

void Model::_add_vertex(const Point &pnt)
{
    shared_ptr<Vertex> new_vertex(new Vertex(pnt));
    v_arr.push_back(new_vertex);
}

