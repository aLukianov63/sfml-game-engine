
#include "Configuration.h"
#include "../Object.h"
#include "../Player.h"
#include "../Cultist.h"

ResourceManager<sf::Texture, int> Configuration::textures;
ResourceManager<sf::Music, int> Configuration::sounds;
Player* Configuration::player;
Object* Configuration::background;
Object* Configuration::background2;
Object* Configuration::background3;
Object* Configuration::ground;
Object* Configuration::ground2;
Object* Configuration::ground3;
Cultist* Configuration::cultist;

auto Configuration::init() -> void
{
	initTextures();

	player = new Player();
	player->setPosition(0, 1335);

	background = new Object();
	background2 = new Object();
	background3 = new Object();
	ground = new Object();
	ground2 = new Object();
	ground3 = new Object();
	background->setTexture(textures.get(Textures::Background));
	background->setPosition(0, 1100);
	background->setScale(sf::Vector2f(1.4, 1.9));
	background2->setTexture(textures.get(Textures::Background));
	background2->setPosition(448, 1100);
	background2->setScale(sf::Vector2f(1.4, 1.9));
	background3->setTexture(textures.get(Textures::Background));
	background3->setPosition(-448, 1100);
	background3->setScale(sf::Vector2f(1.4, 1.9));

	ground->setTexture(textures.get(Textures::LevelGround));
	ground2->setTexture(textures.get(Textures::LevelGround));
	ground3->setTexture(textures.get(Textures::LevelGround));

	ground->setPosition(0, 1415);
	ground2->setPosition(448, 1415);
	ground3->setPosition(-448, 1415);

	cultist = new Cultist(player);
	cultist->setScale(sf::Vector2f(0.36, 0.36));
	cultist->setPosition(400, 1350);

}

auto Configuration::initTextures() -> void
{
	textures.load(Textures::RightPlayerRun, "../resources/RightPlayerRun.png");
	textures.load(Textures::RightPlayerAttack_1, "../resources/RightPlayerAttack_1.png");
	textures.load(Textures::RightPlayerAttack_2, "../resources/RightPlayerAttack_2.png");
	textures.load(Textures::RightPlayerStay, "../resources/RightPlayerStay.png");
	textures.load(Textures::RightPlayerRoll, "../resources/RightPlayerRoll.png");
	textures.load(Textures::LeftPlayerRun, "../resources/LeftPlayerRun.png");
	textures.load(Textures::LeftPlayerAttack_1, "../resources/LeftPlayerAttack_1.png");
	textures.load(Textures::LeftPlayerAttack_2, "../resources/LeftPlayerAttack_2.png");
	textures.load(Textures::LeftPlayerStay, "../resources/LeftPlayerStay.png");
	textures.load(Textures::LeftPlayerRoll, "../resources/LeftPlayerRoll.png");
	textures.load(Textures::Background, "../resources/background/Background.png");
	textures.load(Textures::LevelGround, "../resources/LevelGround.png");
	textures.load(Textures::RightCultistWalk, "../resources/RightCultistRun.png");
	textures.load(Textures::LeftCultistWalk, "../resources/LeftCultistRun.png");
}
