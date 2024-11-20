#include "../../Helpers.h"
#include "../../Renderer/Scener/Scener.h"
#include <cstdint>
#include <functional>
#include <string>

#define MENU_SCALE 3

class MenuScene : public Scene {

    private:
        uint8_t selected = 1;
        Scener &scener = Scener::getInstance();
        std::function<void()> upDeb;
        std::function<void()> downDeb;
        std::function<void()> up;
        std::function<void()> down;

    public:
        MenuScene();
        void update(float dt) override;
        void render() override;
};
