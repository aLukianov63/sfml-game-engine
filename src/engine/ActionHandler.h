

#ifndef GAMETEST_SRC_ENGINE_ACTIONHANDLER_H_
#define GAMETEST_SRC_ENGINE_ACTIONHANDLER_H_

#include <SFML/Graphics.hpp>

#include "Action.h"

#include <list>
#include <functional>

class ActionHandler
{
public:
	using Function = std::function<void(const sf::Event&)>;

	explicit ActionHandler() = default;
public:
	auto processEvent(const sf::Event& event) const -> bool;
	auto processEvents() const -> void;


	void bind(const Action& action, const Function& callback);
	void unbind(const Action& action);
private:
	std::list<std::pair<Action, Function>> _eventsRealTime;
	std::list<std::pair<Action, Function>> _eventsPoll;
};

#endif //GAMETEST_SRC_ENGINE_ACTIONHANDLER_H_
