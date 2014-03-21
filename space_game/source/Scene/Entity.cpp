#include "Entity.h"

#include <iostream>

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>

Entity::Entity()
{
}

Entity::Entity(const sf::Sprite & p_sprite) : m_sprite(p_sprite)
{
}

Entity::~Entity()
{
}

void Entity::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}