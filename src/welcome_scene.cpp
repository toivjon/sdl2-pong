#include "welcome_scene.h"
#include "game.h"

#include <SDL.h>

using namespace pong;

WelcomeScene::WelcomeScene(Game& game) : mGame(game)
{
	// ...
}

void WelcomeScene::onDraw(SDL_Renderer& renderer)
{
	// TODO ...
}

void WelcomeScene::onUpdate() 
{
	// ...
}

void WelcomeScene::onEnter() 
{
	// ...
}

void WelcomeScene::onExit()
{
	// ...	
}

void WelcomeScene::onKeyDown(SDL_KeyboardEvent& event)
{
  // ...
}

void WelcomeScene::onKeyUp(SDL_KeyboardEvent& event)
{
  switch (event.keysym.sym) {
  case SDLK_RETURN:
    // TODO ... goto court scene when court scene exists.
    break;
  }
}