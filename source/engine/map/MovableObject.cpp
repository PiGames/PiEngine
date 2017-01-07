#include "MovableObject.hpp"

namespace pi
{
	MovableObject::MovableObject(const std::string& name, const sf::Vector2f& pos , float speed ) :
		MapObject(name,pos),
		moveSpeed(speed)
	{

	}

	void MovableObject::setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to)
	{
		PathFinder::fillTargetsQueue(from, to, &targets);
	}

	bool MovableObject::canMove()
	{
		return !targets.empty();
	}

	void MovableObject::move()
	{
		sf::Vector2f direction = targets.front() - this->position;

		float magnitude = std::sqrt((direction.x * direction.x) + (direction.y + direction.y));
		sf::Vector2f vector(direction.x / magnitude, direction.y / magnitude);

		this->position += vector * moveSpeed /* * delta time */;
	}
}
