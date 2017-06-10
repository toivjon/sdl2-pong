/*! A horizontal wall abstraction for the Pong game.

    This class contains a definition for a single horizontal wall for a Pong
    game. Typically Pong contains a wall at the bottom and the top of the
    screen. These walls are also commonly 100% wide related to game scene.
 */
#ifndef PONG_WALL_H
#define PONG_WALL_H

#include <SDL.h>

namespace pong
{
  class Wall
  {
  public:
    Wall(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
  private:
    SDL_Rect mRect;
  };
}

#endif