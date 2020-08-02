#include "simple_object.h"

SimpleObject::SimpleObject() {}

SimpleObject::~SimpleObject() {}


InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}


VisibleObject::VisibleObject() {}

VisibleObject::VisibleObject(const VisibleObject& other)
{
    _model = other._model;
}

VisibleObject::~VisibleObject() {}
