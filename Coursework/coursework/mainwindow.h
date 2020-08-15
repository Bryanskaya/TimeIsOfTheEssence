#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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

private:
    Ui::MainWindow *ui;
    shared_ptr<QGraphicsScene> _qscene;
    Facade _scene;

    QSize _size_scene;
    shared_ptr<QImage> _image;
    QGraphicsPixmapItem* q_pmap;

    void _set_binds_input(void);
    void _show_error(const char* error);
    void _draw_scene();
};

#endif // MAINWINDOW_H
