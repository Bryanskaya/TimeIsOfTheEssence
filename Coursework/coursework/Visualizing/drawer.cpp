#include "drawer.h"

#include <iostream>
using namespace std;


QRgb get_color(QRgb color, double itensity)
{
    QColor new_color(color);
    int r, g, b;

    new_color.getRgb(&r, &g, &b);

    r *= itensity;
    g *= itensity;
    b *= itensity;

    new_color.setRgb(r, g, b);

    return new_color.rgba();
}

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

    for (int i = 0; i < this->height; i++)
        delete _zmap[i];
    delete _zmap;
}

void QDrawer::draw_point(const Point &pnt, QRgb color)
{
    int x = static_cast<int>(pnt.x);
    if (x < 0 || x > width)
        return;

    int y = static_cast<int>(pnt.y);
    if (y < 0 || y > height)
        return;

    cout << "draw point" << endl;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
        cout << "change" << endl;
    }
}

void QDrawer::draw_point(const Point &pnt, QRgb color, double itensity)
{
    int x = static_cast<int>(pnt.x);
    if (x < 0 || x > width)
        return;

    int y = static_cast<int>(pnt.y);
    if (y < 0 || y > height)
        return;

    cout << "draw point" << endl;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = get_color(color, itensity);
        cout << "change" << endl;
    }
}

void QDrawer::make_map_plain(QRgb color)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _colormap[i][j] = color;
}

void QDrawer::fill_zmap_onedepth(double depth)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _zmap[i][j] = depth;
}

void QDrawer::move_to_qimage()
{
    if (_image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QImage& img = *_image.lock();
    size_t row_size = static_cast<size_t>(width) * sizeof (QRgb);

    for (int i = 0; i < height; i++)
        memcpy(img.scanLine(i), &_colormap[i][0], row_size);

}
