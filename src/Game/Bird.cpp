#include "Bird.h"

void Bird::jump() {
    velocity = { 0, 300 };
}

bool Bird::pipeCollides(Rect rect, int gap) {
    Rect bottomPipe = {
        rect.x + 5,
        rect.y,
        rect.w - 5,
        SCREEN_HEIGHT
    };

    Rect topPipe = {
        rect.x + 5,
        0,
        rect.w - 5,
        (int)rect.y - gap
    };

    drawRect(bottomPipe.x, bottomPipe.y, bottomPipe.w, bottomPipe.h, 0xFF0000);
    drawRect(topPipe.x, topPipe.y, topPipe.w, topPipe.h, 0xFF0000);

    return collides(bottomPipe) || collides(topPipe);
}

void Bird::setPosition(float x, float y, bool start) {
    this->x = x;
    this->y = y;
    if(start) startPos = { x, y };
}

void Bird::reset() {
    x = startPos.x;
    y = startPos.y;
    velocity = { 0, 0 };
}
