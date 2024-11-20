#pragma once
#include "../Screen/Screen.h"
#include "../Sprite/Sprite.h"
#include "../UI/UIBlock.h"
#include <map>
#include <string>
#include <vector>

class Scene {
    public:
        std::string name;
        bool active = false;

    protected:
        std::map<std::string, std::unique_ptr<UIBlock>> ui{};

    public:
        virtual void update(float dt) = 0;
        virtual void render() = 0;
        void addUIBlock(std::string name, UIBlockData data);
        void renderUI();
};
