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
    mCenterLine((RESOLUTION_WIDTH/2) - BOX_WIDTH/2, BOX_WIDTH, BOX_WIDTH, RESOLUTION_HEIGHT),
    mLeftPaddle(*this, EDGE_OFFSET, (RESOLUTION_HEIGHT/2) - (PADDLE_HEIGHT/2), BOX_WIDTH, PADDLE_HEIGHT),
    mRightPaddle(*this, RESOLUTION_WIDTH - EDGE_OFFSET - BOX_WIDTH, (RESOLUTION_HEIGHT/2) - (PADDLE_HEIGHT/2), BOX_WIDTH, PADDLE_HEIGHT),
    mBall(*this, RESOLUTION_WIDTH/2 - (BOX_WIDTH/2), RESOLUTION_HEIGHT/2 - (BOX_WIDTH/2), BOX_WIDTH, BOX_WIDTH)
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
  mLeftPaddle.onDraw(renderer);
  mRightPaddle.onDraw(renderer);
  mBall.onDraw(renderer);
}

void CourtScene::onUpdate()
{
  mLeftPaddle.onUpdate();
  mRightPaddle.onUpdate();
  mBall.onUpdate();
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
  switch (event.keysym.sym) {
  case SDLK_w:
    mLeftPaddle.setMovement(Paddle::Movement::UP);
    break;
  case SDLK_s:
    mLeftPaddle.setMovement(Paddle::Movement::DOWN);
    break;
  case SDLK_UP:
    mRightPaddle.setMovement(Paddle::Movement::UP);
    break;
  case SDLK_DOWN:
    mRightPaddle.setMovement(Paddle::Movement::DOWN);
    break;
  }
}

void CourtScene::onKeyUp(SDL_KeyboardEvent& event)
{
  switch (event.keysym.sym) {
  case SDLK_w:
    if (mLeftPaddle.isMoving(Paddle::Movement::UP)) {
      mLeftPaddle.setMovement(Paddle::Movement::NONE);
    }
    break;
  case SDLK_s:
    if (mLeftPaddle.isMoving(Paddle::Movement::DOWN)) {
      mLeftPaddle.setMovement(Paddle::Movement::NONE);
    }
    break;
  case SDLK_UP:
    if (mRightPaddle.isMoving(Paddle::Movement::UP)) {
      mRightPaddle.setMovement(Paddle::Movement::NONE);
    }
    break;
  case SDLK_DOWN:
    if (mRightPaddle.isMoving(Paddle::Movement::DOWN)) {
      mRightPaddle.setMovement(Paddle::Movement::NONE);
    }
    break;
  }
}