/*! An Axis Aligned Bounding Box implementation for the game.

    This class contains a definition for a AABB structure that is used for a 
    fast collision detection base structure. This implementation contains only
    2D-version of the AABB as we do not need more dimensions in our Pong game.
 */
#ifndef PONG_AABB_H
#define PONG_AABB_H

namespace pong
{
  class AABB final
  {
  public:
    AABB();

    bool collides(const AABB& other) const;

    int getCenterX() const { return mCenterX; }
    int getCenterY() const { return mCenterY; }
    int getExtentX() const { return mExtentX; }
    int getExtentY() const { return mExtentY; }

    void setCenterX(int x) { mCenterX = x; }
    void setCenterY(int y) { mCenterY = y; }
    void setExtentX(int x) { mExtentX = x; }
    void setExtentY(int y) { mExtentY = y; }
  private:
    int mCenterX;
    int mCenterY;
    int mExtentX;
    int mExtentY;
  };
}

#endif