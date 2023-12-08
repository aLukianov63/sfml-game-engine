
#include "Player.h"

Player::Player() : Entity(), ActionHandler()
{
	_walkRight.addFrameLine(10, 1, 0);
	_attackRight_1.addFrameLine(6, 1, 0);
	_stayRight.addFrameLine(10, 1, 0);
	_attackRight_2.addFrameLine(4, 1, 0);
	_rollRight.addFrameLine(12, 1, 0);
	_walkLeft.addFrameLineFromBack(10, 1, 0);
	_attackLeft_1.addFrameLineFromBack(6, 1, 0);
	_stayLeft.addFrameLineFromBack(10, 1, 0);
	_attackLeft_2.addFrameLineFromBack(4, 1, 0);
	_rollLeft.addFrameLineFromBack(12, 1, 0);

	_sprite = AnimatedSprite(nullptr, AnimatedSprite::Playing, sf::seconds(0.06), false);

	bind(Action(sf::Keyboard::A), [this] (const sf::Event&)
	{
		_currentRight = false;
		_sprite.setAnimation(&_walkLeft);
		_sprite.play();
		_onWalk = true;
	});
	bind(Action(sf::Keyboard::D), [this] (const sf::Event&)
	{
	  	_currentRight = true;
	  	_sprite.setAnimation(&_walkRight);
	  	_sprite.play();
	  	_onWalk = true;
	});
}

auto Player::processEvents() -> void
{
	_onWalk = false;
	ActionHandler::processEvents();
}

void Player::update(sf::Time delta)
{
	if (_currentRight)
	{
		if (_onWalk)
		{
			_sprite.move(120 * delta.asSeconds(), 0);
		}
		else
		{
			_sprite.setAnimation(&_stayRight);
			_sprite.play();
		}
	}
	else
	{
		if (_onWalk)
		{
			_sprite.move(-120 * delta.asSeconds(), 0);
		}
		else
		{
			_sprite.setAnimation(&_stayLeft);
			_sprite.play();
		}
	}

	_sprite.update(delta);
}

void Player::onDestroy()
{
	Entity::onDestroy();
}

auto Player::isCollide(const Entity& other) const -> bool
{
	return false;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

