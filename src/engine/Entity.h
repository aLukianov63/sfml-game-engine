
#ifndef GAMETEST_SRC_ENGINE_ENTITY_H_
#define GAMETEST_SRC_ENGINE_ENTITY_H_

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class Entity : public sf::Drawable
{
public:
	Entity(const Entity&) = delete;
	auto operator=(const Entity&) -> Entity& = delete;

	explicit Entity() = default;
	virtual ~Entity() { }
public:
	virtual auto isAlive() const -> bool;

	auto getPosition() const -> const sf::Vector2f&;
	template <typename ... Args>
	auto setPosition(Args&& ... args) -> void
	{
		_sprite.setPosition(std::forward<Args>(args)...);
	}
	virtual auto isCollide(const Entity& other) const -> bool = 0;

	virtual auto update(sf::Time delta) -> void = 0;
	virtual auto onDestroy() -> void;
protected:
	AnimatedSprite _sprite;
	sf::Vector2f _velocity;

	bool _alive{};
private:
	auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};

#endif //GAMETEST_SRC_ENGINE_ENTITY_H_
