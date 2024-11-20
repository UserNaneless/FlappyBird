#include "./src/Game/Scenes/MenuScene.h"
#include "Engine.h"
#include "src/Game/Scenes/GameScene.h"
#include "src/Renderer/Scener/Scener.h"
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <memory>
#include <stdlib.h>

void clear() {
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint32_t));
}

Scener &scener = Scener::getInstance();

void initialize() {

    srand(time(NULL));

    scener.addScene(std::make_unique<MenuScene>());
    scener.addScene(std::make_unique<GameScene>());
    scener.changeScene("menu");
}

void act(float dt) {

    scener.update(dt);
    if (is_key_pressed(VK_ESCAPE))
        schedule_quit_game();
}

void draw() {
    clear();

    scener.render();
}

void finalize() {}
