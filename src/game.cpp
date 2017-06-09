#include "game.h"

#include <SDL.h>

using namespace pong;

Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
}

Game::~Game()
{
  SDL_Quit();
}

void Game::start()
{
  // ... TODO
}
