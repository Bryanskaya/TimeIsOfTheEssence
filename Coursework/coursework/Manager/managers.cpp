#include "managers.h"

SceneManager::SceneManager(weak_ptr<Scene> scene) :
    _scene(scene) {}

SceneManager::~SceneManager() {}


DrawManager::DrawManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DrawManager::~DrawManager() {}

void DrawManager::execute()
{
    //
}


InitManager::InitManager(weak_ptr<Scene> scene, shared_ptr<QDrawer> draw) :
    SceneManager(scene), _draw(draw) {}

InitManager::~InitManager() {}

void InitManager::execute()
{
    //
}
