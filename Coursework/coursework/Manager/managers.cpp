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

    //for visitor
}


TransformManager::TransformManager(weak_ptr<Scene> scene, shared_ptr<Transformator> transf) :
    SceneManager(scene), _transf(transf) {}

TransformManager::~TransformManager() {}

void TransformManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    //
}


