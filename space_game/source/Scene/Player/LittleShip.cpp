#include "LittleShip.h"

#include <iostream>

LittleShip::LittleShip(sf::Sprite& p_sprite)
	:
	Entity(p_sprite)
{
	setPosition(0, -140);
	setOrigin(32, 16);
	m_velocity = 1;
}

LittleShip::~LittleShip()
{
}

void LittleShip::updateSelf(sf::Time const& p_deltaTime)
{
	std::cout << getWorldPosition().x << " : " << getWorldPosition().y << std::endl;
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	//{
	//	if (m_velocity < m_terminal_velocity)
	//	{
	//		m_velocity += 0.1f;
	//	}
	//}else
	//{
	//	if (m_velocity > 1)
	//	{
	//		m_velocity -= 0.1f;
	//	}
	//}

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//{

	//}

	//rotate(m_velocity);
	////m_sprite.rotate(-m_velocity);
}