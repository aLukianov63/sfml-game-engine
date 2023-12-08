
#include "ActionHandler.h"

auto ActionHandler::processEvent(const sf::Event& event) const -> bool
{
	bool res = false;

	for (auto& action : _eventsPoll)
	{
		if (action.first == event)
		{
			action.second(event);
			res = true;
			break;
		}
	}
	return  res;
}

auto ActionHandler::processEvents() const -> void
{
	for (auto& action : _eventsRealTime)
	{
		if (action.first.isPressed()) action.second(action.first._event);
	}
}

void ActionHandler::bind(const Action& action, const ActionHandler::Function& callback)
{
	if (action._type & Action::ActionType::RealTime)
	{
		_eventsRealTime.emplace_back(action, callback);
	}
	else
	{
		_eventsPoll.emplace_back(action, callback);
	}
}

void ActionHandler::unbind(const Action& action)
{
	auto remove_func = [&action] (const std::pair<Action, Function>& pair) -> bool
	{
		return pair.first == action;
	};

	if (action._type & Action::ActionType::RealTime)
	{
		_eventsRealTime.remove_if(remove_func);
	}
	else
	{
		_eventsPoll.remove_if(remove_func);
	}
}
