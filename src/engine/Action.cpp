
#include "Action.h"

Action::Action(const Action& other) : _type(other._type)
{
	std::memcpy(&_event, &other._event, sizeof(sf::Event));
}

auto Action::operator=(const Action& other) -> Action&
{
	if (this != &other)
	{
		std::memcpy(&_event, &other._event, sizeof(sf::Event));
		_type = other._type;
	}
	return *this;
}

Action::Action(const sf::Keyboard::Key& key, int type) : _type(type)
{
	_event.type = sf::Event::EventType::KeyPressed;
	_event.key.code = key;
}

Action::Action(const sf::Mouse::Button& button, int type) : _type(type)
{
	_event.type = sf::Event::EventType::MouseButtonPressed;
	_event.mouseButton.button = button;
}

Action::Action(const int& id, const int& button, int type) : _type(type)
{
	_event.type = sf::Event::EventType::JoystickButtonPressed;
	_event.joystickButton.joystickId = id;
	_event.joystickButton.button = button;
}

auto Action::isPressed() const -> bool
{
	bool res = false;

	if (_event.type == sf::Event::EventType::KeyPressed)
	{
		if (_type & Pressed) res = sf::Keyboard::isKeyPressed(_event.key.code);
	}
	else if (_event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (_type & Pressed) res = sf::Mouse::isButtonPressed(_event.mouseButton.button);
	}
	else if (_event.type == sf::Event::EventType::JoystickButtonPressed)
	{
		if (_type & Pressed) res = sf::Joystick::isButtonPressed(_event.joystickButton.joystickId,
			_event.joystickButton.button);
	}
	return res;
}

auto Action::operator==(const sf::Event& event) const -> bool
{
	bool res = false;

	switch (event.type)
	{
	case sf::Event::EventType::KeyPressed:
		if (_type & Pressed && _event.type == sf::Event::EventType::KeyPressed)
			res = event.key.code == _event.key.code;
		break;
	case sf::Event::EventType::KeyReleased:
		if (_type & Released && _event.type == sf::Event::EventType::KeyPressed)
			res = event.key.code == _event.key.code;
		break;
	case sf::Event::EventType::MouseButtonPressed:
		if (_type & Pressed && _event.type == sf::Event::EventType::MouseButtonPressed)
			res = event.mouseButton.button == _event.mouseButton.button;
		break;
	case sf::Event::EventType::MouseButtonReleased:
		if (_type & Released && _event.type == sf::Event::EventType::MouseButtonPressed)
			res = event.mouseButton.button == _event.mouseButton.button;
		break;
	case sf::Event::EventType::JoystickButtonPressed:
		if (_type & Pressed && _event.type == sf::Event::EventType::JoystickButtonPressed)
			res = event.joystickButton.button == _event.mouseButton.button;
		break;
	case sf::Event::EventType::JoystickButtonReleased:
		if (_type & Pressed && _event.type == sf::Event::EventType::JoystickButtonPressed)
			res = event.joystickButton.button == _event.mouseButton.button;
		break;
	default:
		break;
	}
	return res;
}

auto Action::operator==(const Action& other) const -> bool
{
	return _type == other._type || other == _event;
}

