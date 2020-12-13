#include "sand.h"
#include "Visitors/object_visitor.h"

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

    size_t count = 0, step = 2;
    size_t num = size_t(x_start - x_end) + 1;

    _add_vertices_line(x_start, sand_level, z_start, step, num);
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
    if (num <= 0)
        throw error::WrongNumofVertices(__FILE__, typeid (*this).name(), __LINE__ - 1, num);

    for (size_t i = 0; i < num; i += step)
        surf_up.add_vertex(Point(x + i, y, z));
}

void Sand::accept(ObjectVisitor&)
{
    //visitor->visit(*this);
}

SceneObject *Sand::clone()
{
    return new Sand(*this);
}


SandUpP::SandUpP(const Point& pnt1, const Point& pnt2)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    Model* model_ptr = new Piramid(pnt1, pnt2, _color, _down_length, _up_length);
    _model = shared_ptr<Model>(model_ptr);
}

SandUpP::SandUpP(const SandUpP& other) : VisibleObject(other)
{
    _color = other._color;
}

SandUpP::~SandUpP() {}

void SandUpP::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* SandUpP::clone()
{
    return new SandUpP(*this);
}


SandItem::SandItem(const Point& pnt1, const Point& pnt2, const Point& pnt3, const Point& pnt_top)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    Model* model_ptr = new Piramid_3(pnt1, pnt2, pnt3, pnt_top, _color);
    _model = shared_ptr<Model>(model_ptr);
}

SandItem::SandItem(const Point& pnt_top)
{
    _color = QColor("#b0894f").rgba(); //CD853F

    Point pnt1(pnt_top.x - _h * 1.73 / 4, pnt_top.y - _h, pnt_top.z + _h / 2);
    Point pnt2(pnt_top.x + _h * 1.73 / 4, pnt_top.y - _h, pnt_top.z + _h / 2);
    Point pnt3(pnt_top.x, pnt_top.y - _h, pnt_top.z - _h);

    Model* model_ptr = new Piramid_3(pnt1, pnt2, pnt3, pnt_top, _color);
    _model = shared_ptr<Model>(model_ptr);
}

SandItem::SandItem(const SandItem& other) : VisibleObject(other)
{
    _color = other._color;
}

SandItem::~SandItem() {}


void SandItem::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* SandItem::clone()
{
    return new SandItem(*this);
}
