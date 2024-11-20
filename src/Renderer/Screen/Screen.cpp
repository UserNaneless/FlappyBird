#include "Screen.h"
#include "../../Helpers.h"
#include <cstdlib>

#define square(x) (x) * (x)

void drawRect(int x, int y, int w, int h, Color color) {
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++) {
            if (i < 0 || j < 0 || i >= SCREEN_WIDTH || j >= SCREEN_HEIGHT)
                continue;
            buffer[j][i] = color;
        }
}

void drawRoundedRect(int x, int y, int w, int h, int r, Color color) {
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++) {
            if (i < 0 || j < 0 || i >= SCREEN_WIDTH || j >= SCREEN_HEIGHT)
                continue;
            int localX = i - x;
            int localY = j - y;

            if ((localX <= r && localY <= r) || (localX >= w - r && localY <= r) || (localX >= w - r && localY >= h - r) || (localX <= r && localY >= h - r)) {
                if ((square(localX - r) + square(localY - r) <= square(r)) || (square(localX - (w - r)) + square(localY - r) <= square(r)) || (square(localX - (w - r)) + square(localY - (h - r)) <= square(r)) || (square(localX - r) + square(localY - (h - r)) <= square(r)))
                    buffer[j][i] = color;
            } else
                buffer[j][i] = color;
        }
};

void drawOutlineRect(int x, int y, int w, int h, int d, Color color) {
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++) {
            if (i < 0 || j < 0 || i >= SCREEN_WIDTH || j >= SCREEN_HEIGHT)
                continue;
            if (i < x + d || i > x + w - d || j < y + d || j > y + h - d)
                buffer[j][i] = color;
        }
}

void drawRoundedOutlineRect(int x, int y, int w, int h, int d, int r, Color color, Color bgColor) {
    drawRoundedRect(x, y, w, h, r, color);
    drawRoundedRect(x + d, y + d, w - 2 * d, h - 2 * d, r / 2, bgColor);
}

void drawPixels(const Color *pixels, int x, int y, int w, int h, int scale) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (pixels[i * w + j] != TRANSPARENT)
                drawRect(x + j * scale, y + i * scale, std::abs(scale), std::abs(scale),
                         pixels[i * w + j]);
}

void drawPixels(const bool *pixels, Color color, int x, int y, int w, int h, int scale) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (pixels[i * w + j])
                drawRect(x + j * scale, y + i * scale, std::abs(scale), std::abs(scale),
                         color);
};

void drawPixelsRev(const Color *pixels, int x, int y, int w, int h, int scale) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (pixels[i * w + j] != TRANSPARENT)
                drawRect(x - (j + 1) * scale, y - (i + 1) * scale, std::abs(scale), std::abs(scale),
                         pixels[i * w + j]);
}

void drawSprite(Sprite *sprite, bool inverse) {
    if (inverse)
        drawPixelsRev(sprite->buffer, sprite->x + sprite->w * sprite->scale, sprite->y + sprite->h * sprite->scale, sprite->w,
                      sprite->h, sprite->scale);
    else
        drawPixels(sprite->buffer, sprite->x, sprite->y, sprite->w,
                   sprite->h, sprite->scale);
}

void drawSprite(Sprite *sprite, float x, float y, bool inverse) {
    if (inverse)
        drawPixelsRev(sprite->buffer, x + sprite->w * sprite->scale, y + sprite->h * sprite->scale, sprite->w,
                      sprite->h, sprite->scale);
    else
        drawPixels(sprite->buffer, x, y, sprite->w,
                   sprite->h, sprite->scale);
}

void drawPipe(Pipe *pipe) {
    drawSprite(pipe);

    for (int i = 0; i < (SCREEN_HEIGHT - pipe->y) * pipe->scale; i++) {
        drawPixels(pipe->pipeBody, pipe->x, pipe->y + pipe->h * pipe->scale + i, pipe->w, 1, pipe->scale);
    }

    const float topPipeY = pipe->y - (pipe->gap + pipe->h) * pipe->scale;
    drawSprite(pipe, pipe->x, topPipeY, true);
    for (int i = topPipeY; i >= 0; i--) {
        drawPixelsRev(pipe->pipeBody, pipe->x + pipe->w * pipe->scale, topPipeY - i, pipe->w, 1, pipe->scale);
    }
}

void drawText(const std::string text, Color color, int x, int y, int scale) {
    for (auto c : text) {
        drawPixels(font[c].pixels, color, x, y, font[c].w, font[c].h, scale);
        x += (font[c].w) * scale;
    }
};

void drawUIBlock(UIBlock &block) {
    if (block.rounded && block.outline)
        drawRoundedOutlineRect(block.x, block.y, block.w, block.h, block.d, block.r, block.color, block.bgColor);
    else if (block.rounded)
        drawRoundedRect(block.x, block.y, block.w, block.h, block.r, block.color);
    else if (block.outline)
        drawOutlineRect(block.x, block.y, block.w, block.h, block.d, block.color);
    else
        drawRect(block.x, block.y, block.w, block.h, block.color);

    int textStart = block.x;
    if (block.textPosition == 0)
        textStart = block.x + (block.w - textLength(block.text, block.scale)) / 2;
    else if (block.textPosition == 1)
        textStart = block.x + block.padding;
    else if (block.textPosition == 2)
        textStart = block.x + block.w - textLength(block.text, block.scale) - block.padding;

    drawText(block.text, block.textColor, textStart, block.y + (block.h - 9 * block.scale) / 2, block.scale);
};
