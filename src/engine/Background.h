
#ifndef GAMETEST_SRC_ENGINE_BACKGROUND_H_
#define GAMETEST_SRC_ENGINE_BACKGROUND_H_

#include "SFML/Graphics.hpp"

class Background
{
public:
	Background() = delete;
	explicit Background(sf::RenderWindow& window);
public:

	auto draw() -> void;
	auto update(sf::Time delta) -> void;
private:
	sf::RenderWindow& _window;
	sf::View _view;

	float _scrollSpeed;

	std::vector<std::pair<float, sf::Sprite*>> _layers;
};

#endif //GAMETEST_SRC_ENGINE_BACKGROUND_H_
