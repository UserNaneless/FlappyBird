#include "Pipe.h"

void Pipe::updatePipe(float x, float y, int gap) {
    setPosition(x, y);
    this->gap = gap;
    this->rect = {
        this->x,
        this->y,
        this->w * this->scale,
        this->h * this->scale
    };
}
