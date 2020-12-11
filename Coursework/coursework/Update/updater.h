#ifndef UPDATER_H
#define UPDATER_H

#include "Objects/sand.h"

using namespace std;

class Updater //отказаться от этого
{
public:
    Updater();
    ~Updater();

    void update(double step);
    void add_item(const shared_ptr<SandItem>& item);

private:
    vector<shared_ptr<SandItem>> _arr_items;

    void _move_sand_items(shared_ptr<SandItem>& item, double step);

};

#endif // UPDATER_H
