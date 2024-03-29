#ifndef SIDE_H
#define SIDE_H

#include <QColor>
#include <memory>
#include <vector>

#include "Primitives/Vertex/vertex.h"
#include "Primitives/Vector/vector.h"
#include "Errors/side_errors.h"


class Side
{
public:
    vector<shared_ptr<Vertex>> vertex_arr;
    Vector n;
    QRgb color;

    Side();
    Side(vector<shared_ptr<Vertex>> vertex_arr, const Point& control_p, QRgb color);

    virtual ~Side();

    void n_correction(const Point& control_p);
    void set_vert_normal(const Point& control_p);

private:
    void _find_normal();
};

#endif // SIDE_H
