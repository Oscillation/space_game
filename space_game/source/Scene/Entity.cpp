#include "Entity.h"

#include <iostream>

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

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
	sf::RectangleShape box;
	sf::FloatRect rect = getBoundingRect();	
	box.setSize(sf::Vector2f(rect.width, rect.height));
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Red);
	box.setOutlineThickness(2);
	box.setPosition(sf::Vector2f(rect.left, rect.top));
	target.draw(box);
}

sf::FloatRect Entity::getBoundingRect() const
{
	return getWorldTransform().transformRect(m_sprite.getGlobalBounds());
}