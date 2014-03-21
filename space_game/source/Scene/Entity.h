#pragma once

#include "SceneNode.h"

#include <SFML\Graphics\Sprite.hpp>

class Entity : public SceneNode
{
public:
	Entity();
	Entity(const sf::Sprite & p_sprite);
	virtual ~Entity();

	virtual void updateSelf(sf::Time const& p_deltaTime) = 0;

	void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite m_sprite;
};