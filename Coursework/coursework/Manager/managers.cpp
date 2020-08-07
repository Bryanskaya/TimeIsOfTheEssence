#include "managers.h"

SceneManager::SceneManager(weak_ptr<Scene> scene) :
    _scene(scene) {}

SceneManager::~SceneManager() {}

