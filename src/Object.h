
#ifndef GAMETEST_SRC_GUI_OBJECT_H_
#define GAMETEST_SRC_GUI_OBJECT_H_

#include <SFML/Graphics.hpp>
#include "engine//Entity.h"

class Object : public Entity
{
public:
	Object() = default;
	~Object() override { }
public:
	auto isAlive() const -> bool override { return Entity::isAlive(); }
	auto isCollide(const Entity& other) const -> bool override { return false; }
	auto update(sf::Time delta) -> void override { }
	auto onDestroy() -> void override { Entity::onDestroy(); }
	auto setScale(sf::Vector2f vector) -> void { _sprite.setScale(vector); }
	auto getScale() const -> sf::Vector2f { _sprite.getScale(); }
	auto setTexture(sf::Texture& texture) { _sprite.setTexture(texture); }
};

#endif //GAMETEST_SRC_GUI_OBJECT_H_
