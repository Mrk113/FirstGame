#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#pragma once

class Game {
public:
    Game();
    void handleInput();
    void update(double dt);
    void render();
    ~Game();

    bool isRunning = true;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};