#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SDL.h>

namespace pong
{
  class Paddle
  {
  public:
    /*! The movement velocity for the paddle. */
    static const float VELOCITY;

    /*! Enumeration for possible paddle movement directions. */
    enum class Movement : int {
      UP    = -1,
      NONE  =  0,
      DOWN  =  1
    };

    Paddle(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
    void onUpdate();

    void setMovement(Movement movement) { mMovement = movement; }

    bool isMoving(Movement movement) const { return mMovement == movement;  }
  private:
    SDL_Rect mRect;
    Movement mMovement;
  };
}

#endif