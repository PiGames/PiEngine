#pragma once

#include "States.hpp"
#include "engine/game/State.hpp"
#include "engine/ResourceCache.hpp"
#include "entities/Player.hpp"

namespace mc
{
	class PlayState final :
		public pi::State
	{
	public:
		PlayState();

		short run();

	private:
		pi::FontCache fonts;
	};
}