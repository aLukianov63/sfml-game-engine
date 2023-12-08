
#include "Camera.h"

Camera::Camera(sf::RenderWindow& window) : _window(window), _position(std::nullopt),
		_entity(std::nullopt)
{
}

auto Camera::update(sf::Time delta) -> void
{
	if (_entity != std::nullopt || _position != std::nullopt)
	{
		float x_fix = 0;
		float y_fix = 0;

		if (_view.getSize().x > _view.getSize().y)
		{
			x_fix = (_view.getSize().x - _view.getSize().y) / 4;
		}
		if (_view.getSize().y > _view.getSize().x)
		{
			y_fix = (_view.getSize().y - _view.getSize().x) / 4;
		}

		if (_entity != std::nullopt)
		{
			_view.setCenter(_entity.value()->getPosition().x + x_fix, _entity.value()->getPosition().y + y_fix);
		}
		else
		{
			_view.setCenter(_position.value());
		}
		_window.setView(_view);
	}
	else
	{
		_window.setView(_window.getDefaultView());
	}
}

