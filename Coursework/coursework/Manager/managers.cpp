#include "managers.h"

SceneManager::SceneManager(weak_ptr<Scene> scene) :
    _scene(scene) {}

SceneManager::~SceneManager() {}


InitDrawManager::InitDrawManager(weak_ptr<Scene> scene, shared_ptr<QDrawer> draw) :
    SceneManager(scene), _draw(draw) {}

InitDrawManager::~InitDrawManager() {}

void InitDrawManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _scene.lock()->set_drawer(_draw);
}


DrawManager::DrawManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DrawManager::~DrawManager() {}

void DrawManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<Scene> scene = _scene.lock();

    shared_ptr<Visualizer> visual(new Visualizer());

    visual->set_camera(*scene->get_camera());
    visual->set_light(*scene->get_light());
    visual->set_draw(scene->get_drawer());
    visual->clear();

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));

    for (auto object : *_scene.lock())
        object->accept(*visitor);

    /*shared_ptr<ObjectVisitor> iten_visitor(new TransparencyVisitor(visual)); //hi

    for (auto object : *_scene.lock()) //hi
        object->accept(*iten_visitor);*/

    visual->show_scene();
}


TransformManager::TransformManager(weak_ptr<Scene> scene, shared_ptr<Transformator> transf) :
    SceneManager(scene), _transf(transf) {}

TransformManager::~TransformManager() {}

void TransformManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);
}

void TransformManager::camera_execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _transf->rotate(_scene.lock()->get_camera()->get_direction());//
    _transf->transform(*_scene.lock()->get_camera());
}

void TransformManager::light_execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _transf->transform(_scene.lock()->get_light()->get_position());
}


InitUpdateManager::InitUpdateManager(weak_ptr<Scene> scene) : SceneManager(scene) {}

InitUpdateManager::~InitUpdateManager() {}

void InitUpdateManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);
}


UpdateManager::UpdateManager(weak_ptr<Scene> scene, double t_cur, double dt) :
    SceneManager(scene), _t_cur(t_cur), _dt(dt) {}

UpdateManager::~UpdateManager() {}

void UpdateManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<ObjectVisitor> visitor(new UpdateVisitor(_t_cur, _dt, _scene.lock()->get_border(), _scene.lock()->get_global_time()));

    for (auto obj = _scene.lock()->begin(); obj < _scene.lock()->end();)
    {
        try {
            (*obj)->accept(*visitor);
        }  catch (int) {
            _scene.lock()->remove_object(obj);
            continue;
        }
        obj++;
    }

    if (_t_cur < _scene.lock()->get_global_time() * (1 - DTIME))
        _scene.lock()->add_items(2);
}


InitStateManager::InitStateManager(weak_ptr<Scene> scene, double t_limit) :
    SceneManager(scene), _t_limit(t_limit) {}

InitStateManager::~InitStateManager() {}

void InitStateManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _scene.lock()->set_global_time(_t_limit);

    shared_ptr<ObjectVisitor> visitor(new InitStateVisitor());

    for (auto obj = _scene.lock()->begin(); obj < _scene.lock()->end();)
    {
        try {
            (*obj)->accept(*visitor);
        }  catch (int) {
            _scene.lock()->remove_object(obj);
            continue;
        }
        obj++;
    }

    double temp = pow(_t_limit / 120, 1.0/3.0);
    double h_temp = 124 * temp;
    double d_temp = 70 * temp;

    _scene.lock()->add_object(new SurfaceObject(Point(-d_temp, h_temp, d_temp), Point(d_temp, h_temp, -d_temp), Point(-1, 0, 1), true));
    _scene.lock()->add_object(new SurfaceObject(Point(-70, -210, 70), Point(70, -210, -70)));

}
