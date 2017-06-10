#include "court_scene.h"
#include "game.h"
#include "wall.h"

#include <SDL.h>

using namespace pong;

CourtScene::CourtScene(Game& game) 
  : mGame(game),
    mTopWall(0, 0, 800, 25),
    mBottomWall(0, (600 - 25), 800, 25)
{
	// TODO ...
}

CourtScene::~CourtScene()
{
  // TODO ...
}

void CourtScene::onDraw(SDL_Renderer& renderer)
{
  mTopWall.onDraw(renderer);
  mBottomWall.onDraw(renderer);
}

void CourtScene::onUpdate()
{
  // TODO ...
}

void CourtScene::onEnter()
{
  // TODO ...
}

void CourtScene::onExit()
{
  // TODO ...
}

void CourtScene::onKeyDown(SDL_KeyboardEvent& event)
{
  // TODO ...
}

void CourtScene::onKeyUp(SDL_KeyboardEvent& event)
{
  // TODO ...
}