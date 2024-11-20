#pragma once
#include "../../Assets/Assets.h"
#include "../../Helpers.h"
#include "../../Renderer/Scener/Scener.h"
#include "../Bird.h"
#include "../Pipe.h"
#include <functional>
#include <memory>

#define GAME_SCALE 2

typedef struct PipeData_t {
        float x;
        float y;
        int gap;
} PipeData;

class GameScene : public Scene {
    private:
        Scener &scener = Scener::getInstance();
        int score = 0;
        bool lost = false;
        std::unique_ptr<Bird> bird;
        std::unique_ptr<Pipe> pipe;
        std::vector<PipeData> pipeData;

    public:
        GameScene();
        void update(float dt) override;
        void render() override;
        void renderUI();
        void reset();
};
