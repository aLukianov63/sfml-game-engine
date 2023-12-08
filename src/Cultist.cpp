
#include "Cultist.h"

Cultist::Cultist(Entity* entity) : Enemy(*entity)
{
	_walkLeft.addFrameLine(6, 1, 0);
	_walkRight.addFrameLineFromBack(6, 1, 0);

	_sprite = AnimatedSprite(nullptr, AnimatedSprite::Playing, sf::seconds(0.1), false);

	_patrolPos = _sprite.getPosition().x;
}

void Cultist::update(sf::Time delta)
{
	Enemy::update(delta);
}

