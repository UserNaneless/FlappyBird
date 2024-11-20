#include "UIBlock.h"

UIBlock::UIBlock(UIBlockData data) {
    this->x = data.x;
    this->y = data.y;
    this->w = data.w;
    this->h = data.h;
    this->color = data.color;
    this->startColor = data.color;
    this->rounded = data.rounded;
    this->outline = data.outline;
    this->r = data.r;
    this->d = data.d;
    this->text = data.text;
    this->textPosition = data.textPosition;
    this->scale = data.scale;
    this->bgColor = data.bgColor;
    this->textColor = data.textColor;
    this->animSpeed = data.animSpeed;
    this->padding = data.padding;

    if (data.centeredXY) {
        this->x -= this->w / 2;
        this->y -= this->h;
    }
};

void UIBlock::makeActive() {
    this->active = true;
    this->timer = 0;
    this->color = RED;
};

void UIBlock::makeInactive() {
    this->active = false;
    this->color = this->startColor;
};

void UIBlock::flash(float dt) {
    if (this->active) {
        this->timer += dt * animSpeed;
        if ((int)this->timer % 2 == 0) {
            this->color = this->startColor;
        } else if ((int)this->timer % 1 == 0) {
            this->color = RED;
        }
    }
};

void UIBlock::toggle() {
    this->active = !this->active;
    this->timer = 0;
};
