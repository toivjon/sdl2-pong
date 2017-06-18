#ifndef PONG_SCORE_INDICATOR_H
#define PONG_SCORE_INDICATOR_H

#include <array>
#include <SDL.h>

namespace pong
{
  class ScoreIndicator final
  {
  public:
    ScoreIndicator(int x, int y, int width, int height);

    void onDraw(SDL_Renderer& renderer);

    void setValue(int value) { mValue = value; }
  private:
    int mValue;
    std::array<SDL_Rect, 3> mHLines;
    std::array<SDL_Rect, 5> mVLines;
  };
}

#endif