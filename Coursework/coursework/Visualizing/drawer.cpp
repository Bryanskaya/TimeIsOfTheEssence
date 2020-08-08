#include "drawer.h"

QDrawer::QDrawer(weak_ptr<QImage> image)
{
    if (image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QSize size = image.lock()->size();

    _image = image;
    height = size.height();
    width = size.width();

    _init_map();
}

QDrawer::QDrawer(const QDrawer& other)
{
    _image = other._image;
    height = other.height;
    width = other.width;

    _init_map();
}

QDrawer::~QDrawer() {   _free_map();    }

void QDrawer::_init_map()
{
    _colormap = new QRgb*[this->height];

    for (int i = 0; i < this->height; i++)
        _colormap[i] = new QRgb[this->width];

    _zmap = new double*[this->height];

    for (int i = 0; i < this->height; i++)
        _zmap[i] = new double[this->width];
}

void QDrawer::_free_map()
{
    for (int i = 0; i < this->height; i++)
        delete _colormap[i];
    delete _colormap;
}

void QDrawer::draw_point(const Point &pnt, QRgb color)
{
    int x = static_cast<int>(pnt.x);
    int y = static_cast<int>(pnt.y);

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
    }
}
