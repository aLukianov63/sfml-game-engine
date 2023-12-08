
#ifndef GAMETEST_SRC_ACTION_H_
#define GAMETEST_SRC_ACTION_H_

#include <SFML/Graphics.hpp>

class Action
{
public:
	enum ActionType
	{
		RealTime = 1,
		Pressed = 1 << 1,
		Released = 1 << 2
	};
	Action(const Action& other);
	auto operator=(const Action& other) -> Action&;

	explicit Action(const sf::Keyboard::Key& key, int type = RealTime | Pressed);
	explicit Action(const sf::Mouse::Button& button, int type = RealTime | Pressed);
	explicit Action(const int& id, const int& button, int type = RealTime | Pressed);
public:
	auto isPressed() const -> bool ;

	auto operator==(const Action& other) const -> bool;
	auto operator==(const sf::Event& event) const  -> bool;
private:
	friend class ActionHandler;
	sf::Event _event{};
	int _type;
};

#endif //GAMETEST_SRC_ACTION_H_
