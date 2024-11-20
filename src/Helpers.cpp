#include "Helpers.h"
#include <chrono>

int textLength(const std::string text, int scale) {
    int length = 0;
    for (auto c : text) {
        length += font[c].w;
    }

    return length * scale;
}

int carouselInt(int value, int min, int max) {
    if (value < min)
        return max;
    else if (value > max)
        return min;
    else
        return value;
}

int getRandomInt(int from, int to) {
    return from + (std::rand() % (to - from + 1));
};

float getRandomFloat(float from, float to) {
    return from + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (to - from)));
}

std::function<void()> debounce(std::function<void()> &f, int delay) {
    static auto created = std::chrono::high_resolution_clock::now();

    std::function<void()> wrapper = [=, &f]() {
        auto now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - created).count() >= delay) {
            f();
            created = now;
        }
    };

    return wrapper;
};
