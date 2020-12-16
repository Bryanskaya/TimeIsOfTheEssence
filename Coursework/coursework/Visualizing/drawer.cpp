#include "drawer.h"

#include <iostream>
using namespace std;


QRgb get_color(QRgb color, double itensity)
{
    QColor new_color(color);
    int r, g, b;

    new_color.getRgb(&r, &g, &b);

    if (itensity <= 1)
    {
        r *= itensity;
        g *= itensity;
        b *= itensity;
    }
    else
    {
        r = min<double>(r * itensity, 255);
        g = min<double>(g * itensity, 255);
        b = min<double>(b * itensity, 255);
    }

    new_color.setRgb(r, g, b);

    return new_color.rgba();
}

double get_iten_through_glass(double itensity_obj, double itensity_glass, double t) //hi
{
    return t * itensity_glass + (1 - t) * itensity_obj;
}

QDrawer::QDrawer(weak_ptr<QImage> image)
{
    if (image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QSize size = image.lock()->size();

    _image = image;
    height = size.height();
    width = size.width();

    half_height = height / 2;
    half_width = width / 2;

    _init_map();
}

QDrawer::QDrawer(const QDrawer& other)
{
    _image = other._image;
    height = other.height;
    width = other.width;
    half_height = other.half_height;
    half_width = other.half_width;

    _init_map();
}

QDrawer::~QDrawer() {   _free_map();    }

void QDrawer::_init_map()
{
    _colormap = new QRgb*[this->height];
    _zmap = new double*[this->height];
    //_zmap_shd = new double*[this->height];
    _itenmap = new double*[this->height];

    for (int i = 0; i < this->height; i++)
    {
        _zmap[i] = new double[this->width];
        //_zmap_shd[i] = new double[this->width];
        _colormap[i] = new QRgb[this->width];
        _itenmap[i] = new double[this->width];
    }
}

void QDrawer::_free_map()
{
    for (int i = 0; i < this->height; i++)
    {
        delete _colormap[i];
        delete _zmap[i];
        //delete _zmap_shd[i];
        delete  _itenmap[i];
    }

    delete _colormap;
    delete _zmap;
    //delete _zmap_shd;
    delete  _itenmap;
}

void QDrawer::draw_point(const Point &pnt, QRgb color)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
    }
}

void QDrawer::draw_point_shd(const Point &pnt)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    /*if (pnt.z > _zmap_shd[y][x])
        _zmap_shd[y][x] = pnt.z;*/
}


void QDrawer::draw_point(const Point &pnt, QRgb color, double itensity)//, const Point &pnt_shd)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
        _itenmap[y][x] = itensity;

        /*int x_shd = static_cast<int>(pnt_shd.x) + half_width;
        if (x_shd < 0 || x_shd >= width)
            return;

        int y_shd = -static_cast<int>(pnt_shd.y) + half_height;
        if (y_shd < 0 || y_shd >= height)
            return;

        if (pnt_shd.z + 10 < _zmap_shd[y_shd][x_shd])
            _itenmap[y][x] = 0.1;*/
    }
}

void QDrawer::correct_intensity(const Point& pnt, double i, double tr)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z + 10 > _zmap[y][x])
        _itenmap[y][x] = get_iten_through_glass(_itenmap[y][x], i, tr);
}

void QDrawer::make_map_plain(QRgb color)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _colormap[i][j] = color;
}

void QDrawer::make_itenmap_plain(double iten)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _itenmap[i][j] = iten;
}

void QDrawer::fill_zmap_onedepth(double depth)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
        {
            _zmap[i][j] = depth;
            //_zmap_shd[i][j] = depth;
        }
}

void QDrawer::move_to_qimage()
{
    if (_image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QImage& img = *_image.lock();
    size_t row_size = static_cast<size_t>(width) * sizeof (QRgb);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            _colormap[i][j] = get_color(_colormap[i][j], _itenmap[i][j]);
        }
        memcpy(img.scanLine(i), &_colormap[i][0], row_size);
    }
}

int QDrawer::get_max_y()
{
    return half_height;
}

int QDrawer::get_min_y()
{
    return -half_height;
}

int QDrawer::get_min_x()
{
    return -half_width;
}

int QDrawer::get_max_x()
{
    return half_width;
}
