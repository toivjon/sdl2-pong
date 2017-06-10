#ifndef PONG_WELCOME_SCENE_H
#define PONG_WELCOME_SCENE_H

#include "scene.h"

namespace pong
{
	class Game;

	class WelcomeScene : public Scene
	{
	public:
		WelcomeScene(Game& game);
		
		virtual ~WelcomeScene() { }
		
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