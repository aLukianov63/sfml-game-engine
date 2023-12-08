
#include "Entity.h"

auto Entity::isAlive() const -> bool
{
	return _alive;
}

auto Entity::getPosition() const -> const sf::Vector2f&
{
	return _sprite.getPosition();
}

auto Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
	target.draw(_sprite, states);
}

auto Entity::onDestroy() -> void
{
	_alive = false;
}
