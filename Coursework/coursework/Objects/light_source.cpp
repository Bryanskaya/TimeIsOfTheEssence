#include "light_source.h"

//constructors and destructor
LightSource::LightSource() {}

LightSource::LightSource(const Point& position) :
    _pos(position) {}

LightSource::LightSource(const Point& position, double itensity) :
    _pos(position), _i(itensity) {}

LightSource::LightSource(const LightSource& other) :
    _pos(other._pos), _i(other._i) {}

LightSource::~LightSource() {}


//methonds
Point& LightSource::get_position() {    return _pos;    }

double LightSource::get_itensity() {    return _i;  }

void LightSource::set_itensity(double itensity) {   _i = itensity;  }

const Point& LightSource::get_position() const {    return _pos;    }


void LightSource::accept(shared_ptr<ObjectVisitor> visitor)
{
    //visitor->visit(*this);
}

SceneObject *LightSource::clone()
{
    return new LightSource(*this);
}
