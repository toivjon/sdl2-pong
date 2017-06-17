#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <array>
#include <SDL.h>

#include "aabb.h"

namespace pong
{
  class CourtScene;
  class Ball
  {
  public:
    /** The initial velocity for the ball. */
    static const float INITIAL_VELOCITY;
    /** The amount of velocity to be added on each paddle hit. */
    static const float VELOCITY_INCREASE;
    /** The maximum velocity for the ball. */
    static const float MAX_VELOCITY;

    Ball(CourtScene& scene, int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);
    void onUpdate();

    const AABB& getAabb() const { return mAabb; }
          AABB& getAabb()       { return mAabb; }
  private:
    CourtScene&           mScene;
    SDL_Rect              mRect;
    AABB                  mAabb;
    float                 mVelocity;
    std::array<float, 2>  mDirection;
  };
}

#endif