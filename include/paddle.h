#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SDL.h>
#include <aabb.h>

namespace pong
{
  class CourtScene;
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

    Paddle(CourtScene& scene, int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
    void onUpdate();

    void setMovement(Movement movement) { mMovement = movement; }

    bool isMoving(Movement movement) const { return mMovement == movement;  }

    const AABB& getAabb() const { return mAabb; }
          AABB& getAabb()       { return mAabb; }
  private:
    CourtScene& mScene;
    SDL_Rect    mRect;
    Movement    mMovement;
    AABB        mAabb;
  };
}

#endif