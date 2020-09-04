#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>

RgbMap create_rgb_map(int width, int height)
{
    RgbMap rgb_map = new QRgb*[height];

    for (int i = 0; i < height; i++)
        rgb_map[i] = new QRgb[width];

    return rgb_map;
}

void free_rgb_map(RgbMap &rgb_map, int height)
{
    for (int i = 0; i < height; i++)
        delete rgb_map[i];

    delete rgb_map;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _qscene(new QGraphicsScene(-1, -1, 1, 1)), _scene(new Scene())
{
    ui->setupUi(this);

    _size_scene = ui->graphicsView->size();

    cout << "Size: " << _size_scene.width() << "x" << _size_scene.height() << endl;

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
    _move_camera(0, 10, 0);
}

void MainWindow::on_PushDown_clicked()
{
    _move_camera(0, -10, 0);
}

void MainWindow::on_PushRight_clicked()
{
    _move_camera(10, 0, 0);
}

void MainWindow::on_PushLeft_clicked()
{
    _move_camera(-10, 0, 0);
}

void MainWindow::on_PushCloser_clicked()
{
    _move_camera(0, 0, -10);
}

void MainWindow::on_PushFurther_clicked()
{
    _move_camera(0, 0, 10);
}

void MainWindow::on_Start_clicked()
{
    cout << "Let's start!";
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    cout << event->key() << " " << Qt::Key_W << endl;

    switch (event->key())
    {
        case Qt::Key_W:
            cout << "here************************" << endl;
            _rotate_camera(0, 10, 0);
            break;
        case Qt::Key_S:
            break;
        case Qt::Key_A:
            break;
        case Qt::Key_D:
            break;
        default:
            break;
    }
}

void MainWindow::_move_camera(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new MoveCamera(Vector(x, y, z)));

    _scene.execute(*ptr);
    _draw_scene();
}

void MainWindow::_rotate_camera(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new RotateCamera(Vector(x, y, z)));

    _scene.execute(*ptr);
    _draw_scene();
}
