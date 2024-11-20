#include "GameScene.h"

PipeData generatePipeData() {
    return {
        SCREEN_WIDTH,
        getRandomFloat(90, SCREEN_HEIGHT - 100),
        getRandomInt(60, 120),
    };
};

GameScene::GameScene() {
    name = "game";

    this->bird = std::make_unique<Bird>(FlappyBirdArt, 17, 12, GAME_SCALE);
    this->bird->setPosition(0, (SCREEN_HEIGHT - this->bird->w) / 2, true);

    this->pipe = std::make_unique<Pipe>(PipeTopArt, PipeBodyArt, 32, 20, GAME_SCALE);

    this->pipeData = {
        { 300, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 600, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 900, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 1200, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
    };

    UIBlockData score = {
        .x = 0,
        .y = 0,
        .w = textLength("SCORE: 0", GAME_SCALE + 2),
        .h = 30,
        .color = BLACK,
        .centeredXY = false,
        .bgColor = BLACK,
        .text = "SCORE: 0",
        .scale = GAME_SCALE + 2,
        .textPosition = 1,
        .textColor = WHITE,
        .padding = 0
    };

    UIBlockData lostBG = { .x = SCREEN_WIDTH / 2 - 300,
                           .y = SCREEN_HEIGHT / 2 - 300,
                           .w = 600,
                           .h = 520,
                           .color = 0x6C7180,
                           .centeredXY = false,
                           .rounded = true,
                           .outline = true,
                           .r = 12,
                           .d = 4,
                           .bgColor = BLACK,
                           .text = "",
                           .scale = GAME_SCALE + 2,
                           .textColor = 0xB2FF59,
                           .padding = 20 };

    UIBlockData yourScore = { .x = SCREEN_WIDTH / 2,
                              .y = SCREEN_HEIGHT / 2 - 140,
                              .w = 300,
                              .h = 60,
                              .color = 0xB2FF59,
                              .centeredXY = true,
                              .rounded = true,
                              .outline = true,
                              .r = 12,
                              .d = 4,
                              .bgColor = BLACK,
                              .text = "YOUR SCORE: " + std::to_string(score.w),
                              .scale = GAME_SCALE + 2,
                              .textColor = 0xB2FF59,
                              .padding = 20 };

    UIBlockData retry = { .x = SCREEN_WIDTH / 2,
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
                          .text = "RETRY",
                          .scale = GAME_SCALE + 2,
                          .textColor = 0xB2FF59,
                          .padding = 20 };

    addUIBlock("1score", score);
    addUIBlock("2lostBG", lostBG);
    addUIBlock("3retryButton", retry);
    addUIBlock("4lastScore", yourScore);

    ui["3retryButton"]->makeActive();
}

void GameScene::update(float dt) {
    if (lost) {
        if (is_key_pressed(VK_RETURN))
            reset();
        return;
    }
    if (is_key_pressed(VK_SPACE))
        bird->jump();

    bird->move(dt);

    for (PipeData &p : pipeData) {
        p.x -= 100 * dt;
        if (p.x + pipe->w * pipe->scale < 0) {
            score += 12 * p.gap;
            p = generatePipeData();
            auto scoreBlock = ui["1score"].get();
            scoreBlock->text = "SCORE: " + std::to_string(score);
            scoreBlock->w = textLength(scoreBlock->text, scoreBlock->scale);
        }

        // clang-format off
        if (bird->pipeCollides(
                  {   
                      p.x,
                      p.y,
                      pipe->w * pipe->scale,
                      pipe->h * pipe->scale
                  },
                  p.gap * pipe->scale
            ) ||
            bird->y + bird->h > SCREEN_HEIGHT || bird->y + bird->h < 0) {
            ui["4lastScore"].get()->text = "YOUR SCORE: " + std::to_string(score);
            lost = true;
        }

        // clang-format on
    };
}

void GameScene::render() {
    drawSprite(bird.get());
    for (PipeData &p : pipeData) {
        pipe->updatePipe(p.x, p.y, p.gap);
        drawPipe(pipe.get());
    };

    renderUI();
}

void GameScene::renderUI() {
    if (!lost) {
        if (ui.find("1score") != ui.end())
            drawUIBlock(*ui["1score"].get());
    } else
        for (auto &block : ui) {
            drawUIBlock(*block.second);
        }
}

void GameScene::reset() {
    lost = false;
    score = 0;
    pipeData = {
        { 300, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 600, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 900, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
        { 1200, getRandomFloat(90, SCREEN_HEIGHT - 100), getRandomInt(60, 120) },
    };
    ui["1score"].get()->text = "SCORE: 0";
    bird->reset();
}
