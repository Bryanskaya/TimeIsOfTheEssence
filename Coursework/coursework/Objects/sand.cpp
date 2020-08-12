#include "sand.h"

//constructors and destructor
Sand::Sand() {}

Sand::~Sand() {}


//methonds

void Sand::create_surface(int x_start, int x_end, int y_start, int y_end, QRgb color)
{
    if (abs(x_start - x_end) != abs(y_start - y_end))
        throw error::WrongLimits(__FILE__, typeid (*this).name(), __LINE__ - 1, x_start, x_end, y_start, y_end);

    size_t count = 0, step = 1;
    size_t num = size_t(x_start - x_end);

    _add_vertices_line();
    count += num;

    for (size_t i = 0; i < num - 1; i += step)
    {
        _add_vertices_line();

        for (size_t j = 0; j < num - 1; j += step)
        {
            vector<size_t> ind_arr = { num * i + j, num * i + j + 1,
                                    count + j, count + j + 1 };
            surf_up.add_side(ind_arr, color);
        }

        count += num;
    }


}

void Sand::_add_vertices_line()
{
    //
}

void Sand::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *Sand::clone()
{
    return new Sand(*this);
}
