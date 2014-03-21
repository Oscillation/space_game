#include "Asteroid.h"

Asteroid::Asteroid(sf::Sprite& p_sprite, sf::Vector2f p_velocity, float p_rotationSpeed)
	:
	Entity(p_sprite),
	m_velocity(p_velocity),
	m_rotationSpeed(p_rotationSpeed)
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::updateSelf(sf::Time const& p_deltaTime)
{
	move(m_velocity);
	rotate(m_rotationSpeed);
}