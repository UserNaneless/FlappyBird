#include "MenuScene.h"

MenuScene::MenuScene() {

    this->up = [this]() {
        this->selected = carouselInt(this->selected + 1, 1, 2);
    };

    this->down = [this]() {
        this->selected = carouselInt(this->selected - 1, 1, 2);
    };

    this->upDeb = debounce(this->up, 200);
    this->downDeb = debounce(this->down, 200);

    UIBlockData text1 = {
        .x = SCREEN_WIDTH / 2,
        .y = 220,
        .w = textLength("FLAPPY BIRD", MENU_SCALE + 2) + 30 * 2,
        .h = 60,
        .color = 0xB2FF59,
        .centeredXY = true,
        .bgColor = BLACK,
        .text = "FLAPPY BIRD",
        .scale = MENU_SCALE + 2,
        .textPosition = 1,
        .textColor = BLACK,
        .padding = 30
    };

    UIBlockData text2 = {
        .x = 200,
        .y = 350,
        .w = textLength("CONTROLS", MENU_SCALE) + 30 * 2,
        .h = 60,
        .color = BLACK,
        .centeredXY = true,
        .bgColor = BLACK,
        .text = "CONTROLS",
        .scale = MENU_SCALE,
        .textPosition = 1,
        .textColor = WHITE,
        .padding = 30
    };

    UIBlockData text3 = {
        .x = 200,
        .y = 350 + 40,
        .w = textLength("SPACE TO JUMP", MENU_SCALE) + 30 * 2,
        .h = 60,
        .color = BLACK,
        .centeredXY = true,
        .bgColor = BLACK,
        .text = "SPACE TO JUMP",
        .scale = MENU_SCALE,
        .textPosition = 1,
        .textColor = WHITE,
        .padding = 30
    };

    UIBlockData text4 = {
        .x = 200,
        .y = 350 + 80,
        .w = textLength("ESC TO EXIT", MENU_SCALE) + 30 * 2,
        .h = 60,
        .color = BLACK,
        .centeredXY = true,
        .bgColor = BLACK,
        .text = "ESC TO EXIT",
        .scale = MENU_SCALE,
        .textPosition = 1,
        .textColor = WHITE,
        .padding = 30
    };

    UIBlockData play = { .x = SCREEN_WIDTH / 2,
                         .y = SCREEN_HEIGHT / 2,
                         .w = 300,
                         .h = 60,
                         .color = 0xB2FF59,
                         .centeredXY = true,
                         .rounded = true,
                         .outline = true,
                         .r = 12,
                         .d = 4,
                         .bgColor = BLACK,
                         .text = "PLAY",
                         .scale = MENU_SCALE + 2,
                         .textColor = 0xB2FF59,
                         .padding = 20 };

    UIBlockData quit = { .x = SCREEN_WIDTH / 2,
                         .y = SCREEN_HEIGHT / 2 + 60 + 30,
                         .w = 300,
                         .h = 60,
                         .color = 0xB2FF59,
                         .centeredXY = true,
                         .rounded = true,
                         .outline = true,
                         .r = 12,
                         .d = 4,
                         .bgColor = BLACK,
                         .text = "QUIT",
                         .scale = MENU_SCALE + 2,
                         .textColor = 0xB2FF59,
                         .padding = 20 };

    addUIBlock("text1", text1);
    addUIBlock("text2", text2);
    addUIBlock("text3", text3);
    addUIBlock("text4", text4);
    addUIBlock("playButton", play);
    addUIBlock("quitButton", quit);
}

void MenuScene::update(float dt) {
    if (is_key_pressed(VK_DOWN)) {
        this->downDeb();
    }
    if (is_key_pressed(VK_UP)) {
        this->upDeb();
    }

    for (auto &item : ui) {
        if (item.first == "playButton" && selected == 1) {
            item.second->makeActive();
        } else if (item.first == "quitButton" && selected == 2) {
            item.second->makeActive();
        } else {
            item.second->makeInactive();
        }
    }

    if (is_key_pressed(VK_RETURN)) {
        if (selected == 1) {
            scener.changeScene("game");
        } else if (selected == 2) {
            schedule_quit_game();
        }
    }
}

void MenuScene::render() {
    renderUI();
}
