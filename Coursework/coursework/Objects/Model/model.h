#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

#include "Objects/Vertex/vertex.h"
#include "Objects/Side/side.h"


class Model
{
public:
    Model();
    explicit Model(const Model& other);//

    virtual ~Model();

    void normalize_n_vrt();

protected:
    vector<shared_ptr<Vertex>> v_arr;
    vector<shared_ptr<Side>> s_arr;

private:
    void _add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color);
    void _add_vertex(const Point& pnt);
};

#endif // MODEL_H
