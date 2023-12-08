
#include "Background.h"
#include "Configuration.h"
#include <iostream>

Background::Background(sf::RenderWindow& window) : _window(window)
{
	std::pair<float, sf::Sprite*> temp;

}

auto Background::draw() -> void
{
	for (auto iter = _layers.begin(); iter != _layers.end(); ++iter)
	{
		auto currentTarget = _view.getCenter();
		auto parallaxCoefficient = iter->first;
		auto background = iter->second;
		sf::View v;
		v.setCenter(parallaxCoefficient * currentTarget);
		_window.setView(v);
		_window.draw(*background);
	}
	_window.setView(_view);
}

auto Background::update(sf::Time delta) -> void
{
	_view.move(_scrollSpeed * delta.asSeconds(), 0.0f);
}
