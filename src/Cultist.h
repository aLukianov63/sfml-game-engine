
#ifndef GAMETEST_SRC_CULTIST_H_
#define GAMETEST_SRC_CULTIST_H_

#include "engine/Enemy.h"
#include "engine/Configuration.h"

class Cultist : public Enemy
{
public:
	explicit Cultist(Entity* entity);
public:
	auto update(sf::Time delta) -> void override;
	auto getScale() const -> sf::Vector2f { _sprite.getScale(); }
	auto setScale(sf::Vector2f vector) -> void { _sprite.setScale(vector); }
private:
	Animation _walkLeft{&Configuration::textures.get(Configuration::Textures::LeftCultistWalk)};
	Animation _walkRight{&Configuration::textures.get(Configuration::Textures::RightCultistWalk)};

	float _patrolPos;
};

#endif //GAMETEST_SRC_CULTIST_H_