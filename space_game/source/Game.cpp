#include "Game.h"

Game::Game() : m_window(sf::VideoMode(1280, 720), "Space Game", sf::Style::Close)
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
	
}

void Game::handleEvents()
{
	sf::Event e;
	while (m_window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time & p_deltaTime)
{
	
}

void Game::render()
{
	m_window.clear();

	m_window.display();
}