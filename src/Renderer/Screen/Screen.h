#pragma once
#include "../../../Engine.h"
#include "../../Game/Pipe.h"
#include "../Colors.h"
#include "../Font/Font.h"
#include "../Sprite/Sprite.h"
#include "../UI/UIBlock.h"
#include <string>

void drawRect(int x, int y, int w, int h, Color color);
void drawRoundedRect(int x, int y, int w, int h, int r, Color color);
void drawOutlineRect(int x, int y, int w, int h, int d, Color color);
void drawRoundedOutlineRect(int x, int y, int w, int h, int d, int r, Color color, Color bgColor);
void drawPixels(const Color *pixels, int x, int y, int w, int h, int scale);
void drawPixels(const bool *pixels, Color color, int x, int y, int w, int h, int scale);
void drawPixelsRev(const Color *pixels, int x, int y, int w, int h, int scale);
void drawSprite(Sprite *sprite, bool inverse = false);
void drawSprite(Sprite *sprite, float x, float y, bool inverse = false);
void drawPipe(Pipe *pipe);
void drawText(const std::string text, Color color, int x, int y, int scale);
void drawUIBlock(UIBlock &block);
