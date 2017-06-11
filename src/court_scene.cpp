#include "court_scene.h"
#include "game.h"
#include "wall.h"

#include <SDL.h>

using namespace pong;

#define RESOLUTION_WIDTH 800
#define RESOLUTION_HEIGHT 600

CourtScene::CourtScene(Game& game) 
  : mGame(game),
    mTopWall(0, 0, RESOLUTION_WIDTH, BOX_WIDTH),
    mBottomWall(0, (RESOLUTION_HEIGHT - BOX_WIDTH), RESOLUTION_WIDTH, BOX_WIDTH),
    mCenterLine((RESOLUTION_WIDTH/2) - BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, RESOLUTION_HEIGHT)
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
  mCenterLine.onDraw(renderer);
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