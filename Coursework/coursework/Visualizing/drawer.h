#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include <memory>

#include "Primitives/Point/point.h"
#include "Errors/scene_errors.h"


using RgbMap = QRgb**;
using ZMap = double**;

using namespace std;


class QDrawer
{
public:
    QDrawer(weak_ptr<QImage> image);
    explicit QDrawer(const QDrawer& other);
    virtual ~QDrawer();

    void draw_point(const Point& pnt, QRgb color);
    void make_map_plain(QRgb color);
    void fill_zmap_onedepth(double depth);

private:
    weak_ptr<QImage> _image;
    RgbMap _colormap;
    ZMap _zmap;

    int height, width;

    void _init_map();
    void _free_map();
};

#endif // DRAWER_H
