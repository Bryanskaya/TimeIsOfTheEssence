#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include <iostream>

#include "Scene/facade.h"
#include "Commands/all_commands.h"


using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PushUp_clicked();

    void on_PushRight_clicked();

    void on_PushDown_clicked();

    void on_PushLeft_clicked();

    void on_Start_clicked();

    void on_PushCloser_clicked();

    void on_PushFurther_clicked();

    void keyPressEvent(QKeyEvent*);


    void on_PushLightUp_clicked();

    void on_PushLightDown_clicked();

    void on_PushLightLeft_clicked();

    void on_PushLightRight_clicked();

    void on_PushLightCloser_clicked();

    void on_PushLightFurther_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<QGraphicsScene> _qscene;
    Facade _scene;

    QSize _size_scene;
    shared_ptr<QImage> _image;
    QGraphicsPixmapItem* q_pmap;
    RgbMap _rgb_map;
    QColor _draw_color = Qt::lightGray;

    void wheelEvent(QWheelEvent *event);

    void _set_binds_input(void);
    void _show_error(const char* error);
    void _move_camera(double x, double y, double z);
    void _move_light(double x, double y, double z);
    void _rotate_camera(double x, double y, double z);
    void _draw_scene();
};

#endif // MAINWINDOW_H
