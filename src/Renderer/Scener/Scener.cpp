#include "Scener.h"
#include <iostream>
#include <utility>

void Scener::addScene(std::unique_ptr<Scene> scene) {
    scenes[scene->name] = std::move(scene);
}

void Scener::changeScene(std::string scene) {
    if (scenes.find(active) == scenes.end()) {
        return;
    } else
        scenes[active]->active = false;
    if (scenes.find(scene) == scenes.end()) {
        std::cout << "Scene " << scene << " does not exist" << std::endl;
        return;
    } else {
        scenes[scene]->active = true;
        active = scene;
    }
}

void Scener::render() {
    if (scenes.find(active) == scenes.end()) {
        return;
    }
    scenes[active]->render();
}

void Scener::update(float dt) {
    if (scenes.find(active) == scenes.end()) {
        return;
    }
    scenes[active]->update(dt);
}
