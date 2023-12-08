
#ifndef GAMETEST_SRC_ENGINE_ENEMY_H_
#define GAMETEST_SRC_ENGINE_ENEMY_H_

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(const Enemy&) = delete;
	auto operator=(const Enemy&) -> Enemy& = delete;

	explicit Enemy(Entity& character);
public:
	auto isCollide(const Entity& other) const -> bool override;
	virtual auto update(sf::Time delta) -> void override;
	virtual auto isTriggerCharacter(float areaSize) -> bool;
	virtual auto findCharacter() -> int;
private:

	Entity& _character;
};

#endif //GAMETEST_SRC_ENGINE_ENEMY_H_
