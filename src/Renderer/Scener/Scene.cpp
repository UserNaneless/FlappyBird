#include "Scene.h"

void Scene::addUIBlock(std::string name, UIBlockData data) {
    ui[name] = std::make_unique<UIBlock>(data);
}

void Scene::renderUI() {
    for (auto &block : ui) {
        drawUIBlock(*block.second);
    }
}
