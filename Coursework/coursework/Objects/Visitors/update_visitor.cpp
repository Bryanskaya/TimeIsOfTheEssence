#include "update_visitor.h"

UpdateVisitor::UpdateVisitor(double t, double edge) : _temp_time(t), _border(_border)  {}

UpdateVisitor::~UpdateVisitor() {}


void UpdateVisitor::visit(Camera&) {}

void UpdateVisitor::visit(LightSource&) {}

void UpdateVisitor::visit(Hourglass&) {}

void UpdateVisitor::visit(Stand&) {}

void UpdateVisitor::visit(Glass&) {}

void UpdateVisitor::visit(SandUpP& sand)
{
    //
}

void UpdateVisitor::visit(SurfaceObject& sand)
{

}

void UpdateVisitor::visit(SandItem& item)
{
    //_updater->add_item(item);
}

void UpdateVisitor::visit(DemoBox&) {}

void UpdateVisitor::set_border(double border)
{
    _border = border;
}

void UpdateVisitor::set_temp_time(double t)
{
    _temp_time = t;
}

void UpdateVisitor::move_sand_items()
{
    double step = 5; // что-то с этим придумать
    for (size_t i = 0; i < массив_песчинок.size(); i++)
    {
        // обдумать обработку ошибки выхода
        _move_sand_item(массив_песчинок[i], step);

        //удаление в случае не пустого массива/ошибки
    }
}

void UpdateVisitor::_move_sand_item(shared_ptr<SandItem> &item, double step)
{
    vector<shared_ptr<Vertex>>& v = item->get_model()->v_arr; //&???

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->y += step;

        if (v[i]->y > _border)
            throw i; // можно просто return в принципе учесть что циел должен работать до конца!!!
        /* можно массив индексов для удаления сделать*/
    }
}

