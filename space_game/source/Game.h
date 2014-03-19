#pragma once

#include <SFML\System\Time.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>

#include "State\StateStack.h"

class Game
{
public:
	Game();
	~Game();

private:
	void run();
	void initialize();

	void update(sf::Time & p_deltaTime);
	void render();

	void handleEvents();

	sf::RenderWindow m_window;
	StateStack m_stateStack;
};