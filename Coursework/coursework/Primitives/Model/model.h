#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

#include "Primitives/Vertex/vertex.h"
#include "Primitives/Side/side.h"


class Model
{
public:
    vector<shared_ptr<Vertex>> v_arr;
    vector<shared_ptr<Side>> s_arr;

    Model();
    Model(const vector<Point>& p_arr);
    explicit Model(const Model& other);

    virtual ~Model();

    void normalize_n_vrt();
    void add_vertex(const Point& pnt);
    void add_vertices(const vector<Point> &p_arr);
    void add_side(std::initializer_list<size_t> ind_arr, QRgb color);
    void add_side(vector<int> ind_arr, QRgb color);

protected:
    Point _center;

private:
    void _add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color);
};

#endif // MODEL_H
