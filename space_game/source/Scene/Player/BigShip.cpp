#include "BigShip.h"

BigShip::BigShip(const sf::Sprite & p_sprite) : Entity(p_sprite), m_velocity(0.5, 0){
	setOrigin(128, 64);
	setPosition(0, 360);
}

BigShip::~BigShip(){}

void BigShip::updateSelf(const sf::Time & p_deltaTime){
	move(m_velocity);
}