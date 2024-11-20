#include "Sprite.h"
#include <cstring>
#include <iostream>

Sprite::Sprite(const Color *buffer, int w, int h, int scale) {
    this->buffer = buffer;
    this->w = w;
    this->h = h;
    this->scale = scale;

    updateRect();
}

void Sprite::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
    updateRect();
}

void Sprite::move(float dt) {
    this->x += this->velocity.x * dt;
    this->y -= this->velocity.y * dt;

    this->velocity.x += this->acceleration.x * dt;
    this->velocity.y += this->acceleration.y * dt;

    updateRect();
}

bool Sprite::collides(Rect rect) {
    return this->rect.x <= rect.x + rect.w &&
           this->rect.x + this->rect.w >= rect.x &&
           this->rect.y <= rect.y + rect.h &&
           this->rect.y + this->rect.h >= rect.y;
}

void Sprite::updateRect() {
    this->rect = {
        this->x,
        this->y,
        this->w * this->scale,
        this->h * this->scale
    };
}

void Sprite::printRect() {
    std::cout << this->rect.x << " " << this->rect.y << " " << this->rect.w << " " << this->rect.h << "\n";
}
