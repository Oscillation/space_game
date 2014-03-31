#include "GameState.h"
#include "..\Scene\Player\BigShip.h"
#include "..\Scene\Player\LittleShip.h"
#include "..\Scene\Enemy\Asteroid.h"
#include "..\Resource Managers\EntityLoader.h"

#include "..\Math\GeneralMath.h"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>


GameState::GameState(StateStack* p_stateStack, Context p_context)
	:
	State(p_stateStack, p_context),
	m_world()
{
	EntityLoader entityLoader;
	entityLoader.load(m_world, "assets/entities.dat", getContext().textures);
}

GameState::~GameState()
{
}

bool GameState::update(sf::Time const& p_deltaTime)
{
	m_world.update(p_deltaTime);
	m_view.setCenter(m_world.getNode("big_ship")->getPosition());
	//spawnAsteroids();
	return false;
}

bool GameState::handleEvent(sf::Event const& event)
{
	return false;
}

bool GameState::render() const
{
	getContext().window.setView(m_view);
	getContext().window.draw(m_world, sf::RenderStates());
	return false;
}

void GameState::spawnAsteroids()
{
	if (math::random(0, 100) > 95)
	{
		sf::Sprite asssprite;
		asssprite.setTexture(*getContext().textures.get("asteroid"));
		asssprite.setOrigin(64, 64);
		SceneNode::Ptr a(new Asteroid(asssprite, sf::Vector2f(math::random(-10, 10), math::random(-10, 10)), math::random(-10, 10)));
		
		float x, y;
		x  = (math::random(1, 10) > 5) ? -64 : 1280 + 64;
		y = math::random(-64, 720+64);

		a.get()->setPosition(x, y);

		m_world.addNode(std::move(a));
	}
}