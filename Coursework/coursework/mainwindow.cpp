#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>
#include <QGraphicsView>

RgbMap create_rgb_map(int width, int height)
{
    RgbMap rgb_map = new QRgb*[height];

    for (int i = 0; i < height; i++)
        rgb_map[i] = new QRgb[width];

    return rgb_map;
}

RgbMap create_itensity_map(int width, int height)
{
    RgbMap iten_map = new QRgb*[height];

    for (int i = 0; i < height; i++)
        iten_map[i] = new QRgb[width];

    return iten_map;
}

void free_rgb_map(RgbMap &rgb_map, int height)
{
    for (int i = 0; i < height; i++)
        delete rgb_map[i];

    delete rgb_map;
}

void free_itensity_map(RgbMap &iten_map, int height)
{
    for (int i = 0; i < height; i++)
        delete iten_map[i];

    delete iten_map;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _qscene(new QGraphicsScene(-10, -10, 10, 10)), _scene(new Scene())
{
    ui->setupUi(this);

    _size_scene = ui->graphicsView->size();

    //cout << "Size: " << _size_scene.width() << "x" << _size_scene.height() << endl;

    _set_binds_input();

    _rgb_map = create_rgb_map(_size_scene.width(), _size_scene.height());

    ui->graphicsView->setSceneRect(0, 0, _size_scene.width(), _size_scene.height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(&(*_qscene));

    _image = shared_ptr<QImage>(new QImage(_size_scene.width(), _size_scene.height(), QImage::Format_RGB32));

    InitDrawCommand command(_image);
    _scene.execute(command);

    _draw_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
    free_rgb_map(_rgb_map, _size_scene.height());
}

void MainWindow::_set_binds_input(void)
{
    QDoubleValidator *vld = new QDoubleValidator;

    vld->setLocale(QLocale(QLocale::English));

    /*ui->camera_x->setValidator(vld);
    ui->camera_y->setValidator(vld);
    ui->camera_z->setValidator(vld);*/
}

void MainWindow::_show_error(const char *error)
{
    QMessageBox error_message(QMessageBox::Critical, "Error", error);
    error_message.exec();
}

void MainWindow::_draw_scene()
{
    q_pmap = _qscene->addPixmap(QPixmap::fromImage(*_image));

    DrawCommand command;

    _scene.execute(command);
    q_pmap->setPixmap(QPixmap::fromImage(*_image));
    QCoreApplication::processEvents();
}


void MainWindow::on_PushUp_clicked()
{
    _move_camera(0, 5, 0);
}

void MainWindow::on_PushDown_clicked()
{
    _move_camera(0, -5, 0);
}

void MainWindow::on_PushRight_clicked()
{
    _move_camera(5, 0, 0);
}

void MainWindow::on_PushLeft_clicked()
{
    _move_camera(-5, 0, 0);
}

void MainWindow::on_PushCloser_clicked()
{
    _move_camera(0, 0, -8);
}

void MainWindow::on_PushFurther_clicked()
{
    _move_camera(0, 0, 8);
}

void MainWindow::on_Start_clicked()
{
    cout << "Let's start!";
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        case Qt::Key_W:
            _move_camera(0, 5, 0);
            break;
        case Qt::Key_S:
            _move_camera(0, -5, 0);
            break;
        case Qt::Key_A:
            _move_camera(-5, 0, 0);
            break;
        case Qt::Key_D:
            _move_camera(5, 0, 0);
            break;
        case Qt::Key_U:
            _rotate_camera(15, 0, 0);
            break;
        case Qt::Key_J:
            _rotate_camera(-15, 0, 0);
            break;
        case Qt::Key_H:
            _rotate_camera(0, -30, 0);
            break;
        case Qt::Key_K:
            _rotate_camera(0, 30, 0);
            break;
        default:
            break;
    }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
        _move_camera(0, 0, -8);
    else
        _move_camera(0, 0, 8);
}

void MainWindow::_move_camera(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new MoveCamera(Vector(x, y, z)));

    _scene.execute(*ptr);

    try {
        _draw_scene();
    }  catch (error::BaseError &err) {
        cout << err.what() << endl;
        _move_camera(-x, -y, -z);
    }

}

void MainWindow::_move_light(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new MoveLightSource(Vector(x, y, z)));

    _scene.execute(*ptr);

    try {
        _draw_scene();
    }  catch (error::BaseError &err) {
        cout << err.what() << endl;
        _move_light(-x, -y, -z);
    }

}

void MainWindow::_rotate_camera(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new RotateCamera(Vector(x, y, z)));

    _scene.execute(*ptr);

    try {
        _draw_scene();
    }  catch (error::BaseError &err) {
        cout << err.what() << endl;
        _rotate_camera(-x, -y, -z);
    }
}

void MainWindow::on_PushLightUp_clicked()
{
    _move_light(0, 10, 0);
}

void MainWindow::on_PushLightDown_clicked()
{
    _move_light(0, -10, 0);
}

void MainWindow::on_PushLightLeft_clicked()
{
    _move_light(-10, 0, 0);
}

void MainWindow::on_PushLightRight_clicked()
{
    _move_light(10, 0, 0);
}

void MainWindow::on_PushLightCloser_clicked()
{
    _move_light(0, 0, -10);
}

void MainWindow::on_PushLightFurther_clicked()
{
    _move_light(0, 0, 10);
}
