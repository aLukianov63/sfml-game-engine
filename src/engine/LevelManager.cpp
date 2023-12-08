
#include <iostream>
#include "LevelManager.h"
#include "Entity.h"

LevelManager::LevelManager(const int& x, const int& y) : _x(x), _y(y) { }

auto LevelManager::update(sf::Time deltaTime) -> void
{
	if(_entities_tmp.size() > 0) _entities.splice(_entities.end(), _entities_tmp);

	for (Entity* pEntity : _entities)
	{
		Entity& entity = *pEntity;
		entity.update(deltaTime);
	}
}

auto LevelManager::add(Entity* entity) -> void
{
	_entities_tmp.push_back(entity);
}

auto LevelManager::clear() -> void
{
	for (Entity* entity : _entities)
	{
		delete entity;
	}
	_entities.clear();

	for (Entity* entity : _entities_tmp)
	{
		delete entity;
	}
	_entities.clear();
}

auto LevelManager::size() -> int
{
	return _entities.size() + _entities_tmp.size();
}

auto LevelManager::getX() const -> int
{
	return _x;
}

auto LevelManager::getY() const -> int
{
	return _y;
}

auto LevelManager::getEntities() const -> const std::list<Entity*>
{
	return _entities;
}

auto LevelManager::isCollide(const Entity& other) -> bool
{
	for(Entity* entity : _entities)
	{
		if (other.isCollide(*entity)) return true;
	}
	return false;
}

LevelManager::~LevelManager()
{
	clear();
}

auto LevelManager::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
	for (Entity* entity : _entities)
	{
		target.draw(*entity, states);
	}
}
