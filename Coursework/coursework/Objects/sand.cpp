#include "sand.h"

//constructors and destructor
Sand::Sand() {}

Sand::~Sand() {}


//methonds

void Sand::create_topsurface(int x_start, int x_end, int z_start, int z_end, int sand_level, QRgb color)
{
    if (abs(x_start - x_end) != abs(z_start - z_end))
        throw error::WrongLimits(__FILE__, typeid (*this).name(), __LINE__ - 1, x_start, x_end, z_start, z_end);

    if (sand_level < 0)
        throw error::WrongLevelofSand(__FILE__, typeid (*this).name(), __LINE__ - 1, sand_level);

    size_t count = 0, step = 1;
    size_t num = size_t(x_start - x_end);

    _add_vertices_line(x_start, z_start, sand_level, step, num);
    count += num;

    for (size_t i = 0; i < num - 1; i += step)
    {
        _add_vertices_line(x_start, sand_level, z_start + i + 1, step, num);

        for (size_t j = 0; j < num - 1; j += step)
        {
            vector<size_t> ind_arr = { num * i + j, num * i + j + 1,
                                    count + j, count + j + 1 };
            surf_up.add_side(ind_arr, color);
        }

        count += num;
    }

    surf_up.normalize_n_vrt();
}

void Sand::_add_vertices_line(int x, int y, int z, size_t step, size_t num)
{
    for (size_t i = 0; i < num; i += step)
        surf_up.add_vertex(Point(x, y, z));
}

void Sand::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *Sand::clone()
{
    return new Sand(*this);
}
