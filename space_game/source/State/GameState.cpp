#include "GameState.h"
#include "..\Scene\SpriteNode.h"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>


GameState::GameState(StateStack* p_stateStack, Context p_context)
	:
	State(p_stateStack, p_context)
{
	sf::Sprite sprite;
	sprite.setTexture(*p_context.textures.get("background"));

	SceneNode::Ptr backgroundSprite(new SpriteNode(sprite));
	baseNode.addChild(std::move(backgroundSprite));
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
	getContext().window.draw(baseNode, sf::RenderStates());
	return false;
}