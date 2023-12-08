
#ifndef GAMETEST_SRC_GAME_H_
#define GAMETEST_SRC_GAME_H_

#include "engine/LevelManager.h"
#include "engine/Background.h"
#include "engine/Camera.h"

class Game
{
public:
	Game(const Game &) = delete;
	Game &operator=(const Game &) = delete;

	explicit Game();
public:
	void run(float fps = 60);
private:
	void processEvents();
	void update(sf::Time delta);
	void render();

	sf::RenderWindow _window;
	LevelManager _level;
	Camera _camera;
};

#endif //GAMETEST_SRC_GAME_H_
