#include "aabb.h"

#include <cmath>

using namespace pong;

AABB::AABB() : mCenterX(0), mCenterY(0), mExtentX(0), mExtentY(0)
{
  // ...
}

bool AABB::collides(const AABB& other) const
{
  auto x = std::abs(mCenterX - other.mCenterX) < (mExtentX + other.mExtentX);
  auto y = std::abs(mCenterY - other.mCenterY) < (mExtentY + other.mExtentY);
  return x && y;
}