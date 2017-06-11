#include "center_line.h"

using namespace pong;

CenterLine::CenterLine(int x, int y, int width, int height) : mRect({ x, y, width, height })
{
  // ...
}

void CenterLine::onDraw(SDL_Renderer& renderer)
{
  // draw the center line by forming a number squares as required.
  for (float y = mRect.y; y < mRect.h; y += (1.93 * mRect.w)) {
    SDL_Rect rect{ mRect.x, y, mRect.w, mRect.w };
    SDL_RenderFillRect(&renderer, &rect);
  }
}