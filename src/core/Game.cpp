#include "Game.hpp"

Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game Window", 
        800, 
        600, 
        SDL_WINDOW_RESIZABLE 
    );
    if (!window) {
        isRunning = false;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        isRunning = false;
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s", SDL_GetError());
    }

    isRunning = true;
}

Game::~Game() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void Game::run() {
    Uint64 current = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double deltaTime = 0;

    while (isRunning) {
        last = current;
        current = SDL_GetPerformanceCounter();
        deltaTime = (double)((current - last) / (double)SDL_GetPerformanceFrequency());

        handleInput();
        update(deltaTime);
        render();
    }
}

void Game::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            isRunning = false;
        }
        if (event.key.key == SDLK_ESCAPE) {
            isRunning = false;
        }
    }
}

void Game::update(double dt) {
    // Update game logic here
}

void Game::render() {
    SDL_RenderClear(renderer);
    // Render game objects here
    SDL_RenderPresent(renderer);
}