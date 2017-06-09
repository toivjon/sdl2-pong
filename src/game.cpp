#include "game.h"

#include <SDL.h>
#include <iostream>

#define ERROR -1
#define OK     0

using namespace pong;

Game::Game() : mWindow(nullptr)
{
  // ...
}

Game::~Game()
{
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

void Game::start()
{
  // initialize the SDL2 framework along with systems.
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    return;
  }

  // try to create a new window for the application.
  mWindow = SDL_CreateWindow("SDL2 - Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (mWindow == nullptr) {
    std::cerr << "Unable to create SDL window: " << SDL_GetError() << std::endl;
    return;
  }

  // try to create a new renderer for the application window.
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
  if (mRenderer == nullptr) {
    std::cerr << "Unable to create SDL renderer: " << SDL_GetError() << std::endl;
    return;
  }

  auto isRunning = true;
  SDL_Event event;
  while (isRunning) {
    // poll and handle events from the SDL framework.
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        isRunning = false;
      }
    }

    // ... TODO update game logics.

    // clear the rendering context with the black color.
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mRenderer);

    // ... TODO render stuff into the buffer.

    // present the rendered buffer.
    SDL_RenderPresent(mRenderer);
  }
}
