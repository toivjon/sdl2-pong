#include "paddle.h"

using namespace pong;

Paddle::Paddle(int x, int y, int width, int height) : mRect({ x, y, width, height })
{
  // ...
}

void Paddle::onDraw(SDL_Renderer& renderer)
{
  SDL_RenderFillRect(&renderer, &mRect);
}
