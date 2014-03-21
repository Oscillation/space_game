#include "BigShip.h"

void BigShip::updateSelf(const sf::Time & p_deltaTime){
	move(m_velocity);
}