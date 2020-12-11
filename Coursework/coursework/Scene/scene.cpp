#include "scene.h"

Scene::Scene()
{
    set_camera(Camera(Point(0, 0, 710), Vector(0, 0, 0)));
    set_light(LightSource(Point(0, 50, 500), 900));

    /*Point pnt1 = Point(-50, 150, -200);
    Point pnt2 = Point(400, 120, -300);
    add_object(new DemoBox(pnt1, pnt2));*/

    add_object(new Stand(-130, -210, 130));
    add_object(new Stand(-130, 190, 130));

    //add_object(new SandUpP(Point(-70, 124, 70), Point(-1, 10, 1)));
    add_object(new SurfaceObject(Point(-70, 124, 70), Point(70, 124, -70), Point(-1, 0, 1), true));//0-10
    add_object(new SandItem(Point(-4.33, -10, 5), Point(4.33, -10, 5), Point(0, -10, 10), Point(0, 0, 0)));

    add_object(new Glass(Point(-120, -190, 120), Point(-5, 0, 5)));//0-10
    add_object(new Glass(Point(-120, 200, 120), Point(-5, 0, 5)));//0-10
}

Scene::~Scene() {}


size_t Scene::get_size()
{
    return _arr.size();
}

shared_ptr<Camera> Scene::get_camera()
{
    return _camera;
}

void Scene::set_camera(const Camera& camera)
{
    _camera = shared_ptr<Camera>(new Camera(camera));
}


shared_ptr<LightSource> Scene::get_light()
{
    return _light;
}

void Scene::set_light(const LightSource& light)
{
    _light = shared_ptr<LightSource>(new LightSource(light));
}


shared_ptr<QDrawer> Scene::get_drawer()
{
    return _draw;
}

void Scene::set_drawer(const QDrawer &drawer)
{
    _draw = shared_ptr<QDrawer>(new QDrawer(drawer));
}

void Scene::set_drawer(shared_ptr<QDrawer> &drawer)
{
    _draw = drawer;
}

void Scene::add_object(shared_ptr<SceneObject> object)
{
    _arr.push_back(object);
}

void Scene::add_object(SceneObject *object)
{
    _arr.push_back(shared_ptr<SceneObject>(object));
}

/*void Scene::add_tr_object(shared_ptr<SceneObject> object) //hi
{
    _tr_arr.push_back(object);
}

void Scene::add_tr_object(SceneObject *object) //hi
{
    _tr_arr.push_back(shared_ptr<SceneObject>(object));
}*/

void Scene::remove_object(scene_iter &iter)
{
    _arr.erase(iter);
}

/*void Scene::remove_tr_object(scene_iter &iter) //hi
{
    _tr_arr.erase(iter);
}*/
