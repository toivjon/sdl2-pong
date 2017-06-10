#ifndef PONG_WELCOME_SCENE_H
#define PONG_WELCOME_SCENE_H

#include "scene.h"

namespace pong
{
	// forward declarations.
	class Game;
	
	class WelcomeScene : public Scene
	{
	public:
		WelcomeScene(Game& game);
		
		virtual ~WelcomeScene() { }
		
		void onDraw() override;
		void onUpdate() override;
		void onEnter() override;
		void onExit() override;
		void onKeyDown() override;
		void onKeyUp() override;
	private:
		Game& mGame;
	};
}

#endif