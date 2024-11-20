#pragma once
#include "../Renderer/Screen/Screen.h"
#include "../Renderer/Sprite/Sprite.h"

class Bird : public Sprite {
    private:
        Vector2D startPos = { 0, 0 };

    public:
        Bird(const Color *buffer, int w, int h, int scale = 1)
            : Sprite(buffer, w, h, scale) {};
        void jump();
        bool pipeCollides(Rect rect, int gap);
        void reset();
        void setPosition(float x, float y, bool start = false);
};
