#include "Game.h"
#include "State\GameState.h"

#include <SFML\Graphics\Texture.hpp>

Game::Game() : 
	m_window(sf::VideoMode(1280, 720), "Space Game", sf::Style::Close),
	m_stateStack(m_window, m_textureManager)
{
	run();
}

Game::~Game()
{
	m_window.close();
}

void Game::run()
{
	initialize();

	sf::Clock dt;
	sf::Time lag;
	sf::Time updateTime = sf::seconds(1.f/60.f);

	while (!m_stateStack.isEmpty())
	{
		lag += dt.getElapsedTime();
		dt.restart();

		handleEvents();
		render();
		while (lag >= updateTime)
		{
			update(updateTime);
			lag -= updateTime;
		}
	}
}

void Game::initialize()
{
	m_textureManager.load("background", "assets/graphics/world/background.png");

	m_stateStack.registerState<GameState>(States::Game);
	m_stateStack.push(States::Game);
	m_stateStack.applyPendingChanges();
}

void Game::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			m_stateStack.clear();
		}
		m_stateStack.handleEvent(event);
	}
}

void Game::update(sf::Time & p_deltaTime)
{
	m_stateStack.update(p_deltaTime);
}

void Game::render()
{
	m_window.clear();
	m_stateStack.render();
	m_window.display();
}