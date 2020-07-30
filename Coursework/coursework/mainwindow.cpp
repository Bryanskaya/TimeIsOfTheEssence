#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _set_binds_input();
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

void MainWindow::on_PushUp_clicked()
{

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
