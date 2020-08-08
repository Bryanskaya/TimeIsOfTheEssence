#include "visualizer.h"

Visualizer::Visualizer() {}

Visualizer::Visualizer(shared_ptr<QDrawer>& drawer) :
    _draw(drawer) {}

Visualizer::~Visualizer() {}

