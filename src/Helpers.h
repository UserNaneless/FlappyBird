#pragma once
#include "Renderer/Font/Font.h"
#include <functional>
#include <string>

int textLength(const std::string text, int scale);
int carouselInt(int value, int min, int max);
int getRandomInt(int from, int to);
float getRandomFloat(float from, float to);
std::function<void()> debounce(std::function<void()> &func, int delay);
