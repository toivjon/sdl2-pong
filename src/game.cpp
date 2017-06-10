#include "game.h"
#include "welcome_scene.h"

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

  // set the initial scene for the game.
  setScene(std::make_shared<WelcomeScene>(*this));

  auto isRunning = true;
  SDL_Event event;
  while (isRunning) {
    // poll and handle events from the SDL framework.
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        isRunning = false;
      }
    }

    // update game logics on the current scene.
    mScene->onUpdate();

    // clear the rendering context with the black color.
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mRenderer);

    // turn the renderer draw color to white.
    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

    // render scene stuff into the buffer.
    mScene->onDraw();

    // present the rendered buffer.
    SDL_RenderPresent(mRenderer);
  }
}

void Game::setScene(ScenePtr scene)
{
  // skip the null scene assignment.
  if (scene == nullptr) {
    std::cerr << "Unable to set null as the active scene!" << std::endl;
    return;
  }

  // tell old scene (if any) that we are going to exit from it.
  if (mScene) {
    mScene->onExit();
  }

  // assign and enter the new scene.
  mScene = scene;
  mScene->onEnter();
}
