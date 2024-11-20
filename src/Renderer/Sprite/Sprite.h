#pragma once
#include "../../../Engine.h"
#include "../Colors.h"
#include <memory>
#include <stdint.h>

typedef struct Vector2D {
        float x;
        float y;
} Vector2D;

typedef struct Rect {
        float x;
        float y;
        int w;
        int h;
} Rect;

class Sprite {

    public:
        const Color *buffer;
        int w;
        int h;
        float x = 0;
        float y = 0;
        int scale = 1;
        Rect rect = { 0, 0, 0, 0 };

        Vector2D velocity = { 0, 0 };
        Vector2D acceleration = { 0, -1000 };

        Sprite(const Color *buffer, int w, int h, int scale = 1);
        void setPosition(float x, float y);
        void move(float dt);
        bool collides(Rect rect);
        void updateRect();

        void printRect();
};
