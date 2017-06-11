#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SDL.h>

namespace pong
{
  class Paddle
  {
  public:
    Paddle(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
  private:
    SDL_Rect mRect;
  };
}

#endif