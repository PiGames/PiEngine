#pragma once

#include "engine/cell/Cell.hpp"
#include "engine/Config.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>
#include <memory>

namespace pi
{
	class MapManager
	{

		static void createArrays();

	public:
		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions);

		//Updatesthe whole collision map (Only from surface) | Don't overuse this method!
		static void SurfaceCollisionMapUpdate();

		//Updates units which have represantion on given object 
		static void UpdateSingleUnits(MapObject* object);

		static void AddCell(uint8_t number = 0, int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", bool collidableFlag = false);

		//Returns cell dimensions (in px)
		static sf::Vector2f& GetCellDimensions();

		//Returns unit world size (in units)
		static sf::Vector2i& GetUnitWorldSize();

	private:

		//static Cell *surface;
		static std::vector<Cell> surface;

		static std::vector<MapObject> objects;

		//true - collidable unit
		//false - not collidable unit
		static bool *collisionMap;

		static sf::Vector2i unitWorldSize;

		static sf::Vector2f cellDimensions;
	};

}