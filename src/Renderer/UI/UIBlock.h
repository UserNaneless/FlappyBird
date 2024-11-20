#pragma once
#include "../Colors.h"
#include <string>

typedef struct UIBlock_t {
        int x;
        int y;
        int w;
        int h;
        Color color;

        bool centeredXY = false;

        bool rounded = false;
        bool outline = false;
        int r = 0;
        int d = 0;
        Color bgColor = TRANSPARENT;

        std::string text = "";
        int scale = 1;
        int textPosition = 0;
        Color textColor = BLACK;

        int padding = 0;
        float animSpeed = 1;

} UIBlockData;

class UIBlock {
    public:
        int x;
        int y;
        int w;
        int h;
        int r;
        int d;
        bool rounded = false;
        bool outline = false;
        Color color;
        Color startColor;
        Color bgColor;
        int scale;
        std::string text = "";
        Color textColor;
        int textPosition = 0;
        int padding = 0;
        bool active = false;
        float timer = 0;
        float animSpeed = 1;

        UIBlock(UIBlockData data);
        void makeActive();
        void makeInactive();
        void toggle();
        void flash(float dt);
};
