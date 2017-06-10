#include "wall.h"

using namespace pong;

Wall::Wall(int x, int y, int width, int height) : mRect({ x, y, width, height})
{
  // ...
}

void Wall::onDraw(SDL_Renderer& renderer)
{
  SDL_RenderFillRect(&renderer, &mRect);
}
