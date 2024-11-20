
# You are free to modify this file

cmake_minimum_required(VERSION 3.0)
project(game)
find_package(X11 REQUIRED)
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")
add_executable(game 
    Game.cpp
    Engine.cpp
    Engine.h
    src/Renderer/Sprite/Sprite.h
    src/Renderer/Sprite/Sprite.cpp
    src/Renderer/Screen/Screen.h
    src/Renderer/Screen/Screen.cpp
    src/Renderer/Font/Font.h
    src/Renderer/Font/Font.cpp
    src/Renderer/Colors.h
    src/Renderer/UI/UIBlock.h
    src/Renderer/UI/UIBlock.cpp
    src/Renderer/Scener/Scener.h
    src/Renderer/Scener/Scener.cpp
    src/Renderer/Scener/Scene.h
    src/Renderer/Scener/Scene.cpp
    src/Helpers.h
    src/Helpers.cpp
    src/Assets/Assets.h
    src/Game/Bird.h
    src/Game/Bird.cpp
    src/Game/Pipe.cpp
    src/Game/Pipe.h
    src/Game/Scenes/MenuScene.h
    src/Game/Scenes/MenuScene.cpp
    src/Game/Scenes/GameScene.h
    src/Game/Scenes/GameScene.cpp
)
target_link_libraries(game m X11)
