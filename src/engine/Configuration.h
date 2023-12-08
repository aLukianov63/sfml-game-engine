
#ifndef GAMETEST_SRC_ENGINE_CONFIGURATION_H_
#define GAMETEST_SRC_ENGINE_CONFIGURATION_H_

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

class Player;
class Object;
class Enemy;
class Cultist;
class Configuration
{
public:
	enum Textures
	{
		RightPlayerRun = 1,
		RightPlayerAttack_1,
		RightPlayerAttack_2,
		RightPlayerRoll,
		RightPlayerStay,
		LeftPlayerRun,
		LeftPlayerAttack_1,
		LeftPlayerAttack_2,
		LeftPlayerRoll,
		LeftPlayerStay,
		RightCultistWalk,
		LeftCultistWalk,
		Background,
		LevelGround
	};
	enum Sounds
	{
		PlayerMove = 1
	};

	Configuration() = delete;
	Configuration(const Configuration&) = delete;
	auto operator=(const Configuration&) = delete;

	static Player* player;
	static Object* background;
	static Object* background2;
	static Object* background3;
	static Object* ground;
	static Object* ground2;
	static Object* ground3;
	static Cultist* cultist;
public:
	static ResourceManager<sf::Texture, int> textures;
	static ResourceManager<sf::Music, int> sounds;

	static auto init() -> void;
private:
	static auto initTextures() -> void;
};

#endif //GAMETEST_SRC_ENGINE_CONFIGURATION_H_
