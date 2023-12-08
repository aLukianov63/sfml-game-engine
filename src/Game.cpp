
#include "Game.h"
#include "gui/Gui.h"
#include "Player.h"
#include "Object.h"
#include "Cultist.h"

Game::Game() : _window(sf::VideoMode(2560, 1440), "Game"), _level(2560, 1440), _camera(_window)
{
	_camera.pinEntity(Configuration::player);
	_camera.setSize(sf::Vector2f(650, 450));

	ImGui::SFML::Init(_window);
	_level.add(Configuration::background);
	_level.add(Configuration::background2);
	_level.add(Configuration::background3);
	_level.add(Configuration::ground);
	_level.add(Configuration::ground2);
	_level.add(Configuration::ground3);
	_level.add(Configuration::player);
	_level.add(Configuration::cultist);
}

void Game::run(float fps)
{
	sf::Clock clock;
	sf::Time lastStep;
	sf::Time fixedStep = sf::seconds(1.f / fps);

	while (_window.isOpen())
	{
		gui.setFps(1.f / (fixedStep.asSeconds() - lastStep.asSeconds()));

		processEvents();
		lastStep = clock.restart();
		while (lastStep > fixedStep)
		{
			lastStep -= fixedStep;
			update(fixedStep);
		}
		update(lastStep);

		ImGui::SFML::Update(_window, lastStep);
		gui.init();

		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(_window, event);
		switch (event.type)
		{
		case sf::Event::Closed:
			_window.close();
			ImGui::SFML::Shutdown(_window);
			break;
		default:
			break;
		}
	}
	Configuration::player->processEvents();
}

void Game::update(sf::Time delta)
{
	_level.update(delta);

	_camera.update(delta);
}

void Game::render()
{
	_window.clear();
	_window.draw(_level);
	ImGui::SFML::Render(_window);
	_window.display();
}
