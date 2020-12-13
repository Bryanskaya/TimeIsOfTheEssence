#include "update_visitor.h"

UpdateVisitor::UpdateVisitor(double t_cur, double dt, double border_y, double t_limit) :
    _t_cur(t_cur), _dt(dt), _general_time(t_limit), _border_y(border_y)  {}

UpdateVisitor::~UpdateVisitor() {}


void UpdateVisitor::visit(Camera&) {}

void UpdateVisitor::visit(LightSource&) {}

void UpdateVisitor::visit(Hourglass&) {}

void UpdateVisitor::visit(Stand&) {}

void UpdateVisitor::visit(Glass&) {}

void UpdateVisitor::visit(SandUpP&) {}

void UpdateVisitor::visit(SurfaceObject& sand)
{
    if (_t_cur > _general_time * (1 - DTIME))
        throw 1004;

    sand.update(_t_cur, _dt, _general_time);
}

void UpdateVisitor::visit(SandItem& item)
{
    vector<shared_ptr<Vertex>>& v = item.get_model()->v_arr;

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->y -= item.v_y * _dt;

        if (v[i]->y < _border_y)
            throw 1000;
    }

    item.v_y += _dt * K_BOOST;
}

void UpdateVisitor::visit(DemoBox&) {}

/*void UpdateVisitor::move_sand_items()
{
    double step = 5; // что-то с этим придумать
    for (size_t i = 0; i < массив_песчинок.size(); i++)
    {
        // обдумать обработку ошибки выхода
        _move_sand_item(массив_песчинок[i], step);

        //удаление в случае не пустого массива/ошибки
    }
}*/

/*void UpdateVisitor::_move_sand_item(shared_ptr<SandItem> &item, double step)
{
    vector<shared_ptr<Vertex>>& v = item->get_model()->v_arr; //&???

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->y += step;

        if (v[i]->y > _border)
            throw i; // можно просто return в принципе учесть что циел должен работать до конца!!!
        /* можно массив индексов для удаления сделать*/
    //}
//}

