#pragma once
#include "Scene.h"
#include <map>
#include <string>
#include <vector>

class Scener {
    private:
        std::map<std::string, std::unique_ptr<Scene>> scenes{};
        std::string active = "";

        Scener() {};
        ~Scener() {};

        Scener(Scener const&) = delete;
        Scener& operator= (Scener const&) = delete;

    public:
        static Scener& getInstance() {
            static Scener instance;
            return instance;
        }

        void addScene(std::unique_ptr<Scene> scene);
        void changeScene(std::string scene);
        void render();
        void update(float dt);
};
