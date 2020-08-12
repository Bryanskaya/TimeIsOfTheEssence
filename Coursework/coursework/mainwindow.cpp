#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _qscene(new QGraphicsScene(-1, -1, 1, 1)), _scene(new Scene())
{
    ui->setupUi(this);

    _size_scene = ui->graphicsView->size();

    _set_binds_input();

    ui->graphicsView->setScene(&(*_qscene));

    _image = shared_ptr<QImage>(new QImage(_size_scene.width(), _size_scene.height(), QImage::Format_RGB32));

    InitDrawCommand command(_image);
    _scene.execute(command);

    _draw_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_set_binds_input(void)
{
    QDoubleValidator *vld = new QDoubleValidator;

    vld->setLocale(QLocale(QLocale::English));

    ui->camera_x->setValidator(vld);
    ui->camera_y->setValidator(vld);
    ui->camera_z->setValidator(vld);
}

void MainWindow::_show_error(const char *error)
{
    QMessageBox error_message(QMessageBox::Critical, "Error", error);
    error_message.exec();
}

void MainWindow::_draw_scene()
{
    DrawCommand command;

    _scene.execute(command);
    //TODO
}

void MainWindow::on_PushUp_clicked()
{
    //TODO
}

void MainWindow::on_PushRight_clicked()
{

}

void MainWindow::on_PushDown_clicked()
{

}

void MainWindow::on_PushLeft_clicked()
{

}

void MainWindow::on_Start_clicked()
{
    cout << "Let's start!";
}
