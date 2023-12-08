
#ifndef GAMETEST_SRC_ENGINE_LEVELMANAGER_H_
#define GAMETEST_SRC_ENGINE_LEVELMANAGER_H_

#include <SFML/Graphics.hpp>

#include <list>

class Entity;
class LevelManager : public sf::Drawable
{
public:
	LevelManager(const LevelManager&) = delete;
	auto operator=(const LevelManager&) = delete;

	LevelManager(const int& x, const int& y);
	~LevelManager();
public:
	auto update(sf::Time deltaTime) -> void;

	auto add(Entity* entity) -> void;
	auto clear() -> void;
	auto isCollide(const Entity& other) -> bool;

	auto size() -> int;
	auto getX() const -> int;
	auto getY() const -> int;

	auto getEntities() const -> const std::list<Entity*>;
private:
	std::list<Entity*> _entities;
	std::list<Entity*> _entities_tmp;

	const int _x;
	const int _y;

	virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};

#endif //GAMETEST_SRC_ENGINE_LEVELMANAGER_H_
