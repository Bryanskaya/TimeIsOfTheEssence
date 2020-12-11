#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <memory>
#include <vector>

#include "Objects/scene_object.h"
#include "Objects/camera.h"
#include "Objects/light_source.h"
#include "Objects/hourglass.h"
#include "Objects/stand.h"
#include "Objects/glass.h"
#include "Objects/sand.h"
#include "Objects/surface_object.h"

#include "Visualizing/drawer.h"
#include "Update/updater.h"


using scene_iter = vector<shared_ptr<SceneObject>>::iterator;
using scene_const_iter = vector<shared_ptr<SceneObject>>::const_iterator;

using namespace std;


class Scene
{
public:
    Scene();

    ~Scene();

    scene_iter begin() {    return _arr.begin();    }
    scene_iter end() {  return _arr.end();  }

    scene_const_iter begin() const {    return _arr.cbegin();    }
    scene_const_iter end() const {  return _arr.cend();  }

    scene_const_iter cbegin() {    return _arr.cbegin();    }
    scene_const_iter cend() {  return _arr.cend();  }

    size_t get_size();

    shared_ptr<Camera> get_camera();
    void set_camera(const Camera& camera);

    shared_ptr<LightSource> get_light();
    void set_light(const LightSource& light);

    shared_ptr<QDrawer> get_drawer();
    void set_drawer(const QDrawer& drawer);
    void set_drawer(shared_ptr<QDrawer>& drawer);

    void add_object(shared_ptr<SceneObject> object);
    void add_object(SceneObject* object);
    void remove_object(scene_iter& iter);

    //void add_tr_object(shared_ptr<SceneObject> object); //hi
    //void add_tr_object(SceneObject* object); //hi
    //void remove_tr_object(scene_iter& iter); //hi

private:
    vector<shared_ptr<SceneObject>> _arr;
    //vector<shared_ptr<SceneObject>> _tr_arr; //hi
    shared_ptr<Camera> _camera;
    shared_ptr<LightSource> _light;

    shared_ptr<QDrawer> _draw;
};

#endif // SCENE_H
