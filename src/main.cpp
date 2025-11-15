#include "Game.hpp"

int main(int argc, char* argv[]) {

    Uint64 current = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double deltaTime = 0;

    Game game;
    while (game.isRunning) {
        last = current;
        current = SDL_GetPerformanceCounter();
        deltaTime = (double)((current - last) / (double)SDL_GetPerformanceFrequency());
        
        game.handleInput();
        game.update(deltaTime); 
        game.render();
    }

    return 0;
}