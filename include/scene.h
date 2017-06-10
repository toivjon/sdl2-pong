/*! The game scene abstraction for the application.

	This is the abstraction for all game scenes used within this Pong game.
	This pure class acts as an interface for all scenes and requires them
	to implement functions that are used in the root Game instance.
 */
#ifndef PONG_SCENE_H
#define PONG_SCENE_H

#include <memory>

namespace pong
{
	class Scene
	{
	public:
		virtual void onDraw() = 0;
		virtual void onUpdate() = 0;
		virtual void onEnter() = 0;
		virtual void onExit() = 0;
		virtual void onKeyDown() = 0;
		virtual void onKeyUp() = 0;
	};
	typedef std::shared_ptr<Scene> ScenePtr;
}

#endif