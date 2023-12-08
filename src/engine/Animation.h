
#ifndef GAMETEST_SRC_ENGINE_ANIMATION_H_
#define GAMETEST_SRC_ENGINE_ANIMATION_H_

#include <SFML/Graphics.hpp>

#include <vector>

class Animation
{
public:
	Animation(sf::Texture* texture = nullptr);
	~Animation();
public:
	auto setTexture(sf::Texture* texture) -> void;
	auto getTexture() const -> sf::Texture*;

	auto addFrame(const sf::IntRect& rect) -> Animation&;
	auto addFrameLine(int number_x, int number_y, int line) -> Animation&;
	auto addFrameLineFromBack(int number_x, int number_y, int line) -> Animation&;
	auto addFrameColumn(int number_x, int number_y, int column) -> Animation&;

	auto size() const -> std::size_t;
	auto getRect(std::size_t index) const -> const sf::IntRect&;
private:
	friend class AnimatedSprite;
	std::vector<sf::IntRect> _frames;
	sf::Texture* _texture;
};

#endif //GAMETEST_SRC_ENGINE_ANIMATION_H_
