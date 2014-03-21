#include "SpriteNode.h"
#include <SFML\Graphics\RenderTarget.hpp>

SpriteNode::SpriteNode(sf::Sprite p_sprite)
	:
	m_sprite(p_sprite)
{
}

SpriteNode::~SpriteNode()
{
}

void SpriteNode::updateSelf(sf::Time const& p_deltaTime)
{
}

void SpriteNode::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}