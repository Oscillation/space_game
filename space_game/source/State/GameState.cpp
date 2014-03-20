#include "GameState.h"
#include <SFML\Graphics\RenderWindow.hpp>

GameState::GameState(StateStack* p_stateStack, Context p_context)
	:
	State(p_stateStack, p_context)
{
	SceneNode::Ptr a(new Entity());
	a.get()->setPosition(300, 300);
	SceneNode::Ptr b(new Entity());
	b.get()->setPosition(40, 40);
	a.get()->addChild(std::move(b));
	baseNode.addChild(std::move(a));
	baseNode.setPosition(0, 0);
}

GameState::~GameState()
{
}

bool GameState::update(sf::Time const& p_deltaTime)
{
	baseNode.update(p_deltaTime);
	return false;
}

bool GameState::handleEvent(sf::Event const& event)
{
	return false;
}

bool GameState::render() const
{
	getContext().window->draw(baseNode, sf::RenderStates());
	return false;
}
