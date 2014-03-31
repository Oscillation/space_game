#include "LittleShip.h"

LittleShip::LittleShip(sf::Sprite& p_sprite)
	:
	Entity(p_sprite)
{
	m_velocity = 1;
	setPosition(32, 16);
	setOrigin(128, 64);
}

LittleShip::~LittleShip(){
}

void LittleShip::updateSelf(sf::Time const& p_deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (m_velocity < m_terminal_velocity)
		{
			m_velocity += 0.1f;
		}
	}else
	{
		if (m_velocity > 1)
		{
			m_velocity -= 0.1f;
		}
	}

	/*rotate(m_velocity);
	m_sprite.rotate(-m_velocity);*/
}