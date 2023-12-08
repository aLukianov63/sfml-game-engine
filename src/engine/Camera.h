
#ifndef GAMETEST_SRC_ENGINE_CAMERA_H_
#define GAMETEST_SRC_ENGINE_CAMERA_H_

#include "SFML/Graphics.hpp"
#include "ActionHandler.h"
#include "Entity.h"
#include <optional>

class Camera
{
public:
	Camera() = delete;
	explicit Camera(sf::RenderWindow& window);
public:
	auto pinEntity(Entity* entity) { _entity = entity; }
	auto unpinEntity() -> void {_entity = std::nullopt; }
	auto setSize(sf::Vector2f size) -> void { _view.setSize(size); }

	auto update(sf::Time delta) -> void;
private:
	sf::RenderWindow& _window;
	sf::View _view;

	std::optional<sf::Vector2f> _position;
	std::optional<Entity*> _entity;
};

#endif //GAMETEST_SRC_ENGINE_CAMERA_H_
