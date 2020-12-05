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

    shared_ptr<ObjectVisitor> iten_visitor(new TransparencyVisitor(visual)); //hi

    for (auto object : *_scene.lock()) //hi
        object->accept(*iten_visitor);

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
