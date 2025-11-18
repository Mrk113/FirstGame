#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Game {
public:
    Game();
    void run();
    ~Game();
private:
    void handleInput();
    void update(double dt);
    void render();
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning = false;
};

#endif