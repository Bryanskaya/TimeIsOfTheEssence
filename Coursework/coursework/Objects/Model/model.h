#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include <iostream>


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

    void _set_binds_input(void);
    void _show_error(const char* error);
};

#endif // MAINWINDOW_H
