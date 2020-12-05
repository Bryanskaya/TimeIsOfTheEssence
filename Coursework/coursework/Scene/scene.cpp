#include "scene.h"

Scene::Scene()
{
    //300 330 100
    set_camera(Camera(Point(0, 0, 710), Vector(0, 0, 0)));
    set_light(LightSource(Point(0, 50, 600), 800));
    //add_object(new Glass(Point(180, 120, 110), Point(295, 310, -5)));
    //add_object(new Glass(Point(180, 500, 110), Point(295, 310, -5)));

    //add_object(new Stand(170, 100, 120));
    //add_object(new Stand(170, 500, 120));


    add_object(new Stand(-130, -210, 130));
    add_object(new Stand(-130, 190, 130));
    add_object(new Glass(Point(-120, -190, 120), Point(-5, 10, 5)));
    add_object(new Glass(Point(-120, 200, 120), Point(-5, 10, 5)));
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

void Scene::remove_object(scene_iter &iter)
{
    _arr.erase(iter);
}
