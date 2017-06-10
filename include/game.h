/*! The game instance for the whole application.

  This is the main instance for the whole Pong game application. This class
  encapsulates the required functionality to tie the application as a whole
  by combining and providing a way to manage the game state and scenes as 
  well as the management of performing logical game updates (i.e. ticks).
 */
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "scene.h"

// SDL forward declarations.
struct SDL_Window;
struct SDL_Renderer;
struct _TTF_Font;

namespace pong
{
  class Game
  {
  public:
    Game();
    Game(const Game&) = delete;
    Game(Game&&) = delete;

    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

    ~Game();
		
    void start();

    void setScene(ScenePtr scene);
  private:
    SDL_Window*     mWindow;
    SDL_Renderer*   mRenderer;
    _TTF_Font*      mFont;
    ScenePtr        mScene;
  };
}

#endif