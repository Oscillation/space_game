#include "Game.h"
#include "State\GameState.h"

Game::Game() : 
	m_window(sf::VideoMode(1280, 720), "Space Game", sf::Style::Close),
	m_stateStack(&m_window)
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

	while (m_window.isOpen())
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
	m_stateStack.registerState<GameState>(States::Game);
	m_stateStack.push(States::Game);
}

void Game::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
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