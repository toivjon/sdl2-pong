#ifndef PONG_COURT_SCENE_H
#define PONG_COURT_SCENE_H

#include "scene.h"

namespace pong
{
  class Game;
  class CourtScene : public Scene
  {
  public:
    CourtScene(Game& game);
    virtual ~CourtScene();

    void onDraw(SDL_Renderer& renderer) override;
    void onUpdate() override;
    void onEnter() override;
    void onExit() override;
    void onKeyDown(SDL_KeyboardEvent& event) override;
    void onKeyUp(SDL_KeyboardEvent& event) override;
  private:
    Game& mGame;
  };
}

#endif