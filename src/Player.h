
#ifndef GAMETEST_SRC_ENGINE_PLAYER_H_
#define GAMETEST_SRC_ENGINE_PLAYER_H_

#include "engine/Entity.h"
#include "engine/ActionHandler.h"
#include "engine/Configuration.h"
#include "engine/Animation.h"
#include "engine/AnimatedSprite.h"

class Player : public Entity, public ActionHandler
{
public:
	Player(const Player&) = delete;
	auto operator=(const Player&) = delete;

	explicit Player();
public:
	auto processEvents() -> void;
	virtual auto isCollide(const Entity& other) const -> bool override;

	auto update(sf::Time delta) -> void override;
	auto onDestroy() -> void override;
private:
	Animation _walkRight{ &Configuration::textures.get(Configuration::Textures::RightPlayerRun) };
	Animation _attackRight_1{ &Configuration::textures.get(Configuration::Textures::RightPlayerAttack_1) };
	Animation _stayRight{&Configuration::textures.get(Configuration::Textures::RightPlayerStay) };
	Animation _attackRight_2{ &Configuration::textures.get(Configuration::Textures::RightPlayerAttack_2) };
	Animation _rollRight{ &Configuration::textures.get(Configuration::Textures::RightPlayerRoll) };
	Animation _walkLeft{ &Configuration::textures.get(Configuration::Textures::LeftPlayerRun) };
	Animation _attackLeft_1{ &Configuration::textures.get(Configuration::Textures::LeftPlayerAttack_1) };
	Animation _stayLeft{&Configuration::textures.get(Configuration::Textures::LeftPlayerStay) };
	Animation _attackLeft_2{ &Configuration::textures.get(Configuration::Textures::LeftPlayerAttack_2) };
	Animation _rollLeft{ &Configuration::textures.get(Configuration::Textures::LeftPlayerRoll) };

	bool _currentRight{true};
	bool _onWalk;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //GAMETEST_SRC_ENGINE_PLAYER_H_
