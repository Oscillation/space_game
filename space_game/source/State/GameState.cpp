#include "GameState.h"
#include "..\Scene\Player\BigShip.h"
#include "..\Scene\Player\LittleShip.h"
#include "..\Scene\Enemy\Asteroid.h"

#include "..\Math\GeneralMath.h"

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
<<<<<<< HEAD
	m_view.setCenter(baseNode.getChild("big_ship")->getPosition());
=======
	spawnAsteroids();
>>>>>>> 5b2b8455627f6072e304bf429820abaeba52b9e3
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

		baseNode.addChild(std::move(a));
	}
}