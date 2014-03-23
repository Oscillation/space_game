#pragma once

#include <SFML\System\Time.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>

#include "State\StateStack.h"
#include "Scene\SceneNode.h"
#include "Scene\Entity.h"
#include "Resource Managers\ResourceManager.h"
#include "Resource Managers\EntityLoader.h"

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

private:

	sf::RenderWindow m_window;
	StateStack m_stateStack;

	ResourceManager<sf::Texture> m_textureManager;
};