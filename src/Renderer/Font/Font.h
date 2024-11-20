#pragma once
#include <map>

#define FONT_H 8;

typedef struct FontItem_t {
        int w;
        int h;
        const bool *pixels;
} FontItem;

typedef std::map<char, FontItem> Font;


extern Font font;
