#include "paddle.h"

using namespace pong;

const float Paddle::VELOCITY = 8.f;

Paddle::Paddle(int x, int y, int width, int height) : mRect({ x, y, width, height }), mMovement(Movement::NONE)
{
  // ...
}

void Paddle::onDraw(SDL_Renderer& renderer)
{
  SDL_RenderFillRect(&renderer, &mRect);
}

void Paddle::onUpdate()
{
  // update paddle position only if the paddle is moving.
  if (mMovement != Movement::NONE) {
    mRect.y += ((int)mMovement) * VELOCITY;
  }
}