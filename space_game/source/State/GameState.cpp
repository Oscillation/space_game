#include "GameState.h"
#include "..\Scene\Player\BigShip.h"
#include "..\Scene\Player\LittleShip.h"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>


GameState::GameState(StateStack* p_stateStack, Context p_context)
	:
	State(p_stateStack, p_context)
{
	sf::Sprite sprite;

	sprite.setTexture(*p_context.textures.get("background"));
	sprite.setTextureRect(sf::Rect<int>(0, 0, p_context.textures.get("background")->getSize().x, p_context.textures.get("background")->getSize().y));
	SceneNode::Ptr backgroundSprite(new BackgroundNode(sprite));
	backgroundSprite->setTag("background_sprite");
	baseNode.addChild(std::move(backgroundSprite));

	sprite.setTexture(*p_context.textures.get("big_ship"));
	sprite.setTextureRect(sf::Rect<int>(0, 0, p_context.textures.get("big_ship")->getSize().x, p_context.textures.get("big_ship")->getSize().y));
	SceneNode::Ptr bigShip(new BigShip(sprite));
	bigShip->setTag("big_ship");
	baseNode.addChild(std::move(bigShip));
}

GameState::~GameState()
{
}

bool GameState::update(sf::Time const& p_deltaTime)
{
	baseNode.update(p_deltaTime);
	m_view.setCenter(baseNode.getChild("big_ship")->getPosition());
	return false;
}

bool GameState::handleEvent(sf::Event const& event)
{
	return false;
}

bool GameState::render() const
{
	getContext().window.setView(m_view);
	getContext().window.draw(baseNode, sf::RenderStates());
	return false;
}