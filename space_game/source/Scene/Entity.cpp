#include "Entity.h"

#include <iostream>

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::updateSelf(sf::Time const& p_deltaTime)
{
	rotate(1);
}

void Entity::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape s(30);
	s.setFillColor(sf::Color::Blue);
	target.draw(s, states);
}