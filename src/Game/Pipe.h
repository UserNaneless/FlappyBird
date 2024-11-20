#pragma once
#include "../Renderer/Sprite/Sprite.h"
#include <cstring>

class Pipe : public Sprite {
    public:
        Vector2D acceleration = { 0, 0 };
        const Color *pipeBody = new Color[32];
        Color *pipe;
        int gap = 50;

        Pipe(const Color *buffer, const Color *body, int w, int h, int scale = 1)
            : Sprite(buffer, w, h, scale) {
            pipeBody = body;
        }
        void updatePipe(float x, float y, int gap);
};
