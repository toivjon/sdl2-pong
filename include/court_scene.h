#ifndef PONG_COURT_SCENE_H
#define PONG_COURT_SCENE_H

#include "center_line.h"
#include "wall.h"
#include "scene.h"

namespace pong
{
  class Game;
  class CourtScene : public Scene
  {
  public:
    /*! The width of the ball boxes used aroung the scene. */
    static const int BOX_WIDTH = 20;
    /*! The height for the top and bottom walls. */
    static const int WALL_HEIGHT = BOX_WIDTH;
    /*! The height for the left and right paddles. */
    static const int PADDLE_HEIGHT = 100;
    /*! A constant edge offset pixels for both paddles. */
    static const int EDGE_OFFSET = 30;

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

    Wall        mTopWall;
    Wall        mBottomWall;
    CenterLine  mCenterLine;
  };
}

#endif