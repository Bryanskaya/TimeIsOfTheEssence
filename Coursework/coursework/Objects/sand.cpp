#include "sand.h"

//constructors and destructor
Sand::Sand() {}

Sand::~Sand() {}


//methonds

void Sand::create_surface(int left_limit, int right_limit, QRgb color)
{
    if (left_limit > right_limit)
        throw error::WrongLimits(__FILE__, typeid (*this).name(), __LINE__ - 1, left_limit, right_limit);

    int count = 0, step = 1;
    int num = right_limit - left_limit;

    _add_vertices_line(); //
    count += num;

    for (int i = 0; i < num - 1; i += step)
    {
        _add_vertices_line();

        for (int j = 0; j < num - 1; j += step)
        {
            vector<int> ind_arr = { num * i + j, num * i + j + 1,
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
