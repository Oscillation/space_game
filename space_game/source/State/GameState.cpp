#include "GameState.h"
#include <SFML\Graphics\RenderWindow.hpp>

GameState::GameState(StateStack* p_stateStack, Context p_context)
	:
	State(p_stateStack, p_context)
{

}

GameState::~GameState()
{
}

bool GameState::update(sf::Time const& p_deltaTime)
{
	return false;
}

bool GameState::handleEvent(sf::Event const& event)
{
	return false;
}

bool GameState::render() const
{
	getContext().window->clear(sf::Color::Red);
	return false;
}
