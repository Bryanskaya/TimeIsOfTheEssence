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
    _itenmap = new double*[this->height];//hi

    for (int i = 0; i < this->height; i++)
    {
        _zmap[i] = new double[this->width];
        _colormap[i] = new QRgb[this->width];
        _itenmap[i] = new double[this->width]; //hi
    }
}

void QDrawer::_free_map()
{
    for (int i = 0; i < this->height; i++)
    {
        delete _colormap[i];
        delete _zmap[i];
        delete  _itenmap[i]; //hi
    }

    delete _colormap;
    delete _zmap;
    delete  _itenmap; //hi
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

void QDrawer::draw_point(const Point &pnt, QRgb color, double itensity)
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
        //_colormap[y][x] = get_color(color, itensity);
        _colormap[y][x] = color;
        _itenmap[y][x] = itensity; //hi
    }
}

void QDrawer::correct_intensity(const Point& pnt, double i, double tr) //hi
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z > _zmap[y][x])
        _itenmap[y][x] = get_iten_through_glass(_itenmap[y][x], i, tr);
}

void QDrawer::make_map_plain(QRgb color)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _colormap[i][j] = color;
}

void QDrawer::make_itenmap_plain(double iten) //hi
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _itenmap[i][j] = iten;
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
    {
        for (int j = 0; j < width; j++)
        {
            if (_itenmap[i][j] < 0)
                cout << _itenmap[i][j] << " " << i << " " << j << endl;
            _colormap[i][j] = get_color(_colormap[i][j], _itenmap[i][j]);
        }
        memcpy(img.scanLine(i), &_colormap[i][0], row_size);
    }

    /*for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cout << _itenmap[i][j] << " ";
        cout << endl;
    }*/

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
