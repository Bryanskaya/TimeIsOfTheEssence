#include "scene.h"

Scene::Scene()
{
    set_camera(Camera(Point(-53.37, 58, 657), Vector(-0.085, -0.0515472, 0))); //0 0 710    0 0 0 ideal
    //set_light(LightSource(Point(0, 250, 500), 900));
    set_light(LightSource(Point(-136, 8, 256), 900));


    add_object(new Stand(-130, -210, 130));
    add_object(new Stand(-130, 190, 130));

    add_object(new SurfaceObject(Point(-70, 124, 70), Point(70, 124, -70), Point(-1, 0, 1), true));

    add_object(new Glass(Point(-120, -190, 120), Point(-5, 0, 5)));
    add_object(new Glass(Point(-120, 200, 120), Point(-5, 0, 5)));
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

double Scene::get_border()
{
    return _border_y;
}

void Scene::set_global_time(double time)
{
    _global_time = time;
}

double Scene::get_global_time()
{
    return _global_time;
}

void Scene::add_object(shared_ptr<SceneObject> object)
{
    _arr.push_back(object);
}

void Scene::add_object(SceneObject *object)
{
    _arr.push_back(shared_ptr<SceneObject>(object));
}

void Scene::add_items(int num)
{
    double x, y, z;

    for (int i = 0; i < num; i++)
    {
        x = (double)(-2 + rand() % 4);
        y = -(double)(rand() % 7);
        z = (double)(-2 + rand() % 4);
        add_object(new SandItem(Point(x, y, z)));
    }
}

void Scene::remove_object(scene_iter &iter)
{
    _arr.erase(iter);
}

