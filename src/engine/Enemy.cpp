
#include "Enemy.h"
#include "cmath"

Enemy::Enemy(Entity& character) : _character(character)
{
}

bool Enemy::isCollide(const Entity& other) const
{
	return false;
}

auto Enemy::isTriggerCharacter(float areaSize) -> bool
{
	return (abs(getPosition().x - _character.getPosition().x) >= areaSize ||
		abs(getPosition().y - _character.getPosition().y) >= areaSize);
}

void Enemy::update(sf::Time delta)
{
	_sprite.update(delta);
}

auto Enemy::findCharacter() -> int
{
	if (getPosition().x == _character.getPosition().x)
		return 0;
	if (getPosition().x > _character.getPosition().x)
		return 1;
	if (getPosition().x < _character.getPosition().x)
		return -1;
}



