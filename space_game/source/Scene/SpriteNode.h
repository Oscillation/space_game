#pragma once

#include "SceneNode.h"

#include <SFML\Graphics\Sprite.hpp>

class SpriteNode : public SceneNode
{
public:
	SpriteNode(sf::Sprite p_sprite);
	virtual ~SpriteNode();

private:
	virtual void updateSelf(sf::Time const& p_deltaTime);
	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite m_sprite;
};